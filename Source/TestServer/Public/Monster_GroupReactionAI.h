// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicMonsterAI.h"
#include "Monster_GroupReactionAI.generated.h"

#define MAX_GROUP_COUNT			10
/**
 * 
 */
UCLASS()
class TESTSERVER_API AMonster_GroupReactionAI : public ABasicMonsterAI
{
	GENERATED_BODY()

protected:
	static int DetectedCount[MAX_GROUP_COUNT];
	static AActor* Target;

	int Group;

protected:

	virtual void OnPossess(APawn* InPawn) override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void PlayerInRange(AActor* Actor = nullptr) override;

	virtual void PlayerOutRange(AActor* Actor = nullptr) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};