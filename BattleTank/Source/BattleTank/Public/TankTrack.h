// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 *  TankTrack is used to set maximum driving force and to apply forces to tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float throttle);



	// Max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
		float trackMaxDrivingForce = 1330000/2; //based on 400hp on 35ton M4 Sherman

private:

	float currentThrottle = 0;

	UTankTrack();

	virtual void BeginPlay() override;
	
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;

	void ApplySidewaysForce();

	UFUNCTION(BlueprintCallable, Category = Collision)
	void OnHit(UPrimitiveComponent * hitComponent, AActor * otherActor, UPrimitiveComponent * otherComponent, FVector normalImpulse, const FHitResult & Hit);
	
	void DrivingTrack();

};
