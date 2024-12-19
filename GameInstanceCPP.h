// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SaveSettingsCPP.h"

#include "GameInstanceCPP.generated.h"

/**
 * 
 */
UCLASS()
class SOVKOCAR2_API UGameInstanceCPP : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	int SbitoKonusov = 0;
	UPROPERTY(BlueprintReadWrite)
	float DurationTime = 0;

	UFUNCTION(BlueprintCallable)
	void UpdateTime(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void Setting(
		const int& sgAntiAliasingQuality,
		const int& sgEffectsQuality,
		const int& sgFoliageQuality,
		const int& sgGlobalIlluminationQuality,
		const int& sgPostProcessQuality,
		const int& sgReflectionQuality,
		const int& sgResolutionQuality,
		const int& sgShadingQuality,
		const int& sgShadowQuality,
		const int& sgTextureQuality,
		const int& sgViewDistanceQuality,

		const int& MotionBlurQuality,
		const int& DOFQuality,
		const int& BloomQuality,
		const int& AOQuality,

		const int& ShadowQuality,
		const int& ShadowMaxResolution,

		const int& MaxAnisotropy,
		const int& StreamingPoolSize,

		const int& DetailMode,

		const int& AntiAliasingMethod,
		const int& DynamicGlobalIlluminationMethod,
		const int& ReflectionMethod,
		const int& AOMethod,
		const bool& VolumetricCloud,

		const int& MaxFPS
	);

	UFUNCTION(BlueprintCallable)
	void SettingFromSave(USaveSettingsCPP* SS);
};
