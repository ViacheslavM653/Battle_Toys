// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Battle_Toys/Battle_ToysGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBattle_ToysGameModeBase() {}
// Cross Module References
	BATTLE_TOYS_API UClass* Z_Construct_UClass_ABattle_ToysGameModeBase_NoRegister();
	BATTLE_TOYS_API UClass* Z_Construct_UClass_ABattle_ToysGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Battle_Toys();
// End Cross Module References
	void ABattle_ToysGameModeBase::StaticRegisterNativesABattle_ToysGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABattle_ToysGameModeBase);
	UClass* Z_Construct_UClass_ABattle_ToysGameModeBase_NoRegister()
	{
		return ABattle_ToysGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ABattle_ToysGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABattle_ToysGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Battle_Toys,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABattle_ToysGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Battle_ToysGameModeBase.h" },
		{ "ModuleRelativePath", "Battle_ToysGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABattle_ToysGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABattle_ToysGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABattle_ToysGameModeBase_Statics::ClassParams = {
		&ABattle_ToysGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ABattle_ToysGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABattle_ToysGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABattle_ToysGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ABattle_ToysGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABattle_ToysGameModeBase.OuterSingleton, Z_Construct_UClass_ABattle_ToysGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABattle_ToysGameModeBase.OuterSingleton;
	}
	template<> BATTLE_TOYS_API UClass* StaticClass<ABattle_ToysGameModeBase>()
	{
		return ABattle_ToysGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABattle_ToysGameModeBase);
	struct Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Battle_ToysGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Battle_ToysGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABattle_ToysGameModeBase, ABattle_ToysGameModeBase::StaticClass, TEXT("ABattle_ToysGameModeBase"), &Z_Registration_Info_UClass_ABattle_ToysGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABattle_ToysGameModeBase), 789534431U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Battle_ToysGameModeBase_h_1932043274(TEXT("/Script/Battle_Toys"),
		Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Battle_ToysGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Battle_ToysGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
