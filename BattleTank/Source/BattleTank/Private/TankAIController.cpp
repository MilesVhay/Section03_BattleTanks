// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {

	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AI controller active"));

	auto PlayerTank = GetPlayerTank();


	if (!PlayerTank) {UE_LOG(LogTemp, Error, TEXT("No possessing AI found"))} //Checks if returned a tank value
	else {//If controlled tank could be found
		UE_LOG(LogTemp, Warning, TEXT("Possessed Tank: %s"), *PlayerTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	//Check if player tank is found
	if (!PlayerPawn) {
		return nullptr;
	}


	return Cast<ATank>(PlayerPawn);

}

