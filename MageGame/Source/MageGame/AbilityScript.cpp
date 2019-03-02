// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilityScript.h"
#include "Engine/GameEngine.h"

// Sets default values
AAbilityScript::AAbilityScript()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAbilityScript::BeginPlay()
{
	Super::BeginPlay();
	
	VMValue test(VM_INT, 3);

	callStack.push(test);

	PrimaryActorTick.bCanEverTick = true;
}

// Called every frame
void AAbilityScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	int32 test1 = 0;
	int32 test2 = 1;

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, *FString::Printf(TEXT("TEST %i"), callStack.top().value.intValue));
}
