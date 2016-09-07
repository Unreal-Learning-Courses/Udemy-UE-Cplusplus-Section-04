// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	collisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(collisionMesh);
	collisionMesh->SetNotifyRigidBodyCollision(true);
	collisionMesh->SetVisibility(false);

	launchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Launch Blast"));
	//launchBlast->AttachTo(RootComponent);
	//launchBlast->SetupAttachment(RootComponent);
	launchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Movement Component"));
	projectileMovement->bAutoActivate = false;

	impactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Impact Blast"));
	//impactBlast->SetupAttachment(RootComponent);
	launchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	impactBlast->bAutoActivate = false;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	collisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	
}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AProjectile::LaunchProjectile(float launchSpeed)
{
	//UE_LOG(LogTemp, Warning, TEXT("Projectile Launched!"));

	projectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * launchSpeed);
	projectileMovement->Activate();
}

void AProjectile::OnHit(UPrimitiveComponent * hitComponent, AActor * otherActor, UPrimitiveComponent * otherComponent, FVector normalImpulse, const FHitResult & Hit)
{
	launchBlast->Deactivate();
	impactBlast->Activate(true);


}

