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
	UE_LOG(LogTemp, Display, TEXT("MovingPlatform :: BeginPlay() :: name = %s"), *GetName());
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float deltaTime)
{
	FVector currentLocation = GetActorLocation();
	currentLocation += velocity * deltaTime;
	SetActorLocation(currentLocation);
	if (IsAtMaxDistance())
	{
		FVector direction = velocity.GetSafeNormal();
		startLocation += direction * maxDistance;
		SetActorLocation(startLocation);
		velocity = -velocity;
	}
}

void AMovingPlatform::RotatePlatform(float deltaTime)
{
	AddActorLocalRotation(rotationalVelocity * deltaTime);	
}

bool AMovingPlatform::IsAtMaxDistance() const
{
	float distance = FVector::Dist(startLocation, GetActorLocation());
	return distance > maxDistance;
}