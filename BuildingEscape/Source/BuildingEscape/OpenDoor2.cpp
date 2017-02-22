// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "OpenDoor2.h"


// Sets default values for this component's properties
UOpenDoor2::UOpenDoor2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor2::BeginPlay()
{
	Super::BeginPlay();
	//GetOwner()->SetActorRotation(FRotator(0.f, 90.f, 0.f));

	// ...
	
}


// Called every frame
void UOpenDoor2::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	
	if (!PressurePlate2) { return; }
	
	TArray<AActor*> OverlappingActors2;
	PressurePlate2->GetOverlappingActors(OUT OverlappingActors2);
	for (const auto& Actor : OverlappingActors2)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is on preessure plate"), *Actor->GetName());
		if (Actor->GetName() == "Cube2") {
			GetOwner()->SetActorRotation(FRotator(0.f, 90.f, 0.f));
		}
	}
	
}

