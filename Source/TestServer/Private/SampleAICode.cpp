// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleAICode.h"
#include "Engine/Engine.h"

void ASampleAICode::PlayerInRange(AActor* Actor)
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("override : Player In Range"));
}

void ASampleAICode::PlayerOutRange(AActor* Actor)
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("override : Player Out Range"));
}
