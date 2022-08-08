// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Battle_Toys/Public/BattleToysProjectile/BattleToysProjectile.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBattleToysProjectile() {}
// Cross Module References
	BATTLE_TOYS_API UClass* Z_Construct_UClass_ABattleToysProjectile_NoRegister();
	BATTLE_TOYS_API UClass* Z_Construct_UClass_ABattleToysProjectile();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Battle_Toys();
// End Cross Module References
	void ABattleToysProjectile::StaticRegisterNativesABattleToysProjectile()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABattleToysProjectile);
	UClass* Z_Construct_UClass_ABattleToysProjectile_NoRegister()
	{
		return ABattleToysProjectile::StaticClass();
	}
	struct Z_Construct_UClass_ABattleToysProjectile_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABattleToysProjectile_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Battle_Toys,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABattleToysProjectile_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BattleToysProjectile/BattleToysProjectile.h" },
		{ "ModuleRelativePath", "Public/BattleToysProjectile/BattleToysProjectile.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABattleToysProjectile_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABattleToysProjectile>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABattleToysProjectile_Statics::ClassParams = {
		&ABattleToysProjectile::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABattleToysProjectile_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABattleToysProjectile_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABattleToysProjectile()
	{
		if (!Z_Registration_Info_UClass_ABattleToysProjectile.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABattleToysProjectile.OuterSingleton, Z_Construct_UClass_ABattleToysProjectile_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABattleToysProjectile.OuterSingleton;
	}
	template<> BATTLE_TOYS_API UClass* StaticClass<ABattleToysProjectile>()
	{
		return ABattleToysProjectile::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABattleToysProjectile);
	struct Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BattleToysProjectile_BattleToysProjectile_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BattleToysProjectile_BattleToysProjectile_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABattleToysProjectile, ABattleToysProjectile::StaticClass, TEXT("ABattleToysProjectile"), &Z_Registration_Info_UClass_ABattleToysProjectile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABattleToysProjectile), 357657024U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BattleToysProjectile_BattleToysProjectile_h_4088468438(TEXT("/Script/Battle_Toys"),
		Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BattleToysProjectile_BattleToysProjectile_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BattleToysProjectile_BattleToysProjectile_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
