// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/CoreUObject/Public/UObject/Class.h"
/**
 * 
 */

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class VMValueType : uint8
{
	INVALID_VALUE UMETA(DisplayName = "Invalid Value"),
	VM_INT UMETA(DisplayName = "Int"),
	VM_FLOAT UMETA(DisplayName = "Float"),
	VM_BOOL UMETA(DisplayName = "Bool"),
	VM_INSTRUCTION UMETA(DisplayName = "Instruction"),
	VM_VECTOR UMETA(DisplayName = "Vector")
};


//enum VMValueType
//{
//	INVALID_VALUE,
//	VM_INT,
//	VM_FLOAT,
//	VM_BOOL,
//	VM_INSTRUCTION,
//	VM_VECTOR
//};

enum VMInstruction
{
	INSTRUCT_ADD,
	INSTRUCT_SUBTRACT,
	INSTRUCT_MULTIPLY,
	INSTRUCT_DIVIDE
};

struct MAGEGAME_API VMValue
{
	VMValue();

	//template<typename T>
	//VMValue(VMValueType _type, T _value);
	
	VMValue(VMValueType _type, VMInstruction _value);
	VMValue(VMValueType _type, int _value);
	VMValue(VMValueType _type, float _value);
	VMValue(VMValueType _type, bool  _value);

	~VMValue();

	VMValueType type;

	union Value
	{
		int intValue;
		float floatValue;
		bool boolValue;
		VMInstruction instructValue;
		//FVector vectorValue;

	} value;
};
