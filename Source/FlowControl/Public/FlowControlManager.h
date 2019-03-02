#pragma once

#include "CoreMinimal.h"
#include "Tickable.h"



/**
 * 
 */
class FLOWCONTROL_API FFlowControl : public FTickableGameObject
{
private: 
	static FFlowControl Instance;

	struct FInvokeEvent
	{
		TWeakObjectPtr<UObject> ContextObject;
		TFunction<bool()> Predicate;
		TFunction<void()> Action;
	};
	TArray<FInvokeEvent> InvokeEvents;

	typedef TFunction<bool(float DeltaTime)> FTickingFunc;
	struct FTickingEvent
	{
		TWeakObjectPtr<UObject> ContextObject;
		FTickingFunc TickableFunction;
	};
	TArray<FTickingEvent> TickingFunctions;

private:
	FFlowControl() = default;
	FFlowControl(const FFlowControl&) = default;

public:
	static void InvokeWhen(UObject* Context, TFunction<bool()> Predicate, TFunction<void()> Function);

	template <class T>
	static void LerpValue(
		UObject* Context,
		float LerpTime,
		const T& Start,
		const T& End,
		TFunction<T(const T&, const T&, float)> LerpFunction, 
		TFunction<void(const T&)> Action
	)
	{
		float TimeElapsed = 0;
		float Alpha = 0;
		auto TickFunction = [Start, End, LerpFunction, Action, TimeElapsed, Alpha, LerpTime](float DeltaTime) mutable
		{
			TimeElapsed += DeltaTime;
			Alpha = FMath::Clamp<float>((TimeElapsed / LerpTime), 0.0, 1.0);
			Action(LerpFunction(Start, End, Alpha));
			if (Alpha >= 1.0) {
				return false;
			}
			return true;
		};
		Instance.TickingFunctions.Add({ Context, TickFunction });
	}

private:

	// ~Begin FTickableGameObject Interface
	virtual void Tick(float DeltaTime) override;
	virtual ETickableTickType GetTickableTickType() const override { return ETickableTickType::Always; }
	virtual bool IsTickableWhenPaused() const override { return true; }
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(FFlowControl, STATGROUP_Tickables); }
	// ~End FTickableGameObject Interface

};
