/*
 *  Copyright (C) 2011-2014  OpenDungeons Team
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "GoalKillAllEnemies.h"

#include "GameMap.h"
#include "Creature.h"
#include "Seat.h"
#include "ODFrameListener.h"

#include <iostream>

GoalKillAllEnemies::GoalKillAllEnemies(const std::string& nName, const std::string& nArguments) :
    Goal(nName, nArguments)
{
    std::cout << "\nAdding goal " << getName();
}

bool GoalKillAllEnemies::isMet(Seat *s)
{
    bool enemiesFound = false;

    GameMap* gameMap = ODFrameListener::getSingleton().getGameMap();
    if (!gameMap)
        return true;

    // Loop over all the creatures in the game map and check to see if any of them are of a different color than our seat.
    for (unsigned int i = 0, num = gameMap->numCreatures(); i < num; ++i)
    {
        if (gameMap->getCreature(i)->getColor() != s->getColor())
        {
            enemiesFound = true;
            break;
        }
    }

    return !enemiesFound;
}

std::string GoalKillAllEnemies::getSuccessMessage(Seat *s)
{
    return "You have killed all the enemy creatures.";
}

std::string GoalKillAllEnemies::getFailedMessage(Seat *s)
{
    return "You have failed to kill all the enemy creatures.";
}

std::string GoalKillAllEnemies::getDescription(Seat *s)
{
    return "Kill all enemy creatures.";
}
