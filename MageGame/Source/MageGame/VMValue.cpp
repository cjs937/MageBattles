// Fill out your copyright notice in the Description page of Project Settings.

#include "VMValue.h"

VMValue::VMValue(): type(INVALID_VALUE)
{}

//template<typename T>
//VMValue::VMValue(const VMValueType &_type, const T &_value):type(_type)
//{
//	switch (_type)
//	{
//		case VM_INT:
//		{
//			value.intValue = (int)_value;
//			break;
//		}
//		case VM_FLOAT:
//		{
//			value.floatValue = (float)_value;
//			break;
//		}
//		case VM_BOOL:
//		{
//			value.boolValue = (bool)_value;
//			break;
//		}
//		case VM_INSTRUCTION:
//		{
//			value.instructValue = (int)_value;
//			break;
//		}
//		case VM_VECTOR:
//		{
//			value.vectorValue = (FVector)_value;
//			break;
//		}
//		default:
//			break;
//	}
//}

VMValue::VMValue(VMValueType _type, VMInstruction _value) :type(_type)
{
	value.instructValue = _value;
}

VMValue::VMValue(VMValueType _type, int _value):type(_type)
{
	value.intValue = _value;
}

VMValue::VMValue(VMValueType _type, float _value): type(_type)
{
	value.floatValue = _value;
}

VMValue::VMValue(VMValueType _type, bool  _value): type(_type)
{
	value.boolValue = _value;
}


VMValue::~VMValue()
{}