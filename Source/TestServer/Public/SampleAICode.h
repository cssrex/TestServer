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
	// 플레이어가 범위 안에 들어왔을 때 할 행동 (상속 시 오버라이드 해서 사용)
	virtual void PlayerInRange(AActor* Actor = nullptr) override;

	// 플레이어가 범위 밖으로 나갔을 때 할 행동 (상속 시 오버라이드 해서 사용)
	virtual void PlayerOutRange(AActor* Actor = nullptr) override;
};
