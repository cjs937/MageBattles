// Fill out your copyright notice in the Description page of Project Settings.

#include "VMValue.h"

VMValue::VMValue()
{
}

VMValue::VMValue(VMValueType _type, int _test)
{
	type = _type;

	value.intValue = _test;
}


VMValue::~VMValue()
{
}
