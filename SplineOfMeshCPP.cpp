// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineOfMeshCPP.h"


ASplineOfMeshCPP::ASplineOfMeshCPP()
{


	SplComp = CreateDefaultSubobject<USplineComponent>("Spline");
	SetRootComponent(SplComp);


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

