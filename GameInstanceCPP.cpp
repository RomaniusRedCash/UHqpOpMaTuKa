// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstanceCPP.h"

void UGameInstanceCPP::UpdateTime(float DeltaTime)
{
	DurationTime += DeltaTime;
}
// АХАХАХАХАХАХ ЩА ВСЁ УДАЛЮ!!!!!

void UGameInstanceCPP::Setting(
	//const bool& bShowFPS,
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
	)
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("sg.AntiAliasingQuality " + FString::FromInt(sgAntiAliasingQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("sg.EffectsQuality " + FString::FromInt(sgEffectsQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("sg.FoliageQuality " + FString::FromInt(sgFoliageQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("sg.GlobalIlluminationQuality " + FString::FromInt(sgGlobalIlluminationQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("sg.PostProcessQuality " + FString::FromInt(sgPostProcessQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("sg.ReflectionQuality " + FString::FromInt(sgReflectionQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("sg.ResolutionQuality " + FString::FromInt(sgResolutionQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("sg.ShadingQuality " + FString::FromInt(sgShadingQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("sg.ShadowQuality " + FString::FromInt(sgShadowQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("sg.TextureQuality " + FString::FromInt(sgTextureQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("sg.ViewDistanceQuality " + FString::FromInt(sgViewDistanceQuality));


	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.MotionBlurQualit " + FString::FromInt(MotionBlurQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.DepthOfFieldQuality " + FString::FromInt(DOFQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.BloomQuality " + FString::FromInt(BloomQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.AOQuality " + FString::FromInt(AOQuality));

	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.ShadowQuality " + (ShadowQuality));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.Shadow.MaxResolution " + (ShadowMaxResolution));

	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.MaxAnisotropy " + FString::FromInt(MaxAnisotropy));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.Streaming.PoolSize " + FString::FromInt(StreamingPoolSize));
	
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.DetailMode " + FString::FromInt(DetailMode));

	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.AntiAliasingMethod " + FString::FromInt(AntiAliasingMethod));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.DynamicGlobalIlluminationMethod " + FString::FromInt(DynamicGlobalIlluminationMethod));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.ReflectionMethod " + FString::FromInt(ReflectionMethod));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.AmbientOcclusion.Method " + FString::FromInt(AOMethod));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("r.VolumetricCloud " + FString::FromInt(VolumetricCloud));
	
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("t.MaxFPS " + FString::FromInt(MaxFPS));
}

void UGameInstanceCPP::SettingFromSave(USaveSettingsCPP* SS)
{
	Setting(
		SS->sgAntiAliasingQuality,
		SS->sgEffectsQuality,
		SS->sgFoliageQuality,
		SS->sgGlobalIlluminationQuality,
		SS->sgPostProcessQuality,
		SS->sgReflectionQuality,
		SS->sgResolutionQuality,
		SS->sgShadingQuality,
		SS->sgShadowQuality,
		SS->sgTextureQuality,
		SS->sgViewDistanceQuality,

		SS->MotionBlurQuality,
		SS->DOFQuality,
		SS->BloomQuality,
		SS->AOQuality,

		SS->ShadowQuality,
		SS->ShadowMaxResolution,

		SS->MaxAnisotropy,
		SS->StreamingPoolSize,

		SS->DetailMode,

		SS->AntiAliasingMethod,
		SS->DynamicGlobalIlluminationMethod,
		SS->ReflectionMethod,
		SS->AOMethod,
		SS->VolumetricCloud,

		SS->MaxFPS
	);
}

/*GetWorld()->Exec(GetWorld(), *FString("sg.PostProcessQuality " + PostProcessQuality));
	GetWorld()->Exec(GetWorld(), *FString("r.ScreenPercentage " + ScreenPercentage));
	GetWorld()->Exec(GetWorld(), *FString("r.MotionBlurQualit " + MotionBlurQuality));
	GetWorld()->Exec(GetWorld(), *FString("r.DepthOfFieldQuality " + DOFQuality));
	GetWorld()->Exec(GetWorld(), *FString("r.BloomQuality " + BloomQuality));
	GetWorld()->Exec(GetWorld(), *FString("r.AOQuality " + AOQuality));
	GetWorld()->Exec(GetWorld(), *FString("r.AmbientOcclusion.Method " + AOMethod));

	GetWorld()->Exec(GetWorld(), *FString("r.ShadowQuality " + ShadowQuality));
	GetWorld()->Exec(GetWorld(), *FString("r.Shadow.MaxResolution " + ShadowMaxResolution));

	GetWorld()->Exec(GetWorld(), *FString("sg.TextureQuality " + TextureQuality));
	GetWorld()->Exec(GetWorld(), *FString("r.MaxAnisotropy " + MaxAnisotropy));
	GetWorld()->Exec(GetWorld(), *FString("r.Streaming.PoolSize " + StreamingPoolSize));

	GetWorld()->Exec(GetWorld(), *FString("sg.EffectsQuality " + EffectsQuality));
	GetWorld()->Exec(GetWorld(), *FString("r.DetailMode " + DetailMode));

	GetWorld()->Exec(GetWorld(), *FString("r.AntiAliasingMethod " + AntiAliasingMethod));
	GetWorld()->Exec(GetWorld(), *FString("r.DynamicGlobalIlluminationMethod " + DynamicGlobalIlluminationMethod));
	GetWorld()->Exec(GetWorld(), *FString("r.ReflectionMethod " + ReflectionMethod));*/
