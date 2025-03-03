// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BasicMonster.h"
#include "BasicMonsterAI.generated.h"

/**
 * 
 */
UCLASS()
class TESTSERVER_API ABasicMonsterAI : public AAIController
{
	GENERATED_BODY()
	
protected:
	// 몬스터 감지 관련
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAIPerceptionComponent* AIPerceptionComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAISenseConfig_Sight* SightConfig;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	ABasicMonster* Monster;

protected:
	ABasicMonsterAI();

	// 몬스터 캐릭터 클래스 불러오기
	virtual void OnPossess(APawn* InPawn) override;

	// 매 프레임마다 할 행동
	virtual void Tick(float DeltaSeconds) override;

	// 플레이어가 범위 안에 들어왔을 때/나갔을 때 실행
	UFUNCTION()
	void OnTargetDetected(AActor* Actor, FAIStimulus Stimulus);

	// 몬스터 초기 설정
	void InitialSetting();

	// 속도 변경
	void SetSpeed(float speed);

	// 플레이어가 범위 안에 들어왔을 때 할 행동 (상속 시 오버라이드 해서 사용)
	virtual void PlayerInRange(AActor* Actor = nullptr);

	// 플레이어가 범위 밖으로 나갔을 때 할 행동 (상속 시 오버라이드 해서 사용)
	virtual void PlayerOutRange(AActor* Actor = nullptr);
};
