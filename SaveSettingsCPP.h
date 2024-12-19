// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveSettingsCPP.generated.h"

/**
 * 
 */
UCLASS()
class SOVKOCAR2_API USaveSettingsCPP : public USaveGame
{
	GENERATED_BODY()
	
public:
	//UPROPERTY(BlueprintReadWrite) bool bShowFPS = false;

	UPROPERTY(BlueprintReadWrite) int sgAntiAliasingQuality = 2;
	UPROPERTY(BlueprintReadWrite) int sgEffectsQuality = 2;
	UPROPERTY(BlueprintReadWrite) int sgFoliageQuality = 2;
	UPROPERTY(BlueprintReadWrite) int sgGlobalIlluminationQuality = 2;
	UPROPERTY(BlueprintReadWrite) int sgPostProcessQuality = 2;
	UPROPERTY(BlueprintReadWrite) int sgReflectionQuality = 2;
	UPROPERTY(BlueprintReadWrite) int sgResolutionQuality = 100;
	UPROPERTY(BlueprintReadWrite) int sgShadingQuality = 2;
	UPROPERTY(BlueprintReadWrite) int sgShadowQuality = 2;
	UPROPERTY(BlueprintReadWrite) int sgTextureQuality = 2;
	UPROPERTY(BlueprintReadWrite) int sgViewDistanceQuality = 2;

	UPROPERTY(BlueprintReadWrite) int MotionBlurQuality = 0;
	UPROPERTY(BlueprintReadWrite) int DOFQuality = 2;
	UPROPERTY(BlueprintReadWrite) int BloomQuality = 5;
	UPROPERTY(BlueprintReadWrite) int AOQuality = 1;

	UPROPERTY(BlueprintReadWrite) int ShadowQuality = 2;
	UPROPERTY(BlueprintReadWrite) int ShadowMaxResolution;

	UPROPERTY(BlueprintReadWrite) int MaxAnisotropy = 4;
	UPROPERTY(BlueprintReadWrite) int StreamingPoolSize = 700;
	
	UPROPERTY(BlueprintReadWrite) int DetailMode = 2;

	UPROPERTY(BlueprintReadWrite) int AntiAliasingMethod = 0;
	UPROPERTY(BlueprintReadWrite) int DynamicGlobalIlluminationMethod = 0;
	UPROPERTY(BlueprintReadWrite) int ReflectionMethod = 0;
	UPROPERTY(BlueprintReadWrite) int AOMethod = 0;
	UPROPERTY(BlueprintReadWrite) bool VolumetricCloud = 1;

	UPROPERTY(BlueprintReadWrite) int MaxFPS = -1;
};
