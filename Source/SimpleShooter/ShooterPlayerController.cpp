// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay()
{
    Super::BeginPlay();
    HUD = CreateWidget(this, Crosshair);
    if (HUD != nullptr) {
        HUD->AddToViewport();
    }
}

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus,bIsWinner);
    HUD->RemoveFromViewport();
    // UE_LOG(LogTemp, Warning, TEXT("We have finished."));
    if (bIsWinner) {
        auto WinScreen = CreateWidget(this, WinScreenClass);
        if (WinScreen != nullptr) {
            WinScreen->AddToViewport();
        }
    } else {
        auto LoseScreen = CreateWidget(this, LoseScreenClass);
        if (LoseScreen != nullptr) {
            LoseScreen->AddToViewport();
        }
    }
    GetWorldTimerManager().SetTimer(RestartTimer, this,
                                    &APlayerController::RestartLevel,RestartDelay);
}
