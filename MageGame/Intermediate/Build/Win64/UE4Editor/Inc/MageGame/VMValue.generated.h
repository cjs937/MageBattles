// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MAGEGAME_VMValue_generated_h
#error "VMValue.generated.h already included, missing '#pragma once' in VMValue.h"
#endif
#define MAGEGAME_VMValue_generated_h

#define MageGame_Source_MageGame_VMValue_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FVMValue_Statics; \
	MAGEGAME_API static class UScriptStruct* StaticStruct();


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MageGame_Source_MageGame_VMValue_h


#define FOREACH_ENUM_EVMVALUETYPE(op) \
	op(EVMValueType::VM_INT) \
	op(EVMValueType::VM_FLOAT) \
	op(EVMValueType::VM_BOOL) \
	op(EVMValueType::VM_INSTRUCTION) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
