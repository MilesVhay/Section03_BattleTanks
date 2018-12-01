// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerConroller BeginPlay"));
	
	auto ControlledTank = GetControlledTank();
	
	
	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("No possessed tank"));
	}
	else {
		
		UE_LOG(LogTemp, Warning, TEXT("Possessed Tank: %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime) {
	
	Super::Tick(DeltaTime);


	AimTowardsCrosshair();
	
		
		return;
}


ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	
	if (!GetControlledTank()) { return; }




	FVector HitLocation; //out parameter
	


	if (GetSightRayLocation(HitLocation)) { // has side-effect of a ray trace
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());

	
	}
		//TODO tell controlled tank to aim at that point
	return;
}


//get world location of linetrace through crosshair, true if hits the landscape
bool ATankPlayerController::GetSightRayLocation( FVector &OutHitLocation ) const {

	OutHitLocation = FVector(1.0);

	return true;
}
