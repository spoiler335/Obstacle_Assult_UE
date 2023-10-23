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

	FVector currentLocation = GetActorLocation();
	currentLocation += velocity * DeltaTime;
	SetActorLocation(currentLocation);
	float distance = FVector::Dist(startLocation, currentLocation);
	if (distance > maxDistance)
	{
		FVector direction = velocity.GetSafeNormal();
		startLocation += direction * maxDistance;
		SetActorLocation(startLocation);
		velocity = -velocity;
	}
}
