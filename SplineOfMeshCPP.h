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



//Анша Абдуль!


protected:


	virtual void OnConstruction(const FTransform& Transform) override;

public:	


};
