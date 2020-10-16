// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "Hand.h"

// Sets default values for this component's properties
UHand::UHand()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHand::BeginPlay()
{
	Super::BeginPlay();

	Handle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (Handle)
	{
		UE_LOG(LogTemp, Warning, TEXT("Handler found"));
	}

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found"));
		InputComponent->BindAction("Grab", IE_Pressed, this, &UHand::GrabPressed);
		InputComponent->BindAction("Grab", IE_Released, this, &UHand::GrabReleased);
	}
	else

	{
		UE_LOG(LogTemp, Warning, TEXT("Not Found"));
	}

	
	
}


// Called every frame
void UHand::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	LineTrace();

	if (Handle->GrabbedComponent)
	{
		Handle->SetTargetLocation(LineTraceEnd);
	}


}


void UHand::LineTrace()
{
	 

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerLocation, PlayerRotation);

	//UE_LOG(LogTemp, Warning, TEXT("Current player location %s current player rotation %s"), *PlayerLocation.ToString(), *PlayerRotation.ToString());

	 LineTraceEnd = PlayerLocation + PlayerRotation.Vector() * Reach;

	 DrawDebugLine(GetWorld(), PlayerLocation, LineTraceEnd, FColor(0, 255, 0), false, 0.0f, 0, 5.0f);

	

	FCollisionQueryParams TraceParam(FName(TEXT(" ")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(Hit, PlayerLocation, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParam);

	AActor* HitActor = Hit.GetActor();

	if (HitActor)
	{
		UE_LOG(LogTemp,Warning,TEXT("Grabbed %s"),*HitActor->GetActorLabel())
	}

	

	
}

void UHand::GrabPressed()
{
	UPrimitiveComponent* ComponentGrabbed = Hit.GetComponent();


	Handle->GrabComponentAtLocation(ComponentGrabbed,NAME_None,LineTraceEnd);
	
}


void UHand::GrabReleased()
{
	Handle->ReleaseComponent();
}
