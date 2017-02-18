// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "OpenDoor.h"
#define OUT


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
	//Open Door when the total mass of actor on the pressure plate is bigger than 30kg
	if (GetTotalMassOfActorsOnPlate() > 30.f) 
	{
		OpenDoor();
	}
	if ((LastDoorOpenTime + DoorCloseDelay) < GetWorld()->GetTimeSeconds()) 
	{
		CloseDoor();
	}
}

//Open Door
void UOpenDoor::OpenDoor()
{
	GetOwner()->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
	LastDoorOpenTime = GetWorld()->GetTimeSeconds();
}

//Close Door
void UOpenDoor::CloseDoor()
{
	GetOwner()->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}

float UOpenDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMassOnPlate = 0.f;
	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	for (const auto& Actor : OverlappingActors)
	{
		TotalMassOnPlate += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s is on preessure plate"), *Actor->GetName());
	}
	return TotalMassOnPlate;
}








