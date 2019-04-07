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

	PrimaryActorTick.bCanEverTick = true;

	operation1Result = 0;
	operation2Result = 0;
	operation3Result = 0;

	//op1
	callStack.push(VMValue(VM_INSTRUCTION, INSTRUCT_ADD));
	callStack.push(VMValue(VM_INT, testInt1));
	callStack.push(VMValue(VM_INT, testInt2));
	
	//op2
	callStack.push(VMValue(VM_INSTRUCTION, INSTRUCT_SUBTRACT));
	callStack.push(VMValue(VM_INT, testInt1));
	callStack.push(VMValue(VM_INSTRUCTION, INSTRUCT_ADD));
	callStack.push(VMValue(VM_INT, testInt1));
	callStack.push(VMValue(VM_INT, testInt2));

	//op3
	callStack.push(VMValue(VM_INSTRUCTION, INSTRUCT_MULTIPLY));
	callStack.push(VMValue(VM_INSTRUCTION, INSTRUCT_ADD));
	callStack.push(VMValue(VM_INT, testInt1));
	callStack.push(VMValue(VM_INT, testInt2));
	callStack.push(VMValue(VM_INSTRUCTION, INSTRUCT_DIVIDE));
	callStack.push(VMValue(VM_INT, testInt2));
	callStack.push(VMValue(VM_INT, testInt1));
}

// Called every frame
void AAbilityScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (callStack.size() > 0)
	{
		//op1
		VMInstruction instruct = callStack.front().value.instructValue;
		callStack.pop();
		
		VMValue test = AVirtualMachine::InterpretInstruction(instruct, &callStack);
		
		operation1Result = test.value.intValue;

		//op2
		instruct = callStack.front().value.instructValue;
		callStack.pop();
		
		test = AVirtualMachine::InterpretInstruction(instruct, &callStack);
		
		operation2Result = test.value.intValue;
		
		//op3
		instruct = callStack.front().value.instructValue;
		callStack.pop();
		
		test = AVirtualMachine::InterpretInstruction(instruct, &callStack);
		
		operation3Result = test.value.intValue;

		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("Operation 1: %i"), operation1Result));
	}	

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("Operation 1: %i"), operation1Result));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("Operation 2: %i"), operation2Result));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("Operation 3: %i"), operation3Result));

}
