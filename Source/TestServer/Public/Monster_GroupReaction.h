// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicMonster.h"
#include "Monster_GroupReaction.generated.h"

/**
 * 
 */
UCLASS()
class TESTSERVER_API AMonster_GroupReaction : public ABasicMonster
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
	int GroupNumber;

	int GetGroupNumber() { return GroupNumber; }
};
