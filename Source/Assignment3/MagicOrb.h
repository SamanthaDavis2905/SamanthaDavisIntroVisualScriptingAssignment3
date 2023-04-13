// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MagicOrb.generated.h"

UCLASS()
class ASSIGNMENT3_API AMagicOrb : public AActor
{
	GENERATED_BODY()

	FTimerHandle DestroyOrbHandle;
	
public:	
	// Sets default values for this actor's properties
	AMagicOrb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, Category = Orb)
	float OrbSpeed;

	UPROPERTY(EditAnywhere, Category = Orb)
	float LifeDuration;

	UPROPERTY(EditAnywhere, Category = Orb)
	int OrbDamage;

private:
	void DestroyOrb();
};
