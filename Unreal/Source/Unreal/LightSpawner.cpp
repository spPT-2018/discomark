// Fill out your copyright notice in the Description page of Project Settings.

#include "LightSpawner.h"

// Sets default values for this component's properties
ULightSpawner::ULightSpawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

AActor *ULightSpawner::SpawnLight(UWorld *theWorld, TSubclassOf<AActor> blueprint) {
	FTransform ComponentTransform(FQuat::Identity, FVector(FMath::RandRange(Min, Max), FMath::RandRange(Min, Max), FMath::RandRange(Min, Max)), FVector::OneVector);
	return theWorld->SpawnActor(blueprint, &ComponentTransform);
}


// Called when the game starts
void ULightSpawner::BeginPlay()
{
	Super::BeginPlay();

	UWorld *unrealWorld = GetWorld();
	if (unrealWorld == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Failed to find world in LightSpawner->BeginPlay()"));
		return;
	}

	for (size_t i = 0; i < NumberOfLights; i++)
	{
		auto light = SpawnLight(unrealWorld, LightBlueprint);
		auto rotator = Cast<URotata>(light->GetComponentByClass(TSubclassOf<URotata>()));
		rotator->Speed1 = FMath::RandRange(0.0f, 20.0f);
		rotator->Speed1 = FMath::RandRange(0.0f, 20.0f);
		rotator->Speed1 = FMath::RandRange(0.0f, 20.0f);

		auto unrealLight = Cast<USpotLightComponent>(light->GetComponentByClass(USpotLightComponent::StaticClass()));
		if (unrealLight->IsValidLowLevel()) {
			unrealLight->LightColor = FColor::MakeRandomColor();
			unrealLight->OuterConeAngle = FMath::RandRange(0.0f, 30.0f);
		}
	}
	
}

