#include "FCExampleActor.h"
#include "FlowControlManager.h"
#include "Engine/World.h"

AFCExampleActor::AFCExampleActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AFCExampleActor::BeginPlay()
{
	Super::BeginPlay();
	
	/*FFlowControl::InvokeWhen(this, [&]() {
		return GetWorld()->GetTimeSeconds() > 5.0;
	}, []() {
		UE_LOG(LogTemp, Log, TEXT("Hello World"));
	});

	FFlowControl::LerpValue<float>(this, 5.0, 0, 10, FMath::Lerp<float, float>, [](const float &Value) {
		UE_LOG(LogTemp, Log, TEXT("%f"), Value);
	});*/
}

void AFCExampleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

