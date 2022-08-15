// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Battle_Toys/Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFriendlyBaseTank() {}
// Cross Module References
	BATTLE_TOYS_API UClass* Z_Construct_UClass_AFriendlyBaseTank_NoRegister();
	BATTLE_TOYS_API UClass* Z_Construct_UClass_AFriendlyBaseTank();
	BATTLE_TOYS_API UClass* Z_Construct_UClass_AFriendlyPawn();
	UPackage* Z_Construct_UPackage__Script_Battle_Toys();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UFloatingPawnMovement_NoRegister();
// End Cross Module References
	void AFriendlyBaseTank::StaticRegisterNativesAFriendlyBaseTank()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFriendlyBaseTank);
	UClass* Z_Construct_UClass_AFriendlyBaseTank_NoRegister()
	{
		return AFriendlyBaseTank::StaticClass();
	}
	struct Z_Construct_UClass_AFriendlyBaseTank_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CapsuleComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CapsuleComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TankPivot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TankPivot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ForwardRightWheelSensor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ForwardRightWheelSensor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ForwardLeftWheelSensor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ForwardLeftWheelSensor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BackwardRightWheelSensor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BackwardRightWheelSensor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BackwardLeftWheelSensor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BackwardLeftWheelSensor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TankHullSkeletalMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TankHullSkeletalMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TankLeftTrackMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TankLeftTrackMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TankRightTrackMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TankRightTrackMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TankTowerMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TankTowerMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TankBarrelMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TankBarrelMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileSpawnPoint_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileSpawnPoint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MovementComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MovementComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnTankTowerInterpolationSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnTankTowerInterpolationSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnRate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFriendlyBaseTank_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AFriendlyPawn,
		(UObject* (*)())Z_Construct_UPackage__Script_Battle_Toys,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * BaseFrendlyTank class\n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
		{ "ToolTip", "BaseFrendlyTank class" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_CapsuleComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Tank Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_CapsuleComponent = { "CapsuleComponent", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, CapsuleComponent), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_CapsuleComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_CapsuleComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankPivot_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Tank Pivot" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankPivot = { "TankPivot", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, TankPivot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankPivot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankPivot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ForwardRightWheelSensor_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Tank ForwardRightWheel Sensor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ForwardRightWheelSensor = { "ForwardRightWheelSensor", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, ForwardRightWheelSensor), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ForwardRightWheelSensor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ForwardRightWheelSensor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ForwardLeftWheelSensor_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Tank ForwardLeftWheel Sensor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ForwardLeftWheelSensor = { "ForwardLeftWheelSensor", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, ForwardLeftWheelSensor), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ForwardLeftWheelSensor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ForwardLeftWheelSensor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_BackwardRightWheelSensor_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Tank BackwardRightWheel Sensor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_BackwardRightWheelSensor = { "BackwardRightWheelSensor", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, BackwardRightWheelSensor), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_BackwardRightWheelSensor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_BackwardRightWheelSensor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_BackwardLeftWheelSensor_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Tank BackwardLeftWheel Sensor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_BackwardLeftWheelSensor = { "BackwardLeftWheelSensor", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, BackwardLeftWheelSensor), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_BackwardLeftWheelSensor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_BackwardLeftWheelSensor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankHullSkeletalMesh_MetaData[] = {
		{ "Category", "Tank Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankHullSkeletalMesh = { "TankHullSkeletalMesh", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, TankHullSkeletalMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankHullSkeletalMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankHullSkeletalMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankLeftTrackMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Tank Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankLeftTrackMesh = { "TankLeftTrackMesh", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, TankLeftTrackMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankLeftTrackMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankLeftTrackMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankRightTrackMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Tank Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankRightTrackMesh = { "TankRightTrackMesh", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, TankRightTrackMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankRightTrackMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankRightTrackMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankTowerMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Tank Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankTowerMesh = { "TankTowerMesh", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, TankTowerMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankTowerMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankTowerMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankBarrelMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Tank Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankBarrelMesh = { "TankBarrelMesh", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, TankBarrelMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankBarrelMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankBarrelMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ProjectileSpawnPoint_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Tank Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ProjectileSpawnPoint = { "ProjectileSpawnPoint", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, ProjectileSpawnPoint), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ProjectileSpawnPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ProjectileSpawnPoint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_MovementComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_MovementComponent = { "MovementComponent", nullptr, (EPropertyFlags)0x00400000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, MovementComponent), Z_Construct_UClass_UFloatingPawnMovement_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_MovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_MovementComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TurnTankTowerInterpolationSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TurnTankTowerInterpolationSpeed = { "TurnTankTowerInterpolationSpeed", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, TurnTankTowerInterpolationSpeed), METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TurnTankTowerInterpolationSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TurnTankTowerInterpolationSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TurnRate_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TurnRate = { "TurnRate", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFriendlyBaseTank, TurnRate), METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TurnRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TurnRate_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFriendlyBaseTank_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_CapsuleComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankPivot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ForwardRightWheelSensor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ForwardLeftWheelSensor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_BackwardRightWheelSensor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_BackwardLeftWheelSensor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankHullSkeletalMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankLeftTrackMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankRightTrackMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankTowerMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TankBarrelMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_ProjectileSpawnPoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_MovementComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TurnTankTowerInterpolationSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFriendlyBaseTank_Statics::NewProp_TurnRate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFriendlyBaseTank_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFriendlyBaseTank>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFriendlyBaseTank_Statics::ClassParams = {
		&AFriendlyBaseTank::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AFriendlyBaseTank_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFriendlyBaseTank_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFriendlyBaseTank_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFriendlyBaseTank()
	{
		if (!Z_Registration_Info_UClass_AFriendlyBaseTank.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFriendlyBaseTank.OuterSingleton, Z_Construct_UClass_AFriendlyBaseTank_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFriendlyBaseTank.OuterSingleton;
	}
	template<> BATTLE_TOYS_API UClass* StaticClass<AFriendlyBaseTank>()
	{
		return AFriendlyBaseTank::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFriendlyBaseTank);
	struct Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_FriendlyPawn_FriendlyBaseTank_FriendlyBaseTank_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_FriendlyPawn_FriendlyBaseTank_FriendlyBaseTank_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFriendlyBaseTank, AFriendlyBaseTank::StaticClass, TEXT("AFriendlyBaseTank"), &Z_Registration_Info_UClass_AFriendlyBaseTank, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFriendlyBaseTank), 2146107971U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_FriendlyPawn_FriendlyBaseTank_FriendlyBaseTank_h_1422050789(TEXT("/Script/Battle_Toys"),
		Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_FriendlyPawn_FriendlyBaseTank_FriendlyBaseTank_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Battle_Toys_Source_Battle_Toys_Public_BasePawn_FriendlyPawn_FriendlyBaseTank_FriendlyBaseTank_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
