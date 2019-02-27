// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MageGame/AbilityScript.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAbilityScript() {}
// Cross Module References
	MAGEGAME_API UClass* Z_Construct_UClass_AAbilityScript_NoRegister();
	MAGEGAME_API UClass* Z_Construct_UClass_AAbilityScript();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MageGame();
// End Cross Module References
	void AAbilityScript::StaticRegisterNativesAAbilityScript()
	{
	}
	UClass* Z_Construct_UClass_AAbilityScript_NoRegister()
	{
		return AAbilityScript::StaticClass();
	}
	struct Z_Construct_UClass_AAbilityScript_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_testInt_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_testInt;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAbilityScript_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MageGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAbilityScript_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AbilityScript.h" },
		{ "ModuleRelativePath", "AbilityScript.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAbilityScript_Statics::NewProp_testInt_MetaData[] = {
		{ "Category", "Test" },
		{ "ModuleRelativePath", "AbilityScript.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AAbilityScript_Statics::NewProp_testInt = { UE4CodeGen_Private::EPropertyClass::Int, "testInt", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AAbilityScript, testInt), METADATA_PARAMS(Z_Construct_UClass_AAbilityScript_Statics::NewProp_testInt_MetaData, ARRAY_COUNT(Z_Construct_UClass_AAbilityScript_Statics::NewProp_testInt_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAbilityScript_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAbilityScript_Statics::NewProp_testInt,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAbilityScript_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAbilityScript>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAbilityScript_Statics::ClassParams = {
		&AAbilityScript::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AAbilityScript_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AAbilityScript_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AAbilityScript_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AAbilityScript_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAbilityScript()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAbilityScript_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAbilityScript, 2780007068);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAbilityScript(Z_Construct_UClass_AAbilityScript, &AAbilityScript::StaticClass, TEXT("/Script/MageGame"), TEXT("AAbilityScript"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAbilityScript);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
