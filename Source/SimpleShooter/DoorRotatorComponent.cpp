// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorRotatorComponent.h"
UDoorRotatorComponent::UDoorRotatorComponent() {
    PrimaryComponentTick.bCanEverTick = true;
    StartMove = false;
    RotationRate.Yaw = 0;
}
void UDoorRotatorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    // UE_LOG(LogTemp, Warning, TEXT("StartMove:%d"),StartMove);
    if(!StartMove) return;
    FRotator Rotator = GetOwner()->GetActorRotation();
    if (DegreeLimit <= 0 && Rotator.Yaw < DegreeLimit) {
        RotationRate.Yaw = YawSpeed;
    } else if (DegreeLimit > 0 && Rotator.Yaw > DegreeLimit) {
        RotationRate.Yaw = YawSpeed;
    }
    
    if (DegreeLimit <= 0 && Rotator.Yaw >= DegreeLimit) {
        RotationRate.Yaw = 0;
    } else if (DegreeLimit > 0 && Rotator.Yaw <= DegreeLimit) {
        RotationRate.Yaw = 0;
    }
}
