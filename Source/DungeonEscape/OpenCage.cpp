// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenCage.h"

// Sets default values for this component's properties
UOpenCage::UOpenCage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenCage::BeginPlay()
{
	Super::BeginPlay();

	// ...

	if (Trigger)
	{
		UE_LOG(LogTemp, Warning, TEXT("Got switch"));
	}

	//Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	
}


// Called every frame
void UOpenCage::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Trigger->IsOverlappingActor(GargoyoleCageKey))
	{
		openCage();
	}

	else if(!Trigger->IsOverlappingActor(GargoyoleCageKey))
	{
		closeCage();
	}

	

	// ...
}

void UOpenCage::openCage()
{
	FRotator opencageyaw = FRotator(0.0f, 0.0f, 0.0f);

	float currentyaw = GetOwner()->GetActorRotation().Yaw;

	opencageyaw.Yaw = FMath::Lerp(currentyaw, TargetYaw, 0.2f);

	GetOwner()->SetActorRotation(opencageyaw);
}


void UOpenCage::closeCage()
{
	FRotator opencageyaw = FRotator(0.0f, 0.0f, 0.0f);

	float currentyaw = GetOwner()->GetActorRotation().Yaw;

	opencageyaw.Yaw = FMath::Lerp(currentyaw, 0.0f, 0.2f);

	GetOwner()->SetActorRotation(opencageyaw);
}

