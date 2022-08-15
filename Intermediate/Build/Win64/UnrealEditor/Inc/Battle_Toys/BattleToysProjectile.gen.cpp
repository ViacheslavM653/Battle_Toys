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
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UCameraShakeBase_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ABattleToysProjectile::execOnHit)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_STRUCT(FVector,Z_Param_NormalIpmulse);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalIpmulse,Z_Param_Out_Hit);
		P_NATIVE_END;
	}
	void ABattleToysProjectile::StaticRegisterNativesABattleToysProjectile()
	{
		UClass* Class = ABattleToysProjectile::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnHit", &ABattleToysProjectile::execOnHit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics
	{
		struct BattleToysProjectile_eventOnHit_Parms
		{
			UPrimitiveComponent* HitComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			FVector NormalIpmulse;
			FHitResult Hit;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HitComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HitComp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UECodeGen_Private::FStructPropertyParams NewProp_NormalIpmulse;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_HitComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_HitComp = { "HitComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BattleToysProjectile_eventOnHit_Parms, HitComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_HitComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_HitComp_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BattleToysProjectile_eventOnHit_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BattleToysProjectile_eventOnHit_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_OtherComp_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_NormalIpmulse = { "NormalIpmulse", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BattleToysProjectile_eventOnHit_Parms, NormalIpmulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BattleToysProjectile_eventOnHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_Hit_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_Hit_MetaData)) }; // 1416937132
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_HitComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_OtherActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_OtherComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_NormalIpmulse,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::NewProp_Hit,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BattleToysProjectile/BattleToysProjectile.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABattleToysProjectile, nullptr, "OnHit", nullptr, nullptr, sizeof(Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::BattleToysProjectile_eventOnHit_Parms), Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C40401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABattleToysProjectile_OnHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABattleToysProjectile_OnHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABattleToysProjectile);
	UClass* Z_Construct_UClass_ABattleToysProjectile_NoRegister()
	{
		return ABattleToysProjectile::StaticClass();
	}
	struct Z_Construct_UClass_ABattleToysProjectile_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileMovementComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileMovementComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HitParticles_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HitParticles;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TrailParticles_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TrailParticles;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LaunchSound_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LaunchSound;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HitSound_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HitSound;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HitCameraShakeClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_HitCameraShakeClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABattleToysProjectile_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Battle_Toys,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABattleToysProjectile_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABattleToysProjectile_OnHit, "OnHit" }, // 4294076478
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABattleToysProjectile_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BattleToysProjectile/BattleToysProjectile.h" },
		{ "ModuleRelativePath", "Public/BattleToysProjectile/BattleToysProjectile.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_ProjectileMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BattleToysProjectile/BattleToysProjectile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_ProjectileMesh = { "ProjectileMesh", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABattleToysProjectile, ProjectileMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_ProjectileMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_ProjectileMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_ProjectileMovementComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BattleToysProjectile/BattleToysProjectile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_ProjectileMovementComponent = { "ProjectileMovementComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABattleToysProjectile, ProjectileMovementComponent), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_ProjectileMovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_ProjectileMovementComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitParticles_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/BattleToysProjectile/BattleToysProjectile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitParticles = { "HitParticles", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABattleToysProjectile, HitParticles), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitParticles_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitParticles_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_TrailParticles_MetaData[] = {
		{ "Category", "Combat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BattleToysProjectile/BattleToysProjectile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_TrailParticles = { "TrailParticles", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABattleToysProjectile, TrailParticles), Z_Construct_UClass_UParticleSystemComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_TrailParticles_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_TrailParticles_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_LaunchSound_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/BattleToysProjectile/BattleToysProjectile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_LaunchSound = { "LaunchSound", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABattleToysProjectile, LaunchSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_LaunchSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_LaunchSound_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitSound_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/BattleToysProjectile/BattleToysProjectile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitSound = { "HitSound", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABattleToysProjectile, HitSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitSound_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitCameraShakeClass_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/BattleToysProjectile/BattleToysProjectile.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitCameraShakeClass = { "HitCameraShakeClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABattleToysProjectile, HitCameraShakeClass), Z_Construct_UClass_UCameraShakeBase_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitCameraShakeClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitCameraShakeClass_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABattleToysProjectile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_ProjectileMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_ProjectileMovementComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitParticles,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_TrailParticles,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_LaunchSound,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitSound,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABattleToysProjectile_Statics::NewProp_HitCameraShakeClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABattleToysProjectile_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABattleToysProjectile>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABattleToysProjectile_Statics::ClassParams = {
		&ABattleToysProjectile::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABattleToysProjectile_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ABattleToysProjectile_Statics::PropPointers),
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
		{ Z_Construct_UClass_ABattleToysProjectile, ABattleToysProjectile::StaticClass, TEXT("ABattleToysProjectile"), &Z_Registration_Info_UClass_ABattleToysProjectile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABattleToysProjectile), 1102029504U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BattleToysProjectile_BattleToysProjectile_h_1516510111(TEXT("/Script/Battle_Toys"),
		Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BattleToysProjectile_BattleToysProjectile_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BattleToysProjectile_BattleToysProjectile_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
