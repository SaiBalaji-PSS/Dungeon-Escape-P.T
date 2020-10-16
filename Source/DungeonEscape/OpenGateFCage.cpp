// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenGateFCage.h"

// Sets default values for this component's properties
UOpenGateFCage::UOpenGateFCage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenGateFCage::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOpenGateFCage::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (BLPressSwitch->IsOverlappingActor(BLStatue)&& TLPressSwitch->IsOverlappingActor(TLStatue) )
	{
		OpenCage();
	}

	// ...
}

void UOpenGateFCage::OpenCage()
{
	FRotator openskullcage = FRotator(0.0f, 0.0f, 0.0f);

	float currentyaw = GetOwner()->GetActorRotation().Yaw;

	openskullcage.Yaw = FMath::Lerp(currentyaw, -180.0f, 0.2f);

	GetOwner()->SetActorRotation(openskullcage);
}

