// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Hand.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONESCAPE_API UHand : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHand();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void LineTrace();
	void GrabPressed();
	void GrabReleased();

private:
	float Reach = 200.0f;

	UPhysicsHandleComponent* Handle = nullptr;
	UInputComponent* InputComponent = nullptr;
	FVector LineTraceEnd;
	FHitResult Hit;
	FVector PlayerLocation;
	FRotator PlayerRotation;

		
};
