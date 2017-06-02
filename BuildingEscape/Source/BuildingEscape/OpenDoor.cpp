// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
   bDoorOpen = false;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
   TriggerActor = GetWorld()->GetFirstPlayerController()->GetPawn();
   
   //This now works, remember the iterator is a controller and you still need to get the pawn!
   /*UE_LOG(LogTemp, Warning, TEXT("Total player controllers is %i"),GetWorld()->PlayerNum);
   for (FConstPlayerControllerIterator ControllerIterator = GetWorld()->GetPlayerControllerIterator(); ControllerIterator; ++ControllerIterator) {
       UE_LOG(LogTemp, Warning, TEXT("Found player controller"));
       APlayerController* PlayerController = *ControllerIterator;
       if (PlayerController->IsLocalPlayerController()) UE_LOG(LogTemp, Warning, TEXT("Server Found"));
       if (PlayerController==GetWorld()->GetFirstPlayerController()) UE_LOG(LogTemp, Warning, TEXT("First player controller is the controller we found"));
       if (PlayerController)
       {
           UE_LOG(LogTemp, Warning, TEXT("Assigned a trigger actor"));
           TriggerActor = PlayerController->GetPawn();
       }
   }*/
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
   if (PressurePlate->IsOverlappingActor(TriggerActor)) OpenDoor();
   else CloseDoor();
}

void UOpenDoor::OpenDoor()
{
    if (bDoorOpen) return;
    //Get owner
    AActor* Owner = GetOwner();
    //Get a rotator, these are super useful as quats are shit and this uses degrees, yaaaay!
    FRotator NewRotation = FRotator(0.0f, -OpenAngle, 0.0f);
    //Set rotation
    Owner->SetActorRotation(NewRotation);
    bDoorOpen = true;
}

void UOpenDoor::CloseDoor()
{
    if (!bDoorOpen) return;
    //Get owner
    AActor* Owner = GetOwner();
    //Get a rotator, these are super useful as quats are shit and this uses degrees, yaaaay!
    FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);
    //Set rotation
    Owner->SetActorRotation(NewRotation);
    bDoorOpen = false;
}