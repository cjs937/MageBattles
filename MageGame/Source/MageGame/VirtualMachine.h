// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VMValue.h"
#include <queue>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VirtualMachine.generated.h"

UCLASS()
class MAGEGAME_API AVirtualMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVirtualMachine();
	static VMValue InterpretInstruction(VMInstruction instruction, std::queue<VMValue>& callStack);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	static VMValue VMAdd(VMValue lhs, VMValue rhs);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
