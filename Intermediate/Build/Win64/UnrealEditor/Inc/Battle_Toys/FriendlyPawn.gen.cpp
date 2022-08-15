// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Battle_Toys/Public/BasePawn/FriendlyPawn/FriendlyPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFriendlyPawn() {}
// Cross Module References
	BATTLE_TOYS_API UClass* Z_Construct_UClass_AFriendlyPawn_NoRegister();
	BATTLE_TOYS_API UClass* Z_Construct_UClass_AFriendlyPawn();
	BATTLE_TOYS_API UClass* Z_Construct_UClass_ABasePawn();
	UPackage* Z_Construct_UPackage__Script_Battle_Toys();
// End Cross Module References
	void AFriendlyPawn::StaticRegisterNativesAFriendlyPawn()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFriendlyPawn);
	UClass* Z_Construct_UClass_AFriendlyPawn_NoRegister()
	{
		return AFriendlyPawn::StaticClass();
	}
	struct Z_Construct_UClass_AFriendlyPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFriendlyPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ABasePawn,
		(UObject* (*)())Z_Construct_UPackage__Script_Battle_Toys,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyPawn_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BasePawn/FriendlyPawn/FriendlyPawn.h" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyPawn.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFriendlyPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFriendlyPawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFriendlyPawn_Statics::ClassParams = {
		&AFriendlyPawn::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AFriendlyPawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFriendlyPawn()
	{
		if (!Z_Registration_Info_UClass_AFriendlyPawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFriendlyPawn.OuterSingleton, Z_Construct_UClass_AFriendlyPawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFriendlyPawn.OuterSingleton;
	}
	template<> BATTLE_TOYS_API UClass* StaticClass<AFriendlyPawn>()
	{
		return AFriendlyPawn::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFriendlyPawn);
	struct Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_FriendlyPawn_FriendlyPawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_FriendlyPawn_FriendlyPawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFriendlyPawn, AFriendlyPawn::StaticClass, TEXT("AFriendlyPawn"), &Z_Registration_Info_UClass_AFriendlyPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFriendlyPawn), 1690301240U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_FriendlyPawn_FriendlyPawn_h_1236041877(TEXT("/Script/Battle_Toys"),
		Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_FriendlyPawn_FriendlyPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_FriendlyPawn_FriendlyPawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
