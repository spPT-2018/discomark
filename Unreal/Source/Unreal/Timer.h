// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include <FileHelper.h>
#include <PlatformFilemanager.h>
#include <PlatformFile.h>
#include <string>
#include <chrono>
#include "Timer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_API UTimer : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTimer();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	int iterations;
	long long lastTimestamp;
		
};
