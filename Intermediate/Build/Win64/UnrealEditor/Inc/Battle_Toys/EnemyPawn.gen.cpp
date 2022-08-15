// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Battle_Toys/Public/BasePawn/EnemyPawn/EnemyPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyPawn() {}
// Cross Module References
	BATTLE_TOYS_API UClass* Z_Construct_UClass_AEnemyPawn_NoRegister();
	BATTLE_TOYS_API UClass* Z_Construct_UClass_AEnemyPawn();
	BATTLE_TOYS_API UClass* Z_Construct_UClass_ABasePawn();
	UPackage* Z_Construct_UPackage__Script_Battle_Toys();
// End Cross Module References
	void AEnemyPawn::StaticRegisterNativesAEnemyPawn()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemyPawn);
	UClass* Z_Construct_UClass_AEnemyPawn_NoRegister()
	{
		return AEnemyPawn::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ABasePawn,
		(UObject* (*)())Z_Construct_UPackage__Script_Battle_Toys,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyPawn_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BasePawn/EnemyPawn/EnemyPawn.h" },
		{ "ModuleRelativePath", "Public/BasePawn/EnemyPawn/EnemyPawn.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyPawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemyPawn_Statics::ClassParams = {
		&AEnemyPawn::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemyPawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemyPawn()
	{
		if (!Z_Registration_Info_UClass_AEnemyPawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemyPawn.OuterSingleton, Z_Construct_UClass_AEnemyPawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AEnemyPawn.OuterSingleton;
	}
	template<> BATTLE_TOYS_API UClass* StaticClass<AEnemyPawn>()
	{
		return AEnemyPawn::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyPawn);
	struct Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_EnemyPawn_EnemyPawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_EnemyPawn_EnemyPawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AEnemyPawn, AEnemyPawn::StaticClass, TEXT("AEnemyPawn"), &Z_Registration_Info_UClass_AEnemyPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemyPawn), 2023821856U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_EnemyPawn_EnemyPawn_h_1377342954(TEXT("/Script/Battle_Toys"),
		Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_EnemyPawn_EnemyPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_EnemyPawn_EnemyPawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
