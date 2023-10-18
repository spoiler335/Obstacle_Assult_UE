// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + velocity * DeltaTime);

	if (GetActorLocation().Z - startLocation.Z > maxupDistance)
	{
		velocity = -velocity;
		// startLocation = GetActorLocation();
	}
	else if (GetActorLocation().Z - startLocation.Z < -2 * maxupDistance)
	{
		velocity = -velocity;
		// startLocation = GetActorLocation();
	}
}
