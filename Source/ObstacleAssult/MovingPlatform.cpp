// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startLocation = GetActorLocation();
}

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
