// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicMonsterAI.h"
#include "Engine/Engine.h"
#include "TestServer/TestServerCharacter.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Kismet/GameplayStatics.h"

ABasicMonsterAI::ABasicMonsterAI()
{
	PrimaryActorTick.bCanEverTick = true;

	//-----------���� ����-----------
	AIPerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComp"));


	// �ð� ���� ����
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 1000.0f;											// ���� �Ÿ�
	SightConfig->LoseSightRadius = 1200.0f;										// ��ġ�� �Ÿ�
	SightConfig->PeripheralVisionAngleDegrees = 360.0f;							// �þ߰�
	SightConfig->SetMaxAge(5.0f);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	// �ð� ���� ����
	AIPerceptionComp->ConfigureSense(*SightConfig);
	AIPerceptionComp->SetDominantSense(SightConfig->GetSenseImplementation());

	AIPerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &ABasicMonsterAI::OnTargetDetected);
	//----------------------------
}

void ABasicMonsterAI::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	Monster = Cast<ABasicMonster>(InPawn);
	if (Monster) {
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Success"));

		InitialSetting();
	}
	else {
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Failed"));
	}
}

void ABasicMonsterAI::Tick(float DeltaSeconds)
{

}

void ABasicMonsterAI::PlayerInRange(AActor* Actor)
{
	MoveToActor(Actor);
}

void ABasicMonsterAI::PlayerOutRange(AActor* Actor)
{
	StopMovement();
}

void ABasicMonsterAI::OnTargetDetected(AActor* Actor, FAIStimulus Stimulus)
{
	// ������ Actor�� �÷��̾ �ƴ϶�� return
	if (!(Actor && Actor->IsA(ATestServerCharacter::StaticClass()))) return;


	if (Stimulus.WasSuccessfullySensed())
	{
		// �÷��̾ ���� �ȿ� ������ ��� ����
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Player Detected"));

		PlayerInRange(Actor);
	}
	else
	{
		// �÷��̾ ���� ������ ������ ��� ����
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Player Lose"));

		PlayerOutRange();
	}
}

void ABasicMonsterAI::InitialSetting()
{
	// ������ �ʱ� ������ �ϴ� �κ�
	if (AIPerceptionComp && SightConfig)
	{
		SightConfig->SightRadius = Monster->GetDetectedRange();
		SightConfig->LoseSightRadius = Monster->GetLoseRange();
		AIPerceptionComp->ConfigureSense(*SightConfig);
	}
	SetSpeed(Monster->GetMoveSpeed());
}

void ABasicMonsterAI::SetSpeed(float speed)
{
	if (Monster) {
		Monster->SetMoveSpeed(speed);
	}
}
