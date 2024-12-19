// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/InstancedStaticMeshComponent.h"

#include "SplineOfMeshCPP.generated.h"

UCLASS()
class SOVKOCAR2_API ASplineOfMeshCPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASplineOfMeshCPP();

	UPROPERTY(EditAnywhere)
	USplineComponent* SplComp;
	UPROPERTY(EditAnywhere)
	UStaticMesh* StatMesh;

	UPROPERTY(EditAnywhere, Category = "RUina|Noise")
	FRotator NoiseRotator = { 0, 0, 0 };
	UPROPERTY(EditAnywhere, Category = "RUina|Noise")
	float NoiseLocationMax = 0;
	UPROPERTY(EditAnywhere, Category = "RUina")
	bool UseRealitySize = true;
	UPROPERTY(EditAnywhere, Category = "RUina", meta = (ClampMin = "0.01"))
	float LeghtOfMesh = 0.01;
	UPROPERTY(EditAnywhere, Category = "RUina")
	float Between = 0;

	UPROPERTY()
	UInstancedStaticMeshComponent* StatMeshCompMain;
	//TArray<UStaticMeshComponent*> MeshArr;

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

};
