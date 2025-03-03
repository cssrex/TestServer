// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicMonsterAI.h"
#include "SampleAICode.generated.h"

/**
 * 
 */
UCLASS()
class TESTSERVER_API ASampleAICode : public ABasicMonsterAI
{
	GENERATED_BODY()
	
public:
	// �÷��̾ ���� �ȿ� ������ �� �� �ൿ (��� �� �������̵� �ؼ� ���)
	virtual void PlayerInRange(AActor* Actor = nullptr) override;

	// �÷��̾ ���� ������ ������ �� �� �ൿ (��� �� �������̵� �ؼ� ���)
	virtual void PlayerOutRange(AActor* Actor = nullptr) override;
};
