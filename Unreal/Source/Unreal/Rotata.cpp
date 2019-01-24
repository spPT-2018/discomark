// Fill out your copyright notice in the Description page of Project Settings.

#include "Rotata.h"

// Sets default values for this component's properties
URotata::URotata()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotata::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URotata::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	auto actor = GetOwner();
	auto actorRoot = actor->GetRootComponent();
	auto rotator = FRotator{ Speed1 * DeltaTime, Speed2 * DeltaTime, Speed3 * DeltaTime };

	FHitResult hitResult;
	actorRoot->AddLocalRotation(rotator, false, &hitResult, TeleportFlagToEnum(false));
	// ...
}

