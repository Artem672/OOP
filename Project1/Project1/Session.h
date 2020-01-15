#pragma warning(disable : 4996)
//#pragma once
//#pragma warning(suppress : 4996)
#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>

#include "Entities.h"
#include "TeamPart.h"

using namespace std;

	template <typename T>
	void randVector(vector<T>& vec) {
		srand((unsigned)time(NULL));
		for (size_t i = 0; i < vec.size(); i++) {
			swap(vec[i], vec[rand() % vec.size()]);
		}
	}

	class Session
	{
	public:
		vector<TeamPart> TeamRed;
		vector<TeamPart> TeamBlue;
		vector<TeamPart> GameLobby;
		vector<Hero> NewHeroes;
		

		int winner = -1;
		string arr[3] = { "Tie","Blue","Red" };

		void ChooseWinner()
		{
			int healthBlue = 0, healthRed = 0,damageBlue = 0,damageRed = 0;

			for (size_t i = 0; i < TeamBlue.size(); i++)
			{
				healthBlue += TeamBlue[i].hero.getHealth();
				damageBlue += TeamBlue[i].hero.getDamage();
			}
			for (size_t i = 0; i < TeamRed.size(); i++)
			{
				healthRed += TeamRed[i].hero.getHealth();
				damageRed += TeamRed[i].hero.getDamage();
			}

			if (healthBlue - damageRed == healthRed - damageBlue)
			{
				winner = 0;//mb Tie
			}
			else if (healthBlue - damageRed > healthRed - damageBlue)
			{
				winner = 1;//mb winner is Blue
			}
			else
			{
				winner = 2;//mb winner is Red
			}
		}

		void ChangeRank(vector<Player>& players)
		{
			for (size_t i = 0; i < TeamBlue.size(); i++)
			{
				int idBlue = TeamBlue[i].player.getId();
				int idRed = TeamRed[i].player.getId();

				for (size_t j = 0; j < players.size(); j++)
				{
					switch (winner)
					{
					case 1:
						if (players[j].getId() == idBlue) players[j].addRank();
						if (players[j].getId() == idRed) players[j].subRank();
						break;//add for BLue
					case 2:
						if (players[j].getId() == idBlue) players[j].subRank();
						if (players[j].getId() == idRed) players[j].addRank();
						break;//add for Red
					}
				}
			}
		}

		void AnnounceTheWinner()
		{
			if (winner > 0)
			{
				cout << arr[winner] << "won this game" << endl;
			}
			else
			{
				cout << arr[winner] << "won" << endl;
			}
		}

		void AddTeamPart()
		{
			for (size_t i = 0; i < GameLobby.size(); i++)
			{
				if (i < 5)
				{
					TeamBlue.push_back(GameLobby[i]);
				}
				else
				{
					TeamRed.push_back(GameLobby[i]);
				}
			}
		}


		Session(vector<Player>& players, vector<Hero>& heroes)
		{
			for (size_t i = 0; i < heroes.size(); i++)
			{
				NewHeroes.push_back(heroes[i]);
			}

			randVector(players);
			randVector(NewHeroes);

			for (size_t i = 0; i < 10; i++) {
				if (GameLobby.size() < 10) {
					if (i < 5) {
						TeamPart tp = TeamPart(players[i], NewHeroes[i]);
						GameLobby.push_back(tp);
					}
					else {
						TeamPart tp = TeamPart(players[i], NewHeroes[i - 5]);
						GameLobby.push_back(tp);
					}
				}
				else {
					TeamPart tp = TeamPart(players[i], NewHeroes[i]);
					GameLobby.push_back(tp);
				}
			}

			AddTeamPart();

			for (int i = 0; i < 10000; i++)
			{
				randVector(GameLobby);
				TeamBlue.clear();
				TeamRed.clear();
				AddTeamPart();
			}

			Sleep(1000);
		}

		~Session()
		{
			NewHeroes.clear();
			TeamBlue.clear();
			TeamRed.clear();
			GameLobby.clear();
		}
			time_t StartTime = 0;
		void StartGame(vector<Player>& players)
		{
			StartTime = time(0);
			ChooseWinner();
			AnnounceTheWinner();
			ChangeRank(players);
		}
		

		void ShowTime()
		{
			tm* ltm = localtime(&StartTime);
			cout<< "Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
		}

		void ShowTeamBlue()
		{
			cout << endl
				<< "                  Team Blue" << endl << endl;
			for (size_t i = 0; i < TeamBlue.size(); i++)
			{
				cout << "Name: " << TeamBlue[i].player.getName()
					<< "\tID: " << TeamBlue[i].player.getId()
					<< "\tRank: " << TeamBlue[i].player.getRank()
					<< endl;

				cout << "Name: " << TeamBlue[i].hero.getName()
					<< "\tHP: " << TeamBlue[i].hero.getHealth()
					<< "\tDamage: " << TeamBlue[i].hero.getDamage()
					<< "\tSpeed: " << TeamBlue[i].hero.getSpeed()
					<< endl;
			}

		}
		
		void ShowTeamRed()
		{
			cout << endl
				<< "                  Team Red" << endl << endl;
			for (size_t i = 0; i < TeamRed.size(); i++)
			{
				cout << "Name: " << TeamRed[i].player.getName()
					<< "\tID: " << TeamRed[i].player.getId()
					<< "\tRank: " << TeamRed[i].player.getRank()
					<< endl;

				cout << "Name: " << TeamRed[i].hero.getName()
					<< "\tHP: " << TeamRed[i].hero.getHealth()
					<< "\tDamage: " << TeamRed[i].hero.getDamage()
					<< "\tSpeed: " << TeamRed[i].hero.getSpeed()
					<< endl;
			}
		}

		int GetWinner()
		{
			return winner;
		}
	}; 
