// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MageGame/VMValue.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVMValue() {}
// Cross Module References
	MAGEGAME_API UEnum* Z_Construct_UEnum_MageGame_EVMValueType();
	UPackage* Z_Construct_UPackage__Script_MageGame();
	MAGEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FVMValue();
// End Cross Module References
	static UEnum* EVMValueType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_MageGame_EVMValueType, Z_Construct_UPackage__Script_MageGame(), TEXT("EVMValueType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVMValueType(EVMValueType_StaticEnum, TEXT("/Script/MageGame"), TEXT("EVMValueType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_MageGame_EVMValueType_CRC() { return 1492419520U; }
	UEnum* Z_Construct_UEnum_MageGame_EVMValueType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_MageGame();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVMValueType"), 0, Get_Z_Construct_UEnum_MageGame_EVMValueType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVMValueType::VM_INT", (int64)EVMValueType::VM_INT },
				{ "EVMValueType::VM_FLOAT", (int64)EVMValueType::VM_FLOAT },
				{ "EVMValueType::VM_BOOL", (int64)EVMValueType::VM_BOOL },
				{ "EVMValueType::VM_INSTRUCTION", (int64)EVMValueType::VM_INSTRUCTION },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "VMValue.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_MageGame,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EVMValueType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EVMValueType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FVMValue::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MAGEGAME_API uint32 Get_Z_Construct_UScriptStruct_FVMValue_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVMValue, Z_Construct_UPackage__Script_MageGame(), TEXT("VMValue"), sizeof(FVMValue), Get_Z_Construct_UScriptStruct_FVMValue_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVMValue(FVMValue::StaticStruct, TEXT("/Script/MageGame"), TEXT("VMValue"), false, nullptr, nullptr);
static struct FScriptStruct_MageGame_StaticRegisterNativesFVMValue
{
	FScriptStruct_MageGame_StaticRegisterNativesFVMValue()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VMValue")),new UScriptStruct::TCppStructOps<FVMValue>);
	}
} ScriptStruct_MageGame_StaticRegisterNativesFVMValue;
	struct Z_Construct_UScriptStruct_FVMValue_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_type_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_type;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_type_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVMValue_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "VMValue.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVMValue_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVMValue>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVMValue_Statics::NewProp_type_MetaData[] = {
		{ "Category", "VMValue" },
		{ "ModuleRelativePath", "VMValue.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FVMValue_Statics::NewProp_type = { UE4CodeGen_Private::EPropertyClass::Enum, "type", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FVMValue, type), Z_Construct_UEnum_MageGame_EVMValueType, METADATA_PARAMS(Z_Construct_UScriptStruct_FVMValue_Statics::NewProp_type_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVMValue_Statics::NewProp_type_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FVMValue_Statics::NewProp_type_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVMValue_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVMValue_Statics::NewProp_type,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVMValue_Statics::NewProp_type_Underlying,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVMValue_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MageGame,
		nullptr,
		&NewStructOps,
		"VMValue",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FVMValue),
		alignof(FVMValue),
		Z_Construct_UScriptStruct_FVMValue_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVMValue_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVMValue_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVMValue_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVMValue()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVMValue_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_MageGame();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VMValue"), sizeof(FVMValue), Get_Z_Construct_UScriptStruct_FVMValue_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVMValue_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVMValue_CRC() { return 739318266U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
