// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	bool IsAtMaxDistance() const;

private:
	UPROPERTY(EditAnywhere)
	FVector velocity = FVector();
	UPROPERTY(EditAnywhere)
	FRotator rotationalVelocity = FRotator();

private:
	FVector startLocation;

private:
	UPROPERTY(EditAnywhere)
	int32 maxDistance = 500;
};