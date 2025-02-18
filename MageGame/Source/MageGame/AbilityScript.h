// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <queue>

#include "VMValue.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VirtualMachine.h"
#include "AbilityScript.generated.h"

UCLASS()
class MAGEGAME_API AAbilityScript : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbilityScript();

	UPROPERTY(EditAnywhere)
	int testInt1;

	UPROPERTY(EditAnywhere)
	int testInt2;

	UPROPERTY(EditAnywhere)
	AVirtualMachine* VM;

	//UPROPERTY(EditAnywhere)
	std::queue<VMValue> callStack;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	int operation1Result;
	int operation2Result;
	int operation3Result;
	//int testDivide;
	
};