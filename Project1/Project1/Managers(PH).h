#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#include "Entities.h"

class PlayerManager 
{
public:
	vector<Player> players;

	void GenerationP(int k) {
		vector<string> names = { "Player1","Player2","Player3","Player4","Player5","Player6","Player7","Player8","Player9","Player10"};
		srand((unsigned)time(NULL));
		for (size_t i = 0; i < k; i++)
		{
			int idx = rand() % names.size();
			Player player = Player(names[idx], 1000, i + 1);
			players.push_back(player);
		}
	}
   

	void ListOfPlayers() {
		for (size_t i = 0; i < players.size(); i++) {
			cout << "Name: " << players[i].getName()
				<< "\tID: " << players[i].getId()
				<< "\tRank: " << players[i].getRank()
				<< endl << endl;
		}
	}
	
	Player GetPlayersByName(string name)
	{
		for (size_t i = 0; i < players.size(); i++)
		{
			if (players[i].getName() == name) 
				return players[i];
		}
	}

	Player GetPlayersById(int id)
	{
		for (size_t i = 0; i < players.size() - 1; i++)
		{
			if (id == players[i].getId())
				return players[i];
		}
	}

	void AddPlayer(string name)
	{
		int id = players[players.size() - 1].getId() + 1;
		Player player = Player(name, 1000, id);
		players.push_back(player);
	}

	void RemovePlayer(int id)
	{
		for (size_t i = 0; i < players.size(); i++)
		{
			if (players[i].getId() == id) players.erase(players.begin() + i);
			break;
		}
	}
};

class HeroManager
{
public:

	vector<Hero> heroes;

	void GenerationH(int x)
	{
		vector<string> names = { "Abaddon","Alchemist","Axe","Slardar","Sven","Timbersaw","Tiny","Wraith King","Drow Ranger","Juggernaut" };
		srand((unsigned)time(NULL));
		for (int i = 0; i < x; i++)
		{
			int idx = rand() % names.size();
			int health = rand() % 100 + 1;
			int damage = rand() % 10 + 1;
			int speed = rand() % 5 + 1;
			Hero hero = Hero(names[idx], health, damage, speed);
			heroes.push_back(hero);
		}
	}

	void ListOfHeroes() {
		for (size_t i = 0; i < heroes.size(); i++) {
			cout << "Name: " << heroes[i].getName()
				<< "\tHP: " << heroes[i].getHealth()
				<< "\tDamage: " << heroes[i].getDamage()
				<< "\tSpeed: " << heroes[i].getSpeed()
				<< endl << endl;
		}
	}

	Hero GetHeroByName(string name)
	{
		for (size_t i = 0; i < heroes.size(); i++)
		{
			if (heroes[i].getName() == name)
			{
				return heroes[i];
			}
		}
	}

	int AddHeroes(string name, int damage, int health, int speed)
	{
		for (size_t i = 0; i < heroes.size(); i++)
		{
			if (heroes[i].getName() == name)
			{
				return 0;
			}
		}
		Hero hero = Hero(name, health, damage, speed);
		heroes.push_back(hero);
	}

	void RemoveHero(string name)
	{
		for (size_t i = 0; i < heroes.size(); i++)
		{
			if (heroes[i].getName() == name)
			{
				heroes.erase(heroes.begin() + i);
				break;
			}
		}
	}
};