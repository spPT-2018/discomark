// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Rotata.h"
#include "Runtime/Engine/Classes/Components/SpotLightComponent.h"
#include "Runtime/Engine/Classes/GameFramework/RotatingMovementComponent.h"
#include "LightSpawner.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_API ULightSpawner : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULightSpawner();
	UPROPERTY(EditAnywhere)
		int NumberOfLights;
	UPROPERTY(EditAnywhere)
		float Min;
	UPROPERTY(EditAnywhere)
		float Max;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> LightBlueprint;

private:
	AActor *SpawnLight(UWorld *theWorld, TSubclassOf<AActor> blueprint);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
