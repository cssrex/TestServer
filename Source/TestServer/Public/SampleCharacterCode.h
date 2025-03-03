// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicMonster.h"
#include "SampleCharacterCode.generated.h"

/**
 * 
 */
UCLASS()
class TESTSERVER_API ASampleCharacterCode : public ABasicMonster
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;
};
