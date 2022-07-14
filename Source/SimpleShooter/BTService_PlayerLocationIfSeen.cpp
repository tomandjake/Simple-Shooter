// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfSeen.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterAIController.h"
#include "GameFramework/Pawn.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
    NodeName = "Update Player Location If Seen";
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
    // AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
    AShooterAIController* Controller = Cast<AShooterAIController>(OwnerComp.GetAIOwner());
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if(Controller == nullptr) {
        // UE_LOG(LogTemp, Warning, TEXT("Controller is nullptr"));
        return;
    }
    if (PlayerPawn == nullptr) {
        // UE_LOG(LogTemp, Warning, TEXT("PlayerPawn is nullptr"));
        return;
    }
    if (Controller->LineOfSightTo(PlayerPawn)) {
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);    
    } else {
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());    
    }
}
