#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Health.generated.h"

UINTERFACE(MinimalAPI)
class UHealth : public UInterface
{
	GENERATED_BODY()
};


class CPP_UE_04_ROMAIN_API IHealth
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void TakeDamage(int Amount);
};
