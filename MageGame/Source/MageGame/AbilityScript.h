// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VMValue.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilityScript.generated.h"

UCLASS()
class MAGEGAME_API AAbilityScript : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbilityScript();

	UPROPERTY(EditAnywhere, Category = "Test")
	int testInt;

	UPROPERTY(EditAnywhere)
	FVMValue testVal;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};