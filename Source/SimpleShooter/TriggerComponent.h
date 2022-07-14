// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "TriggerComponent.generated.h"
/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SIMPLESHOOTER_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	UTriggerComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName AcceptableActorTag = "Unlock";
	// UFUNCTION(BlueprintCallable)
	// void SetRotatingMover(class URotatingMovementComponent *RotatingMover);
private:


	// UPROPERTY(EditAnywhere)
	// TSubclassOf<AMovableDoor> MovableDoorClass;

	// class URotatingMovementComponent *RotatingMover;
};
