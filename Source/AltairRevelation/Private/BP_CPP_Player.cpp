// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_CPP_Player.h"

// Sets default values
ABP_CPP_Player::ABP_CPP_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABP_CPP_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_CPP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABP_CPP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}