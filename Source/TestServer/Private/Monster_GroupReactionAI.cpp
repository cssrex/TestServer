// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster_GroupReactionAI.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Monster_GroupReaction.h"

int AMonster_GroupReactionAI::DetectedCount[MAX_GROUP_COUNT] = { 0, };
AActor* AMonster_GroupReactionAI::Target = nullptr;


void AMonster_GroupReactionAI::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (AMonster_GroupReaction* GroupMonster = Cast<AMonster_GroupReaction>(InPawn))
	{
		Group = GroupMonster->GetGroupNumber();
		if (Group >= MAX_GROUP_COUNT) Group = MAX_GROUP_COUNT - 1;
		else if (Group < 0) Group = 0;
	}
}

void AMonster_GroupReactionAI::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (DetectedCount[Group]) {
		if (Target) {
			MoveToActor(Target);
		}
	}
	else {
		StopMovement();
	}
	
}

void AMonster_GroupReactionAI::PlayerInRange(AActor* Actor)
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("override : Player In Range (%d)"), Group));
	Target = Actor;
	DetectedCount[Group]++;
}

void AMonster_GroupReactionAI::PlayerOutRange(AActor* Actor)
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("override : Player Out Range (%d)"), Group));
	DetectedCount[Group]--;
}

void AMonster_GroupReactionAI::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	for (int i = 0; i < MAX_GROUP_COUNT; i++) {
		DetectedCount[i] = 0;
	}
	Target = nullptr;
}
