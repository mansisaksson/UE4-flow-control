#pragma once

#include "CoreMinimal.h"
#include "IConsoleManager.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogFCEditor, Log, All);

class FFlowControlEditor : public IModuleInterface
{
public:
	virtual void StartupModule();

};

