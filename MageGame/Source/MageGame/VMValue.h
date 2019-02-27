// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
enum VMValueType
{
	VM_INT,
	VM_FLOAT,
	VM_BOOL,
	VM_INSTRUCTION
};

struct MAGEGAME_API VMValue
{
	VMValue();
	VMValue(VMValueType _type, int _test);
	~VMValue();

	VMValueType type;

	union Value
	{
		int intValue;
		float floatValue;
		bool boolValue;
		int instructValue;
	} value;
};
