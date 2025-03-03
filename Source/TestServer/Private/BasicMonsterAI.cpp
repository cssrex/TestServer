// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicMonsterAI.h"
#include "Engine/Engine.h"
#include "TestServer/TestServerCharacter.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Kismet/GameplayStatics.h"

ABasicMonsterAI::ABasicMonsterAI()
{
	PrimaryActorTick.bCanEverTick = true;

	//-----------감지 관련-----------
	AIPerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComp"));


	// 시각 감지 설정
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 1000.0f;											// 감지 거리
	SightConfig->LoseSightRadius = 1200.0f;										// 놓치는 거리
	SightConfig->PeripheralVisionAngleDegrees = 360.0f;							// 시야각
	SightConfig->SetMaxAge(5.0f);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	// 시각 감지 적용
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
	// 감지된 Actor가 플레이어가 아니라면 return
	if (!(Actor && Actor->IsA(ATestServerCharacter::StaticClass()))) return;


	if (Stimulus.WasSuccessfullySensed())
	{
		// 플레이어가 범위 안에 들어왔을 경우 실행
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Player Detected"));

		PlayerInRange(Actor);
	}
	else
	{
		// 플레이어가 범위 밖으로 나갔을 경우 실행
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Player Lose"));

		PlayerOutRange();
	}
}

void ABasicMonsterAI::InitialSetting()
{
	// 몬스터의 초기 설정을 하는 부분
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
