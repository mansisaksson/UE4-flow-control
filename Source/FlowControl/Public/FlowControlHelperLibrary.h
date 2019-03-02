#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FlowControlHelperLibrary.generated.h"


/*
* Invoke When
*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInvokeDelegate);

UCLASS(MinimalAPI)
class UFCInvokeBlueprintProxy : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable)
		FInvokeDelegate OnInvoke;
};


/*
* Lerp Float
*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLerpFloatDelegate, float, Value);

UCLASS(MinimalAPI)
class UFCLerpFloatBlueprintProxy : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable)
		FLerpFloatDelegate Tick;
};


/*
* Lerp Vector
*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLerpVectorDelegate, const FVector&, Value);

UCLASS(MinimalAPI)
class UFCLerpVectorBlueprintProxy : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable)
		FLerpVectorDelegate Tick;
};


/*
* Lerp Rotator
*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLerpRotatorDelegate, const FRotator&, Value);

UCLASS(MinimalAPI)
class UFCLerpRotatorBlueprintProxy : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable)
		FLerpRotatorDelegate Tick;
};


/*
* Flow Control Helper Library
*/
DECLARE_DYNAMIC_DELEGATE_OneParam(FInvokePredicate, bool&, RetValue);

UCLASS(meta=(ScriptName="FlowControlHelperLibrary"))
class FLOWCONTROL_API UFlowControlHelperLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly = "TRUE"))
	static UFCInvokeBlueprintProxy* CreateInvokeProxyObject(UObject* WorldContextObject, FInvokePredicate Predicate);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly = "TRUE"))
	static UFCLerpFloatBlueprintProxy* CreateLerpFloatProxyObject(UObject* WorldContextObject, float Start, float End, float Time);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly = "TRUE"))
	static UFCLerpVectorBlueprintProxy* CreateLerpVectorProxyObject(UObject* WorldContextObject, FVector Start, FVector End, float Time);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", BlueprintInternalUseOnly = "TRUE"))
	static UFCLerpRotatorBlueprintProxy* CreateLerpRotatorProxyObject(UObject* WorldContextObject, FRotator Start, FRotator End, float Time);
};
