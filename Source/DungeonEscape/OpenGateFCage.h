// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenGateFCage.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONESCAPE_API UOpenGateFCage : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenGateFCage();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenCage();
	void CloseCage();
private:
	UPROPERTY(EditAnyWhere)
	AActor* BLStatue;

	

	UPROPERTY(EditAnyWhere)
	AActor* TLStatue;



	UPROPERTY(EditAnyWhere)
	ATriggerVolume* BLPressSwitch;

	




	UPROPERTY(EditAnyWhere)
	ATriggerVolume* TLPressSwitch;

};
