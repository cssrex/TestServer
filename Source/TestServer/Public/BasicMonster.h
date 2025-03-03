// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#include "BasicMonster.generated.h"

UCLASS()
class TESTSERVER_API ABasicMonster : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's propertiesB
	ABasicMonster();

	// ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
	float hpMax;				// �ִ� ü��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
	float hpCur;				// ���� ü��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
	float moveSpeed;			// �̵� �ӵ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
	float detectedRange;		// Ž�� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
	float loseRange;			// ��� ����


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetMoveSpeed(float newSpeed);

	float GetDetectedRange()	{ return detectedRange; }
	float GetLoseRange()		{ return loseRange; }
	float GetMoveSpeed()		{ return moveSpeed; }
};
