// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorOpen.h"

// Sets default values for this component's properties
UDoorOpen::UDoorOpen()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorOpen::BeginPlay()
{
	Super::BeginPlay();

	Hero = GetWorld()->GetFirstPlayerController()->GetPawn();

	// ...
	
}


// Called every frame
void UDoorOpen::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (OpenSwitch->IsOverlappingActor(Hero))
	{
		FRotator OpenDoor = FRotator(0.0f, 0.0f, 0.0f);

		float CurrentYaw = GetOwner()->GetActorRotation().Yaw;

		OpenDoor.Yaw = FMath::Lerp(CurrentYaw, -180.0f, 0.2f);

		GetOwner()->SetActorRotation(OpenDoor);
	}


	

	



	
}

