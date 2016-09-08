// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditDefaultsOnly, Category = firing)
		float alphaDamage = 20;


	// Sets default values for this actor's properties
	AProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void LaunchProjectile(float launchSpeed);



private:

	/// variables

	UProjectileMovementComponent* projectileMovement = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
		UStaticMeshComponent* collisionMesh = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = Components)
		UParticleSystemComponent* launchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
		UParticleSystemComponent* impactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
		URadialForceComponent* explosionForce = nullptr;
	
	UPROPERTY(EditDefaultsOnly,Category = Timer)
		float destroyDelay = 5;
	
	
	/// functions

	UFUNCTION(BlueprintCallable, Category = Collision)
		void OnHit(UPrimitiveComponent * hitComponent, AActor * otherActor, UPrimitiveComponent * otherComponent, FVector normalImpulse, const FHitResult & Hit);

	void OnTimesUp();


	
};
