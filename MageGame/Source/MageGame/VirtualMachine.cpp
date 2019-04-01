// Fill out your copyright notice in the Description page of Project Settings.

#include "VirtualMachine.h"
#include "Engine/GameEngine.h"

// Sets default values
AVirtualMachine::AVirtualMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVirtualMachine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVirtualMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

VMValue AVirtualMachine::InterpretInstruction(VMInstruction instruction, std::stack<VMValue>& callStack)
{
	switch (instruction)
	{
		case INSTRUCT_ADD:
		{
			VMValue lhs = callStack.top();
			callStack.pop();

			if (lhs.type == VM_INSTRUCTION)
				lhs = InterpretInstruction(lhs.value.instructValue, callStack);

			VMValue rhs = callStack.top();
			callStack.pop();

			if (rhs.type == VM_INSTRUCTION)
				lhs = InterpretInstruction(lhs.value.instructValue, callStack);

			return VMAdd(lhs, rhs);
		}
		default:
			return VMValue();
	}
}


VMValue AVirtualMachine::VMAdd(VMValue lhs, VMValue rhs)
{
	//types must match
	if (lhs.type != rhs.type)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("ERROR ON ADD INSTRUCTION: TYPE MISMATCH")));

		return VMValue();
	}

	switch (lhs.type)
	{
		case VM_INT:
		{
			return VMValue(VM_INT, lhs.value.intValue + rhs.value.intValue);
		}
		case VM_FLOAT:
		{
			return VMValue(VM_FLOAT, lhs.value.floatValue + rhs.value.floatValue);
		}
		case VM_VECTOR:
		{
			//return VMValue(VM_VECTOR, lhs.value.)
		}
		default:
		{
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("ERROR ON ADD INSTRUCTION: INCOMPATIBLE TYPE")));

			return VMValue();
		}
	}
}


