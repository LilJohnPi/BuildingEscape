// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "Grabber.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

   UE_LOG(LogTemp, Log,TEXT("Grabber reporting for duty!"));
   PlayerController = GetWorld()->GetFirstPlayerController();
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Get the player viewpoint this tick
   FVector PlayerLocation;
   FRotator PlayerRotation;

   PlayerController->GetPlayerViewPoint(PlayerLocation, PlayerRotation);

   //FString PlayerLocationString = PlayerLocation.ToString();
   //FString PlayerRotationString = PlayerRotation.ToString();

   //UE_LOG(LogTemp, Log, TEXT("Player view : Location: %s  Rotation: %s"), *PlayerLocationString, *PlayerRotationString);

   //Draw a red trace in the world to visualise
   FVector LineTraceEnd = PlayerLocation + (PlayerRotation.Vector() * GrabDistanceMultiplier);
   DrawDebugLine(GetWorld(), PlayerLocation, LineTraceEnd, FColor(255, 0, 0), false, -1.0f, 0, 1.0f);

   // Ray-cast out to reach distance

   //See what we hit

}

