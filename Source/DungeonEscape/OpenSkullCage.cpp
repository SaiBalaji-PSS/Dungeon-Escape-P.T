// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenSkullCage.h"

// Sets default values for this component's properties
UOpenSkullCage::UOpenSkullCage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenSkullCage::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOpenSkullCage::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (switchskullcage->IsOverlappingActor(SkullKey))
	{

		OpenSCage();
	}

	else if (!switchskullcage->IsOverlappingActor(SkullKey))
	{
		CloseSCage();
	}

}

void UOpenSkullCage::OpenSCage()
{
	FRotator openskullcage = FRotator(0.0f, 0.0f, 0.0f);

	float currentyaw = GetOwner()->GetActorRotation().Yaw;

	openskullcage.Yaw = FMath::Lerp(currentyaw,180.0f, 0.2f);

	GetOwner()->SetActorRotation(openskullcage);
}

void UOpenSkullCage::CloseSCage()
{
	FRotator openskullcage = FRotator(0.0f, 0.0f, 0.0f);

	float currentyaw = GetOwner()->GetActorRotation().Yaw;

	openskullcage.Yaw = FMath::Lerp(currentyaw, 90.0f, 0.2f);

	GetOwner()->SetActorRotation(openskullcage);
}

