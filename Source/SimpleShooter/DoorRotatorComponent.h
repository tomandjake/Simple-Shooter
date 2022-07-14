// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "DoorRotatorComponent.generated.h"

/**
 * 
 */

UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SIMPLESHOOTER_API UDoorRotatorComponent : public URotatingMovementComponent
{
	GENERATED_BODY()
public:
	UDoorRotatorComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool StartMove;
private:
	UPROPERTY(EditInstanceOnly)
	float DegreeLimit;
	UPROPERTY(EditInstanceOnly)
	float YawSpeed;
};
