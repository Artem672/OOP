#pragma once
#include <iostream>
#include "Entities.h"

using namespace std;

class TeamPart
{
public:
	Player player;
	Hero hero;

	TeamPart (const Player& player, const Hero& hero)
	{
		this->player = player;
		this->hero = hero;
	}
};
