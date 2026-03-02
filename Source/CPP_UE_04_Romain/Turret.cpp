#include "Turret.h"

ATurret::ATurret()
{
 	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(MeshComponent);
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATurret::ApplyDamage(AActor* Entity, int Amount)
{
	if (Entity->GetClass()->ImplementsInterface(UHealth::StaticClass()))
	{
		IHealth::Execute_TakeDamage(Entity, Amount);
		if (Amount >= 5)
			Destroy();
		else
			return;
	}
}

