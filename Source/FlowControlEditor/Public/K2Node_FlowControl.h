#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "K2Node_BaseAsyncTask.h"
#include "K2Node_FlowControl.generated.h"


UCLASS()
class FLOWCONTROLEDITOR_API UK2Node_FlowControl : public UK2Node_BaseAsyncTask
{
	GENERATED_BODY()
protected:
	FText ToolTip;
	FText Title;

public:
	UK2Node_FlowControl() {};

	//~ Begin UEdGraphNode Interface
	virtual FText GetTooltipText() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	//~ End UEdGraphNode Interface

	//~ Begin UK2Node Interface
	virtual FText GetMenuCategory() const override;
	//~ End UK2Node Interface
};


UCLASS()
class FLOWCONTROLEDITOR_API UK2Node_InvokeWhen : public UK2Node_FlowControl
{
	GENERATED_BODY()
public:
	UK2Node_InvokeWhen();
};

UCLASS()
class FLOWCONTROLEDITOR_API UK2Node_LerpFloat : public UK2Node_FlowControl
{
	GENERATED_BODY()
public:
	UK2Node_LerpFloat();
};

UCLASS()
class FLOWCONTROLEDITOR_API UK2Node_LerpVector : public UK2Node_FlowControl
{
	GENERATED_BODY()
public:
	UK2Node_LerpVector();
};

UCLASS()
class FLOWCONTROLEDITOR_API UK2Node_LerpRotator : public UK2Node_FlowControl
{
	GENERATED_BODY()
public:
	UK2Node_LerpRotator();
};
