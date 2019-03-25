// Fill out your copyright notice in the Description page of Project Settings.

#include "VirtualMachine.h"

// Sets default values
AVirtualMachine::AVirtualMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVirtualMachine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVirtualMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AVirtualMachine::VMAdd(float lhs, float rhs)
{
	return lhs + rhs;
}


