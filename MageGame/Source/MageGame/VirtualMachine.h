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
	VMValue InterpretInstruction(VMInstruction instruction, std::queue<VMValue>* callStack);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	VMValue VMAdd(VMValue lhs, VMValue rhs);
	VMValue VMSubtract(VMValue lhs, VMValue rhs);
	VMValue VMMultiply(VMValue lhs, VMValue rhs);
	VMValue VMDivide(VMValue lhs, VMValue rhs);

	VMValue Random();
	VMValue RandomRange(float min, float max);

	VMValue GetPlayerLocation(int playerIndex);
	VMValue GetPlayerForwardVec(int playerIndex);
	VMValue GetPlayerLeftVec(int playerIndex);
	VMValue GetPlayerUpVec(int playerIndex);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
