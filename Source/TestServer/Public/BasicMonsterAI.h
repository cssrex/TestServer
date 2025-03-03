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
	// ���� ���� ����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAIPerceptionComponent* AIPerceptionComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAISenseConfig_Sight* SightConfig;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	ABasicMonster* Monster;

protected:
	ABasicMonsterAI();

	// ���� ĳ���� Ŭ���� �ҷ�����
	virtual void OnPossess(APawn* InPawn) override;

	// �� �����Ӹ��� �� �ൿ
	virtual void Tick(float DeltaSeconds) override;

	// �÷��̾ ���� �ȿ� ������ ��/������ �� ����
	UFUNCTION()
	void OnTargetDetected(AActor* Actor, FAIStimulus Stimulus);

	// ���� �ʱ� ����
	void InitialSetting();

	// �ӵ� ����
	void SetSpeed(float speed);

	// �÷��̾ ���� �ȿ� ������ �� �� �ൿ (��� �� �������̵� �ؼ� ���)
	virtual void PlayerInRange(AActor* Actor = nullptr);

	// �÷��̾ ���� ������ ������ �� �� �ൿ (��� �� �������̵� �ؼ� ���)
	virtual void PlayerOutRange(AActor* Actor = nullptr);
};
