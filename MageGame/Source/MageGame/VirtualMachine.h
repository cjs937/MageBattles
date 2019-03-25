// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VirtualMachine.generated.h"

enum VMInstructions
{
	ADD
};


UCLASS()
class MAGEGAME_API AVirtualMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVirtualMachine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float VMAdd(float lhs, float rhs);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
