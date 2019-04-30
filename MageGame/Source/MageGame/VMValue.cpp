// Fill out your copyright notice in the Description page of Project Settings.

#include "VMValue.h"


//-----------------------------------------VMVector-------------------------------------//
VMVector::VMVector(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

FVector VMVector::convertToFVec()
{
	return FVector(x, y, z);
}

//-----------------------------------------VMValue-------------------------------------//

VMValue::VMValue(): type(VMValueType::INVALID_VALUE)
{
	value.vectorValue = VMVector(-1, -10, -100);
}

VMValue::VMValue(VMInstruction _value) :type(VMValueType::VM_INSTRUCTION)
{
	value.instructValue = _value;
}

VMValue::VMValue(int _value):type(VMValueType::VM_INT)
{
	value.intValue = _value;
}

VMValue::VMValue(float _value): type(VMValueType::VM_FLOAT)
{
	value.floatValue = _value;
}

VMValue::VMValue(bool  _value): type(VMValueType::VM_BOOL)
{
	value.boolValue = _value;
}

VMValue::VMValue(VMVector _value): type(VMValueType::VM_VECTOR)
{
	value.vectorValue = _value;
}


VMValue::~VMValue()
{}

int GetInstructionWeight(VMInstruction instruct)
{
	switch (instruct)
	{
	case VMInstruction::INSTRUCT_ADD:
	case VMInstruction::INSTRUCT_SUBTRACT:
	{
		return 2;
	}

	case VMInstruction::INSTRUCT_MULTIPLY:
	case VMInstruction::INSTRUCT_DIVIDE:
	{
		return 3;
	}
	default:
		return -1;
	}
}
