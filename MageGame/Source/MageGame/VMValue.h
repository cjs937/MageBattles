// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
enum VMValueType
{
	INVALID_VALUE,
	VM_INT,
	VM_FLOAT,
	VM_BOOL,
	VM_INSTRUCTION,
	VM_VECTOR
};

enum VMInstruction
{
	INSTRUCT_ADD
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
