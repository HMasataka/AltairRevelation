// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Components/PointLightComponent.h"
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
	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	const float Duration = 10.0f;
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

public:
	UPROPERTY(EditAnyWhere)
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	UPROPERTY(EditAnyWhere)
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UArrowComponent> Arrow;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UPointLightComponent> PointLight;

	UPROPERTY(EditAnyWhere, Category = "Point Light")
	bool bIsVisible = false;

	UPROPERTY(EditAnyWhere, Category = "Point Light")
	float Intensity = 5000.0f;

	UPROPERTY(EditAnyWhere, Category = "Point Light")
	FLinearColor LightColor = FLinearColor::White;
};
