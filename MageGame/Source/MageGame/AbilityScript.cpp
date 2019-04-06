// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilityScript.h"
#include "Engine/GameEngine.h"
#include "VirtualMachine.h"

// Sets default values
AAbilityScript::AAbilityScript()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAbilityScript::BeginPlay()
{
	Super::BeginPlay();

	VMValue test(VM_INSTRUCTION, INSTRUCT_ADD);
	VMValue lhs(VM_INT, 1);
	VMValue rhs(VM_INT, 2);

	callStack.push(test);
	callStack.push(lhs);
	callStack.push(rhs);


	PrimaryActorTick.bCanEverTick = true;

	testInt = 0;
}

// Called every frame
void AAbilityScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (callStack.size() > 0)
	{
		VMInstruction instruct = callStack.front().value.instructValue;
		callStack.pop();
		
		VMValue test = AVirtualMachine::InterpretInstruction(instruct, callStack);
		
		testInt = test.value.intValue;
	}	

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("TEST %i"), testInt));
}
