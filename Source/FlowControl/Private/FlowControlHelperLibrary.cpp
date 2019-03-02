#include "FlowControlHelperLibrary.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "FlowControlManager.h"

UFCInvokeBlueprintProxy* UFlowControlHelperLibrary::CreateInvokeProxyObject(UObject* WorldContextObject, FInvokePredicate Predicate)
{
	TWeakObjectPtr<UFCInvokeBlueprintProxy> MyObj = NewObject<UFCInvokeBlueprintProxy>(WorldContextObject);
	
	FFlowControl::InvokeWhen(WorldContextObject, [MyObj, Predicate]()->bool {
		if (!MyObj.IsValid() || !Predicate.IsBound()) {
			return false;
		}

		bool result = false;
		Predicate.ExecuteIfBound(result);
		return result;
	},
	[MyObj]() {
		if (MyObj.IsValid()) {
			MyObj->OnInvoke.Broadcast();
			MyObj->MarkPendingKill();
		}
	});

	return MyObj.Get();
}

UFCLerpFloatBlueprintProxy* UFlowControlHelperLibrary::CreateLerpFloatProxyObject(UObject* WorldContextObject, float Start, float End, float Time)
{
	TWeakObjectPtr<UFCLerpFloatBlueprintProxy> MyObj = NewObject<UFCLerpFloatBlueprintProxy>(WorldContextObject);
	FFlowControl::LerpValue<float>(WorldContextObject, Time, Start, End, FMath::Lerp<float, float>, [MyObj, End](const float &Value) {
		if (MyObj.IsValid()) {
			MyObj->Tick.Broadcast(Value);
			if (FMath::IsNearlyEqual(Value, End)) {
				MyObj->MarkPendingKill();
			}
		}
	});
	return MyObj.Get();
}

UFCLerpVectorBlueprintProxy* UFlowControlHelperLibrary::CreateLerpVectorProxyObject(UObject* WorldContextObject, FVector Start, FVector End, float Time) 
{
	TWeakObjectPtr<UFCLerpVectorBlueprintProxy> MyObj = NewObject<UFCLerpVectorBlueprintProxy>(WorldContextObject);
	FFlowControl::LerpValue<FVector>(WorldContextObject, Time, Start, End, 
		FMath::Lerp<FVector, float>, [MyObj, End](const FVector &Value) {
		if (MyObj.IsValid()) {
			MyObj->Tick.Broadcast(Value);
			if (Value.Equals(End)) {
				MyObj->MarkPendingKill();
			}
		}
	});

	return MyObj.Get();
}

UFCLerpRotatorBlueprintProxy* UFlowControlHelperLibrary::CreateLerpRotatorProxyObject(UObject* WorldContextObject, FRotator Start, FRotator End, float Time)
{
	TWeakObjectPtr<UFCLerpRotatorBlueprintProxy> MyObj = NewObject<UFCLerpRotatorBlueprintProxy>(WorldContextObject);
	FFlowControl::LerpValue<FRotator>(WorldContextObject, Time, Start, End,
		FMath::Lerp<FRotator, float>, [MyObj, End](const FRotator &Value) {
		if (MyObj.IsValid()) {
			MyObj->Tick.Broadcast(Value);
			if (Value.Equals(End)) {
				MyObj->MarkPendingKill();
			}
		}
	});

	return MyObj.Get();
}