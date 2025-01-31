// Copyright Michael Olson 2022


#include "Units/UnitBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "AbilitySystemComponent.h"

// Sets default values
AUnitBase::AUnitBase()
{
	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	ASC->SetIsReplicated(true);


	CapsuleCollider = CreateDefaultSubobject<UCapsuleComponent>("CapsuleCollider");
	SetRootComponent(CapsuleCollider);
	//CapsuleCollider->SetupAttachment(RootComponent);
	CapsuleCollider->InitCapsuleSize(10, 20);
	CapsuleCollider->SetCollisionProfileName("Pawn");
	CapsuleCollider->SetVisibility(true);
	CapsuleCollider->bHiddenInGame = true;

	// Create soft colliders for steering behaviors
	SeparationArea = CreateDefaultSubobject<USphereComponent>("SeparationArea");
	SeparationArea->SetupAttachment(CapsuleCollider);
	SeparationArea->InitSphereRadius(15);
	SeparationArea->SetCollisionProfileName("OverlapOnlyPawn");
	SeparationArea->SetVisibility(true);
	SeparationArea->bHiddenInGame = false;
	/*AlignmentArea = CreateDefaultSubobject<USphereComponent>("AvoidanceArea");
	AlignmentArea->SetupAttachment(RootComponent);
	AlignmentArea->InitSphereRadius(300);
	AlignmentArea->SetCollisionProfileName("OverlapOnlyPawn");
	AlignmentArea->SetVisibility(true);
	AlignmentArea->bHiddenInGame = true;*/
}

void AUnitBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (ASC)
	{
		ASC->InitAbilityActorInfo(this, this);
	}
}

void AUnitBase::BeginPlay()
{
	Super::BeginPlay();

	PrimaryActorTick.bCanEverTick = true;
}

void AUnitBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	UPawnMovementComponent* MovementComponent = GetMovementComponent();

	TSet<AActor*> SeparationUnits;
	SeparationArea->GetOverlappingActors(SeparationUnits);
	if (SeparationUnits.Num() > 0)
	{
		SeparationArea->ShapeColor = FColor::Orange;
	}
	else
	{
		SeparationArea->ShapeColor = FColor::Green;
	}

	// Push us away from any pawns that are too close.
	// TODO: Create a console variable to control the max number of units to consider for separation (2 is probably fine)
	for (AActor* NearbyPawn : SeparationUnits)
	{
		FVector SeparationVector = (this->GetActorLocation() - NearbyPawn->GetActorLocation()).GetUnsafeNormal() * 0.25;
		MovementComponent->AddInputVector(SeparationVector);
	}
}