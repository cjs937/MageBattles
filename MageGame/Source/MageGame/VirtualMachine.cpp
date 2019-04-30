// Fill out your copyright notice in the Description page of Project Settings.

#include "VirtualMachine.h"
#include "Engine/GameEngine.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
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

	if (callStack.size() > 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("%d"), callStack.top().value.intValue));
	}
}

VMValue AVirtualMachine::InterpretInstruction(VMInstruction instruction)
{
	switch (instruction)
	{
		case VMInstruction::INSTRUCT_ADD:
		{
			if (callStack.size() < 2)
				return VMValue();

			VMValue rhs = callStack.top();
			callStack.pop();

			if (rhs.type == VMValueType::VM_INSTRUCTION)
				rhs = InterpretInstruction(rhs.value.instructValue);

			VMValue lhs = callStack.top();
			callStack.pop();

			if (lhs.type == VMValueType::VM_INSTRUCTION)
				lhs = InterpretInstruction(lhs.value.instructValue);

			return VMAdd(lhs, rhs);
		}
		case VMInstruction::INSTRUCT_SUBTRACT:
		{
			if (callStack.size() < 2)
				return VMValue();

			VMValue rhs = callStack.top();
			callStack.pop();

			if (rhs.type == VMValueType::VM_INSTRUCTION)
				rhs = InterpretInstruction(rhs.value.instructValue);

			VMValue lhs = callStack.top();
			callStack.pop();

			if (lhs.type == VMValueType::VM_INSTRUCTION)
				lhs = InterpretInstruction(lhs.value.instructValue);

			return VMSubtract(lhs, rhs);
		}
		//case VMInstruction::INSTRUCT_MULTIPLY:
		//{
		//	if (callStack->size() < 2)
		//		return VMValue();
		//
		//	VMValue lhs = callStack->front();
		//	callStack->pop();
		//
		//	if (lhs.type == VMValueType::VM_INSTRUCTION)
		//		lhs = InterpretInstruction(lhs.value.instructValue)
		//
		//	VMValue rhs = callStack->front();
		//	callStack->pop();
		//
		//	if (rhs.type == VMValueType::VM_INSTRUCTION)
		//		rhs = InterpretInstruction(rhs.value.instructValue)
		//
		//	return VMMultiply(lhs, rhs);
		//}
		//case VMInstruction::INSTRUCT_DIVIDE:
		//{
		//	if (callStack->size() < 2)
		//		return VMValue();
		//
		//	VMValue lhs = callStack->front();
		//	callStack->pop();
		//
		//	if (lhs.type == VMValueType::VM_INSTRUCTION)
		//		lhs = InterpretInstruction(lhs.value.instructValue)
		//
		//	VMValue rhs = callStack->front();
		//	callStack->pop();
		//
		//	if (rhs.type == VMValueType::VM_INSTRUCTION)
		//		rhs = InterpretInstruction(rhs.value.instructValue)
		//
		//	return VMDivide(lhs, rhs);
		//}
		//case VMInstruction::INSTRUCT_LOCATION:
		//{
		//	if (callStack->size() == 0)
		//		return VMValue();
		//
		//	VMValue index = callStack->front();
		//	callStack->pop();
		//
		//	if (index.type == VMValueType::VM_INSTRUCTION)
		//		index = InterpretInstruction(index.value.instructValue);
		//
		//	return GetPlayerLocation(index.value.intValue);
		//}
		default:
			return VMValue();
	}
}

FString AVirtualMachine::InterpretCalculations()
{
	if (instructStack.size() > 0)
	{
		callStack.push(instructStack.top());
		instructStack.pop();
	}

	VMInstruction instruction = callStack.top().value.instructValue;
	callStack.pop();

	return FString::SanitizeFloat(InterpretInstruction(instruction).value.intValue);
}

void AVirtualMachine::PushInt(int value)
{
	callStack.push(VMValue(value));
}

void AVirtualMachine::PushInstruction(VMInstruction instruct)
{
	if (instructStack.size() > 0 && GetInstructionWeight(instruct) >= GetInstructionWeight(instructStack.top().value.instructValue))
	{
		callStack.push(instructStack.top());
		instructStack.pop();
	}

	instructStack.push(VMValue(instruct));
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
		case VMValueType::VM_INT:
		{
			return VMValue(lhs.value.intValue + rhs.value.intValue);
		}
		case VMValueType::VM_FLOAT:
		{
			return VMValue(lhs.value.floatValue + rhs.value.floatValue);
		}
		case VMValueType::VM_VECTOR:
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
		case VMValueType::VM_INT:
		{
			return VMValue(lhs.value.intValue - rhs.value.intValue);
		}
		case VMValueType::VM_FLOAT:
		{
			return VMValue(lhs.value.floatValue - rhs.value.floatValue);
		}
		case VMValueType::VM_VECTOR:
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
		case VMValueType::VM_INT:
		{
			return VMValue(lhs.value.intValue * rhs.value.intValue);
		}
		case VMValueType::VM_FLOAT:
		{
			return VMValue(lhs.value.floatValue * rhs.value.floatValue);
		}
		case VMValueType::VM_VECTOR:
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
	case VMValueType::VM_INT:
		{
			return VMValue(lhs.value.intValue / rhs.value.intValue);
		}
		case VMValueType::VM_FLOAT:
		{
			return VMValue(lhs.value.floatValue / rhs.value.floatValue);
		}
		case VMValueType::VM_VECTOR:
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

VMValue AVirtualMachine::Random()
{
	return VMValue((float)FMath::Rand());
}

VMValue AVirtualMachine::RandomRange(float min, float max)
{
	return VMValue((float)FMath::RandRange(min, max));
}

VMValue AVirtualMachine::GetPlayerLocation(int playerIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("Index: %d"), playerIndex));

	ACharacter* player = UGameplayStatics::GetPlayerCharacter(this, playerIndex);

	if (player == NULL)
		return VMValue();

	FVector loc = player->GetActorLocation();
	VMValue location(VMVector(loc.X, loc.Y, loc.Z));

	//test->GetActorLocation();
	return location;//VMValue();

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
