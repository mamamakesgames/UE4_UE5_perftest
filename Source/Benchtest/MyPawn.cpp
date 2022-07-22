#include "MyPawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"

AMyPawn::AMyPawn()
{
    UCapsuleComponent* capColl = FindComponentByClass<UCapsuleComponent>();
    capColl->SetCapsuleHalfHeight(100.0f);
    capColl->SetCapsuleRadius(100.0f);
    
    UStaticMeshComponent* staticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    staticMeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, -100.0f));

    static ConstructorHelpers::FObjectFinder<UStaticMesh> teapotMeshOF(TEXT("StaticMesh'/Game/teapot.teapot'"));
	if (teapotMeshOF.Succeeded()) {
        staticMeshComp->SetStaticMesh(teapotMeshOF.Object);
	}
    staticMeshComp->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	 
	PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.TickInterval = 2.0f;

}

void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    TArray<AActor*> pawns;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyPawn::StaticClass(), pawns);
    if (pawns.Num() > 1) {
        AMyPawn* targetPawn = this;
        do {
            targetPawn = Cast<AMyPawn>(pawns[FMath::RandRange(0, pawns.Num() - 1)]);
        } while (targetPawn == this);
        AAIController* aiCtrl = Cast<AAIController>(Controller);
        aiCtrl->MoveToLocation(targetPawn->GetActorLocation());
    }
}

void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

