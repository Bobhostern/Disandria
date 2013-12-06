#include "CEGUIFalconBinding.h"

Falcon::Module* CEGUIFalconBinding::module = NULL;

void CEGUIFalconBinding::addConstants(Falcon::Module* mod)
{
}

void CEGUIFalconBinding::addMethods(Falcon::Module* mod)
{
}

void CEGUIFalconBinding::addClasses(Falcon::Module* mod)
{
}

void CEGUIFalconBinding::addSingletons(Falcon::Module* mod)
{
}

Falcon::Module* CEGUIFalconBinding::createBinding()
{
	if(module == NULL)
	{
		module = new Falcon::Module;
		module->name("CEGUIFalcon");
		addConstants(module);
		addMethods(module);
		addClasses(module);
		addSingletons(module);
	}
	return module;
}