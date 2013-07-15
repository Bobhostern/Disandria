#include "Menus.h"
#include "MapParser.h"
#include "GameManager.h"
#include "StateManager.h"
#include <cstdlib>

bool MAINMENU_startButton(const CEGUI::EventArgs&)
{
	StateManager::setCurrentState(disandria::States::VOID);
	MapParser::loadCurrentMap("testmap");
	GameManager::getRenderWindow()->resetView();
}

bool MAINMENU_loadButton(const CEGUI::EventArgs&)
{
	// TODO: Do something
}

bool MAINMENU_endButton(const CEGUI::EventArgs&)
{
	exit(0);
}
