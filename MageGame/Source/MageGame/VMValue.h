// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/CoreUObject/Public/UObject/Class.h"
/**
 * 
 */

UENUM(BlueprintType)
enum class VMValueType : uint8
{
	INVALID_VALUE UMETA(DisplayName = "Invalid Value"),
	VM_INT UMETA(DisplayName = "Int"),
	VM_FLOAT UMETA(DisplayName = "Float"),
	VM_BOOL UMETA(DisplayName = "Bool"),
	VM_INSTRUCTION UMETA(DisplayName = "Instruction"),
	VM_VECTOR UMETA(DisplayName = "Vector")
};


UENUM(BlueprintType)
enum class VMInstruction : uint8
{
	INSTRUCT_ADD UMETA(DisplayName = "Add Instruction"),
	INSTRUCT_SUBTRACT UMETA(DisplayName = "Subtact Instruction"),
	INSTRUCT_MULTIPLY UMETA(DisplayName = "Multiply Instruction"),
	INSTRUCT_DIVIDE UMETA(DisplayName = "Divide Instruction"),
	INSTRUCT_LOCATION UMETA(DisplayName = "Get Location Instruction")
};

struct VMVector
{
	float x, y, z;

	VMVector() = default;

	VMVector(float _x, float _y, float _z);
	FVector convertToFVec();
};

struct MAGEGAME_API VMValue
{
	VMValue();

	//template<typename T>
	//VMValue(VMValueType _type, T _value);
	
	VMValue(VMInstruction _value);
	VMValue(int _value);
	VMValue(float _value);
	VMValue(bool  _value);
	VMValue(VMVector _value);

	~VMValue();

	VMValueType type;

	union Value
	{
		int intValue;
		float floatValue;
		bool boolValue;
		VMInstruction instructValue;
		VMVector vectorValue;
	} value;
};

int GetInstructionWeight(VMInstruction instruct);
