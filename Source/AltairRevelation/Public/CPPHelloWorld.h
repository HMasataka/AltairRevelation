// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPHelloWorld.generated.h"

UCLASS()
class ACPPHelloWorld : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPHelloWorld();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	const float Duration = 10.0f;
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);
};
