#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_UE_04_RomainGameMode.h"
#include "Health.h"
#include "Turret.generated.h"

UCLASS()
class CPP_UE_04_ROMAIN_API ATurret : public AActor
{
	GENERATED_BODY()
	
public:	
	ATurret();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void ApplyDamage(AActor* Entity, int Amount);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"),Category = "Visual")
	UStaticMeshComponent* MeshComponent;
};
