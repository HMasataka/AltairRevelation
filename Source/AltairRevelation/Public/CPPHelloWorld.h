// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CPPCalcType.h"

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
	FString Message = "C++ Hello World!";

	const float Duration = 10.0f;
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

	bool IsPrintHello = false;
	ECPPCalcType CalcType = ECPPCalcType::Add;

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

public:
	int32 Sum(int32 A, int32 B);
	void PressedActionPrintCalcResult();
	void PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration);

private:
	void SetupInput();
	void PressedH();
	void ReleasedH();
};
