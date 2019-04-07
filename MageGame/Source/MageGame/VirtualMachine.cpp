// Fill out your copyright notice in the Description page of Project Settings.

#include "VirtualMachine.h"
#include "Engine/GameEngine.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Engine/World.h"

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

VMValue AVirtualMachine::InterpretInstruction(VMInstruction instruction, std::queue<VMValue>* callStack)
{
	switch (instruction)
	{
		case INSTRUCT_ADD:
		{
			if (callStack->size() < 2)
				return VMValue();

			VMValue lhs = callStack->front();
			callStack->pop();

			if (lhs.type == VM_INSTRUCTION)
				lhs = InterpretInstruction(lhs.value.instructValue, callStack);

			VMValue rhs = callStack->front();
			callStack->pop();

			if (rhs.type == VM_INSTRUCTION)
				rhs = InterpretInstruction(rhs.value.instructValue, callStack);

			return VMAdd(lhs, rhs);
		}
		case INSTRUCT_SUBTRACT:
		{
			if (callStack->size() < 2)
				return VMValue();

			VMValue lhs = callStack->front();
			callStack->pop();

			if (lhs.type == VM_INSTRUCTION)
				lhs = InterpretInstruction(lhs.value.instructValue, callStack);

			VMValue rhs = callStack->front();
			callStack->pop();

			if (rhs.type == VM_INSTRUCTION)
			{
				rhs = InterpretInstruction(rhs.value.instructValue, callStack);
			}

			return VMSubtract(lhs, rhs);
		}
		case INSTRUCT_MULTIPLY:
		{
			if (callStack->size() < 2)
				return VMValue();

			VMValue lhs = callStack->front();
			callStack->pop();

			if (lhs.type == VM_INSTRUCTION)
				lhs = InterpretInstruction(lhs.value.instructValue, callStack);

			VMValue rhs = callStack->front();
			callStack->pop();

			if (rhs.type == VM_INSTRUCTION)
				rhs = InterpretInstruction(rhs.value.instructValue, callStack);

			return VMMultiply(lhs, rhs);
		}
		case INSTRUCT_DIVIDE:
		{
			if (callStack->size() < 2)
				return VMValue();

			VMValue lhs = callStack->front();
			callStack->pop();

			if (lhs.type == VM_INSTRUCTION)
				lhs = InterpretInstruction(lhs.value.instructValue, callStack);

			VMValue rhs = callStack->front();
			callStack->pop();

			if (rhs.type == VM_INSTRUCTION)
				rhs = InterpretInstruction(rhs.value.instructValue, callStack);

			return VMDivide(lhs, rhs);
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

VMValue AVirtualMachine::VMSubtract(VMValue lhs, VMValue rhs)
{
	//types must match
	if (lhs.type != rhs.type)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("ERROR ON SUBTRACT INSTRUCTION: TYPE MISMATCH")));

		return VMValue();
	}

	switch (lhs.type)
	{
		case VM_INT:
		{
			return VMValue(VM_INT, lhs.value.intValue - rhs.value.intValue);
		}
		case VM_FLOAT:
		{
			return VMValue(VM_FLOAT, lhs.value.floatValue - rhs.value.floatValue);
		}
		case VM_VECTOR:
		{
			//return VMValue(VM_VECTOR, lhs.value.)
		}
		default:
		{
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("ERROR ON SUBTRACT INSTRUCTION: INCOMPATIBLE TYPE")));

			return VMValue();
		}
	}
}

VMValue AVirtualMachine::VMMultiply(VMValue lhs, VMValue rhs)
{
	//types must match
	if (lhs.type != rhs.type)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("ERROR ON MULTIPLY INSTRUCTION: TYPE MISMATCH")));

		return VMValue();
	}

	switch (lhs.type)
	{
		case VM_INT:
		{
			return VMValue(VM_INT, lhs.value.intValue * rhs.value.intValue);
		}
		case VM_FLOAT:
		{
			return VMValue(VM_FLOAT, lhs.value.floatValue * rhs.value.floatValue);
		}
		case VM_VECTOR:
		{
			//return VMValue(VM_VECTOR, lhs.value.)
		}
		default:
		{
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("ERROR ON MULTIPLY INSTRUCTION: INCOMPATIBLE TYPE")));

			return VMValue();
		}
	}
}

VMValue AVirtualMachine::VMDivide(VMValue lhs, VMValue rhs)
{
	//types must match
	if (lhs.type != rhs.type)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("ERROR ON DIVIDE INSTRUCTION: TYPE MISMATCH")));

		return VMValue();
	}
	else if (rhs.value.intValue == 0 || rhs.value.floatValue == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("ERROR ON DIVIDE INSTRUCTION: DIVIDE BY 0")));

		return VMValue();
	}

	switch (lhs.type)
	{
		case VM_INT:
		{
			return VMValue(VM_INT, lhs.value.intValue / rhs.value.intValue);
		}
		case VM_FLOAT:
		{
			return VMValue(VM_FLOAT, lhs.value.floatValue / rhs.value.floatValue);
		}
		case VM_VECTOR:
		{
			//return VMValue(VM_VECTOR, lhs.value.)
		}
		default:
		{
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("ERROR ON DIVIDE INSTRUCTION: INCOMPATIBLE TYPE")));

			return VMValue();
		}
	}
}

VMValue  AVirtualMachine::Random()
{
	return VMValue(VM_FLOAT, FMath::Rand());
}

VMValue  AVirtualMachine::RandomRange(float min, float max)
{
	return VMValue(VM_FLOAT, FMath::RandRange(min, max));
}

VMValue  AVirtualMachine::GetPlayerLocation(int playerIndex)
{
	//APlayerController* test = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	//test->GetActorLocation();
	return VMValue();

}

VMValue  AVirtualMachine::GetPlayerForwardVec(int playerIndex)
{
	return VMValue();
}

VMValue  AVirtualMachine::GetPlayerLeftVec(int playerIndex)
{
	return VMValue();
}

VMValue  AVirtualMachine::GetPlayerUpVec(int playerIndex)
{
	return VMValue();
}
