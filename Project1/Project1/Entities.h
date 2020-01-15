#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
	string name;
	int rank;
	int id;
public:
	void addRank()
	{
		rank += 25;
	}

	void subRank()
	{
		if (rank >= 25) rank -= 25;
	}

	Player()
	{
		name = "unknown";
		rank = 1000;
		id = 0;
	}

	Player(string name, int rank, int id) : name(name), rank(rank), id(id){}
	

	string getName()
	{
		return name;
	}

	int getRank()
	{
		return rank;
	}

	int getId()
	{
		return id;
	}

	void changeName(string name)
	{
		this->name = name;
	}
};

class Hero
{
private:
	string name;
	int health;
	int damage;
	int speed;
public:

	Hero()
	{
		name = "hero";
		health = 100;
		damage = 10;
		speed = 2;
	}

	Hero(string name, int health, int damage, int speed):name(name),health(health),damage(damage),speed(speed){}

	string getName()
	{
		return name;
	}

	int getHealth()
	{
		return health;
	}

	int getDamage()
	{
		return damage;
	}

	int getSpeed()
	{
		return speed;
	}
};

