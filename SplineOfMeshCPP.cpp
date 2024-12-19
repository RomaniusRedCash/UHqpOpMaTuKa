// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineOfMeshCPP.h"

// Sets default values
ASplineOfMeshCPP::ASplineOfMeshCPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	SplComp = CreateDefaultSubobject<USplineComponent>("Spline");
	SetRootComponent(SplComp);

	//SplComp->SetMobility(EComponentMobility::Static);
	RootComponent->SetMobility(EComponentMobility::Static);
}

void ASplineOfMeshCPP::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (StatMesh)
	{
		StatMeshCompMain = NewObject<UInstancedStaticMeshComponent>(this, "ISMMain");
		StatMeshCompMain->SetMobility(EComponentMobility::Static);
		StatMeshCompMain->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		StatMeshCompMain->SetStaticMesh(StatMesh);
		StatMeshCompMain->CreationMethod = EComponentCreationMethod::UserConstructionScript;
		StatMeshCompMain->RegisterComponent();
		//StatMeshCompMain->SetMobility(EComponentMobility::Static);
		//AddInstanceComponent(StatMeshCompMain);

		TArray<FTransform> TransArr;

		if (UseRealitySize)
			LeghtOfMesh = StatMesh->GetBounds().GetBox().GetSize().X;

		int Kolvo = SplComp->GetSplineLength() / (LeghtOfMesh + Between);

		for (int i = 0; i < Kolvo; i++)
		{
			FRotator RandNoiseRotation = FRotator(
				FMath::FRandRange(-NoiseRotator.Pitch, NoiseRotator.Pitch),
				FMath::FRandRange(-NoiseRotator.Yaw, NoiseRotator.Yaw),
				FMath::FRandRange(-NoiseRotator.Roll, NoiseRotator.Roll)
			);

			TransArr.Add(FTransform(
				SplComp->GetRotationAtDistanceAlongSpline(i * (LeghtOfMesh + Between), ESplineCoordinateSpace::Local) + RandNoiseRotation,
				SplComp->GetLocationAtDistanceAlongSpline(i * (LeghtOfMesh + Between) + FMath::FRandRange(0, NoiseLocationMax), ESplineCoordinateSpace::Local),
				FVector(1, 1, 1)
			));
		}
		StatMeshCompMain->AddInstances(TransArr, false);
	}
}

/*void ASplineOfMeshCPP::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	MeshArr.Empty();

	if (StatMesh)
	{
		LeghtOfMesh = StatMesh->GetBounds().GetBox().GetSize().X;

		int Kolvo = SplComp->GetSplineLength() / (LeghtOfMesh + Between);

		for (int i = 0; i < Kolvo; i++)
		{
			UStaticMeshComponent* NewStatMeshComp = NewObject<UStaticMeshComponent>(this, FName("StatMeshComp" + FString::FromInt(i + 1)));
			
			NewStatMeshComp->RegisterComponent();
			NewStatMeshComp->CreationMethod = EComponentCreationMethod::UserConstructionScript;
			NewStatMeshComp->SetStaticMesh(StatMesh);
			NewStatMeshComp->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
			NewStatMeshComp->SetRelativeLocation(SplComp->GetLocationAtDistanceAlongSpline(i * (LeghtOfMesh + Between), ESplineCoordinateSpace::Local));
			NewStatMeshComp->SetRelativeRotation(SplComp->GetRotationAtDistanceAlongSpline(i * (LeghtOfMesh + Between), ESplineCoordinateSpace::Local));
		}
	}
}*/

