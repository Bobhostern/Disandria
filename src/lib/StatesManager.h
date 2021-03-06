#ifndef STATESMANAGER_H
#define STATESMANAGER_H

/*
 * StatesManager.h
 * This file is part of Disandria
 *
 * Copyright (C) 2013 - Bob Hostern
 *
 * Disandria is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Disandria is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Disandria. If not, see <http://www.gnu.org/licenses/>.
 */



#include "StateManager.h"
#include "StateMachine.h"

class StatesManager
{
public:
    static void checkCurrentState(RenderWindow*);
    static void renderCurrentState(RenderWindow*);
private:
    static StateBase* currentState;
};

#endif // STATESMANAGER_H
