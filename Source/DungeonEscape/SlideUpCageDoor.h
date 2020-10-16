// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "SlideUpCageDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONESCAPE_API USlideUpCageDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USlideUpCageDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SlideUp();
	void SlideDown();

private:
	UPROPERTY(EditAnyWhere)
	AActor* Lkey;

	UPROPERTY(EditAnyWhere)
	ATriggerVolume* LSwitch;

	UPROPERTY(EditAnyWhere)
	ATriggerVolume* RSwitch;

	UPROPERTY(EditAnyWhere)
	AActor* Rkey;
		
};
