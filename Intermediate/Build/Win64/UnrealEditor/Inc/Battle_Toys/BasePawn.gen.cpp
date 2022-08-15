// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Battle_Toys/Public/BasePawn/BasePawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBasePawn() {}
// Cross Module References
	BATTLE_TOYS_API UClass* Z_Construct_UClass_ABasePawn_NoRegister();
	BATTLE_TOYS_API UClass* Z_Construct_UClass_ABasePawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_Battle_Toys();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	BATTLE_TOYS_API UClass* Z_Construct_UClass_ABattleToysProjectile_NoRegister();
	BATTLE_TOYS_API UClass* Z_Construct_UClass_UHealthComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraShakeBase_NoRegister();
// End Cross Module References
	void ABasePawn::StaticRegisterNativesABasePawn()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABasePawn);
	UClass* Z_Construct_UClass_ABasePawn_NoRegister()
	{
		return ABasePawn::StaticClass();
	}
	struct Z_Construct_UClass_ABasePawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_ProjectileClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileDamage_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileDamage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HealthComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeathParticles_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DeathParticles;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeathSound_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DeathSound;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeathCameraShakeClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_DeathCameraShakeClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABasePawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_Battle_Toys,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABasePawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BasePawn/BasePawn.h" },
		{ "ModuleRelativePath", "Public/BasePawn/BasePawn.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileClass_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ModuleRelativePath", "Public/BasePawn/BasePawn.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileClass = { "ProjectileClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABasePawn, ProjectileClass), Z_Construct_UClass_ABattleToysProjectile_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileDamage_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ModuleRelativePath", "Public/BasePawn/BasePawn.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileDamage = { "ProjectileDamage", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABasePawn, ProjectileDamage), METADATA_PARAMS(Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileDamage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileDamage_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileSpeed_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ModuleRelativePath", "Public/BasePawn/BasePawn.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileSpeed = { "ProjectileSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABasePawn, ProjectileSpeed), METADATA_PARAMS(Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABasePawn_Statics::NewProp_HealthComponent_MetaData[] = {
		{ "Category", "Health" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/BasePawn.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABasePawn_Statics::NewProp_HealthComponent = { "HealthComponent", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABasePawn, HealthComponent), Z_Construct_UClass_UHealthComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABasePawn_Statics::NewProp_HealthComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABasePawn_Statics::NewProp_HealthComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathParticles_MetaData[] = {
		{ "Category", "Death" },
		{ "ModuleRelativePath", "Public/BasePawn/BasePawn.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathParticles = { "DeathParticles", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABasePawn, DeathParticles), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathParticles_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathParticles_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathSound_MetaData[] = {
		{ "Category", "Death" },
		{ "ModuleRelativePath", "Public/BasePawn/BasePawn.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathSound = { "DeathSound", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABasePawn, DeathSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathSound_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathCameraShakeClass_MetaData[] = {
		{ "Category", "Death" },
		{ "ModuleRelativePath", "Public/BasePawn/BasePawn.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathCameraShakeClass = { "DeathCameraShakeClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABasePawn, DeathCameraShakeClass), Z_Construct_UClass_UCameraShakeBase_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathCameraShakeClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathCameraShakeClass_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABasePawn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileDamage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABasePawn_Statics::NewProp_ProjectileSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABasePawn_Statics::NewProp_HealthComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathParticles,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathSound,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABasePawn_Statics::NewProp_DeathCameraShakeClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABasePawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABasePawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABasePawn_Statics::ClassParams = {
		&ABasePawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABasePawn_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABasePawn_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABasePawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABasePawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABasePawn()
	{
		if (!Z_Registration_Info_UClass_ABasePawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABasePawn.OuterSingleton, Z_Construct_UClass_ABasePawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABasePawn.OuterSingleton;
	}
	template<> BATTLE_TOYS_API UClass* StaticClass<ABasePawn>()
	{
		return ABasePawn::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABasePawn);
	struct Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_BasePawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_BasePawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABasePawn, ABasePawn::StaticClass, TEXT("ABasePawn"), &Z_Registration_Info_UClass_ABasePawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABasePawn), 487266262U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_BasePawn_h_4024162511(TEXT("/Script/Battle_Toys"),
		Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_BasePawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_BasePawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
