// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicOrb.h"

// Sets default values
AMagicOrb::AMagicOrb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OrbSpeed = 5.f;
	LifeDuration = 1.f;
	OrbDamage = 25;
}

// Called when the game starts or when spawned
void AMagicOrb::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(DestroyOrbHandle, this, &AMagicOrb::DestroyOrb, LifeDuration);
}

// Called every frame
void AMagicOrb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector offset = this->GetActorForwardVector() * OrbSpeed;
	this->SetActorLocation(this->GetActorLocation() + offset);
}

void AMagicOrb::DestroyOrb()
{
	this->Destroy();
}