// Fill out your copyright notice in the Description page of Project Settings.
#include "TriggerComponent.h"
#include "DoorRotatorComponent.h"
UTriggerComponent::UTriggerComponent(){
    PrimaryComponentTick.bCanEverTick = true;
}
void UTriggerComponent::BeginPlay() {
    Super::BeginPlay();
}
// void UTriggerComponent::SetRotatingMover(class URotatingMovementComponent* NewMover) {
//     RotatingMover = NewMover;
// }

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    // TArray<AActor*> Actors;
    // GetOverlappingActors(Actors);
    // for (AActor *Actor : Actors) {
    //     if (Actor->ActorHasTag(AcceptableActorTag)) {
    //         // MovableDoorClass->DoorRotatorComponent->StartRotating = true;
    //     }
    // }
}
