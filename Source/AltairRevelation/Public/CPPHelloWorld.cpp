// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPHelloWorld.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/GameplayStatics.h"

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

	SetupInput();

	if (IsPrintHello)
	{
		// PrintStringƒm[ƒh‚Æ“¯‚¶ˆ—
		// UKismetSystemLibraryƒNƒ‰ƒX‚ÌPrintStringŠÖ”‚ðŒÄ‚Ño‚·
		UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
	}
	else
	{
		PrintCalcResult(CalcType, CalcVarA, CalcVarB, Duration);
	}
}

void ACPPHelloWorld::PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration)
{
	switch (Type)
	{
		case ECPPCalcType::Add:
		{
			// Add(‘«‚µŽZ)‚Ìˆ—
			int32 ResultAdd = Sum(CalcVarA, CalcVarB);
			FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
			UKismetSystemLibrary::PrintString(this, StrResultAdd, true, true, FColor::Red, Duration, TEXT("None"));
			break;
		}
		case ECPPCalcType::Subtract:
		{
			// Subtract(ˆø‚«ŽZ)‚Ìˆ—
			int32 ResultSubtract = CalcVarA - CalcVarB;
			FString StrResultSubtract = FString::Printf(TEXT("%d"), ResultSubtract);
			UKismetSystemLibrary::PrintString(this, StrResultSubtract, true, true, FColor::Yellow, Duration, TEXT("None"));
			break;
		}
		case ECPPCalcType::Multiply:
		{
			// Multiply(Š|‚¯ŽZ)‚Ìˆ—
			int32 ResultMultiply = CalcVarA * CalcVarB;
			FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
			UKismetSystemLibrary::PrintString(this, StrResultMultiply, true, true, FColor::Green, Duration, TEXT("None"));
			break;
		}
		case ECPPCalcType::Divide:
		{
			// Divide(Š„‚èŽZ)‚Ìˆ—
			float ResultDivide = (float)CalcVarA / (float)CalcVarB;
			FString StrResultDivide = FString::Printf(TEXT("%f"), ResultDivide);
			UKismetSystemLibrary::PrintString(this, StrResultDivide, true, true, FColor::Blue, Duration, TEXT("None"));
			break;
		}
	}
}

// Called every frame
void ACPPHelloWorld::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 ACPPHelloWorld::Sum(int32 A, int32 B)
{
	return A + B;
}

void ACPPHelloWorld::SetupInput()
{
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPHelloWorld::PressedH);
	InputComponent->BindKey(EKeys::H, IE_Released, this, &ACPPHelloWorld::ReleasedH);
}

void ACPPHelloWorld::PressedH()
{
	// Hello World!‚ðo—Í‚·‚éˆ—
	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration, TEXT("None"));
}

void ACPPHelloWorld::ReleasedH()
{
	// ŒvŽZŒ‹‰Ê‚ðo—Í‚·‚éˆ—
	PrintCalcResult(CalcType, CalcVarA, CalcVarB, Duration);
}

void ACPPHelloWorld::OnConstruction(const FTransform& Transform)
{
	PointLight->SetVisibility(bIsVisible);
	PointLight->SetIntensity(Intensity);
	PointLight->SetLightColor(LightColor);
}