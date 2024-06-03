// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPHelloWorld.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetStringLibrary.h"

// Sets default values
ACPPHelloWorld::ACPPHelloWorld()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = DefaultSceneRoot;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	TObjectPtr<UStaticMesh> Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/Meshes/SM_SampleCube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);
	StaticMesh->SetupAttachment(RootComponent);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	Arrow->SetRelativeLocation(FVector(50.0f, 0.0f, 0.0f));
	Arrow->SetupAttachment(StaticMesh);

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));
	PointLight->SetRelativeLocation(FVector(130.0f, 0.0f, 0.0f));
	PointLight->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void ACPPHelloWorld::BeginPlay()
{
	Super::BeginPlay();

	// •Ï”‚ðì¬‚·‚é
	FString Message = "C++ Hello World!";

	if (IsPrintHello)
	{
		// PrintStringƒm[ƒh‚Æ“¯‚¶ˆ—
		// UKismetSystemLibraryƒNƒ‰ƒX‚ÌPrintStringŠÖ”‚ðŒÄ‚Ño‚·
		UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
	}
	else
	{
		switch (CalcType)
		{
		case 0:
		{
			// Add(‘«‚µŽZ)‚Ìˆ—
			int32 ResultAdd = UKismetMathLibrary::Add_IntInt(CalcVarA, CalcVarB);
			FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
			UKismetSystemLibrary::PrintString(this, StrResultAdd, true, true, FColor::Red, Duration, TEXT("None"));
			break;
		}
		case 1:
		{
			// Subtract(ˆø‚«ŽZ)‚Ìˆ—
			int32 ResultSubtract = CalcVarA - CalcVarB;
			FString StrResultSubtract = FString::Printf(TEXT("%d"), ResultSubtract);
			UKismetSystemLibrary::PrintString(this, StrResultSubtract, true, true, FColor::Yellow, Duration, TEXT("None"));
			break;
		}
		case 2:
		{
			// Multiply(Š|‚¯ŽZ)‚Ìˆ—
			int32 ResultMultiply = CalcVarA * CalcVarB;
			FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
			UKismetSystemLibrary::PrintString(this, StrResultMultiply, true, true, FColor::Green, Duration, TEXT("None"));
			break;
		}
		default:
		{
			// Divide(Š„‚èŽZ)‚Ìˆ—
			float ResultDivide = (float)CalcVarA / (float)CalcVarB;
			FString StrResultDivide = FString::Printf(TEXT("%f"), ResultDivide);
			UKismetSystemLibrary::PrintString(this, StrResultDivide, true, true, FColor::Blue, Duration, TEXT("None"));
			break;
		}
		}
	}
}

// Called every frame
void ACPPHelloWorld::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPPHelloWorld::OnConstruction(const FTransform& Transform)
{
	PointLight->SetVisibility(bIsVisible);
	PointLight->SetIntensity(Intensity);
	PointLight->SetLightColor(LightColor);
}