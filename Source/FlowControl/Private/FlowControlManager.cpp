
#include "FlowControlManager.h"

FFlowControl FFlowControl::Instance = FFlowControl();

void FFlowControl::InvokeWhen(UObject* Context, TFunction<bool()> Predicate, TFunction<void()> Function)
{
	Instance.InvokeEvents.Add({	Context, Predicate,	Function });
}

void FFlowControl::Tick(float DeltaTime)
{
	// Execute invoke events
	for (auto It = InvokeEvents.CreateIterator(); It; ++It)
	{
		if (!(*It).ContextObject.IsValid()) {
			It.RemoveCurrent();
		}
		else if ((*It).Predicate()) {
			(*It).Action();
			It.RemoveCurrent();
		}
	}

	// Execute Ticking functions
	for (auto It = TickingEvents.CreateIterator(); It; ++It)
	{
		if (!(*It).ContextObject.IsValid()) {
			It.RemoveCurrent();
		}
		else {
			bool Result = (*It).TickingFunction(DeltaTime);
			if (!Result) {
				It.RemoveCurrent();
			}
		}
	}
}