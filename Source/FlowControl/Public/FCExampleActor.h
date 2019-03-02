

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FCExampleActor.generated.h"

UCLASS()
class FLOWCONTROL_API AFCExampleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AFCExampleActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
