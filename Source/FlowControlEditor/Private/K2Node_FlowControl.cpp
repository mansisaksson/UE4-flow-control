#include "K2Node_FlowControl.h"
#include "EditorCategoryUtils.h"
#include "FlowControlHelperLibrary.h"

#define LOCTEXT_NAMESPACE "K2Node_FlowControl"

FText UK2Node_FlowControl::GetTooltipText() const
{
	return ToolTip;
}

FText UK2Node_FlowControl::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return Title;
}

FText UK2Node_FlowControl::GetMenuCategory() const
{
	return FEditorCategoryUtils::GetCommonCategory(FCommonEditorCategory::FlowControl);
}

UK2Node_InvokeWhen::UK2Node_InvokeWhen()
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UFlowControlHelperLibrary, CreateInvokeProxyObject);
	ProxyFactoryClass = UFlowControlHelperLibrary::StaticClass();
	ProxyClass = UFCInvokeBlueprintProxy::StaticClass();

	ToolTip = LOCTEXT("InvokeWhen_Tooltip", "Invoked when the predicate returns true");
	Title = LOCTEXT("InvokeWhen", "Invoke When");
}

UK2Node_LerpFloat::UK2Node_LerpFloat()
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UFlowControlHelperLibrary, CreateLerpFloatProxyObject);
	ProxyFactoryClass = UFlowControlHelperLibrary::StaticClass();
	ProxyClass = UFCLerpFloatBlueprintProxy::StaticClass();

	ToolTip = LOCTEXT("LerpFloat_Tooltip", "Lerps a float value from start to end in the time specified");
	Title = LOCTEXT("LerpFloat", "Lerp Float");
}

UK2Node_LerpVector::UK2Node_LerpVector()
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UFlowControlHelperLibrary, CreateLerpVectorProxyObject);
	ProxyFactoryClass = UFlowControlHelperLibrary::StaticClass();
	ProxyClass = UFCLerpVectorBlueprintProxy::StaticClass();

	ToolTip = LOCTEXT("LerpVector_Tooltip", "Lerps a Vector value from start to end in the time specified");
	Title = LOCTEXT("LerpVector", "Lerp Vector");
}

UK2Node_LerpRotator::UK2Node_LerpRotator()
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UFlowControlHelperLibrary, CreateLerpRotatorProxyObject);
	ProxyFactoryClass = UFlowControlHelperLibrary::StaticClass();
	ProxyClass = UFCLerpRotatorBlueprintProxy::StaticClass();

	ToolTip = LOCTEXT("LerpRotator_Tooltip", "Lerps a Rotator value from start to end in the time specified");
	Title = LOCTEXT("LerpRotator", "Lerp Rotator");
}

#undef LOCTEXT_NAMESPACE


