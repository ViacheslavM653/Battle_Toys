// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Battle_Toys/Public/BattleToysGameMode/BattleToysGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBattleToysGameMode() {}
// Cross Module References
	BATTLE_TOYS_API UClass* Z_Construct_UClass_ABattleToysGameMode_NoRegister();
	BATTLE_TOYS_API UClass* Z_Construct_UClass_ABattleToysGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Battle_Toys();
// End Cross Module References
	void ABattleToysGameMode::StaticRegisterNativesABattleToysGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABattleToysGameMode);
	UClass* Z_Construct_UClass_ABattleToysGameMode_NoRegister()
	{
		return ABattleToysGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ABattleToysGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABattleToysGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Battle_Toys,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABattleToysGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "BattleToysGameMode/BattleToysGameMode.h" },
		{ "ModuleRelativePath", "Public/BattleToysGameMode/BattleToysGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABattleToysGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABattleToysGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABattleToysGameMode_Statics::ClassParams = {
		&ABattleToysGameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ABattleToysGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABattleToysGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABattleToysGameMode()
	{
		if (!Z_Registration_Info_UClass_ABattleToysGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABattleToysGameMode.OuterSingleton, Z_Construct_UClass_ABattleToysGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABattleToysGameMode.OuterSingleton;
	}
	template<> BATTLE_TOYS_API UClass* StaticClass<ABattleToysGameMode>()
	{
		return ABattleToysGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABattleToysGameMode);
	struct Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BattleToysGameMode_BattleToysGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BattleToysGameMode_BattleToysGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABattleToysGameMode, ABattleToysGameMode::StaticClass, TEXT("ABattleToysGameMode"), &Z_Registration_Info_UClass_ABattleToysGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABattleToysGameMode), 2120873281U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BattleToysGameMode_BattleToysGameMode_h_3810223244(TEXT("/Script/Battle_Toys"),
		Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BattleToysGameMode_BattleToysGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BattleToysGameMode_BattleToysGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
