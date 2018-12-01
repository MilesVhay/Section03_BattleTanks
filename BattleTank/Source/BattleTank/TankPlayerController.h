// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be last # include



UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	

	//starts moving the barrel towards crosshair, so that a shot
	//would hit where the crosshair intersects with the world
	void AimTowardsCrosshair();

private:
	bool GetSightRayLocation(FVector &OutHitLocation) const;

};
