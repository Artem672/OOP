#pragma once
#include <iostream>
#include <vector>
#include "Session.h"

using namespace std;

class SessionManager
{
private:
	vector<Session> Sessions;
	time_t time = 0;

public:
	SessionManager(){}

	void ListOfSessions()
	{
		for (size_t i = 0; i < Sessions.size(); i++)
		{
			cout << i + 1 << ".";
			Sessions[i].ShowTime();
			int winner = Sessions[i].GetWinner();
			cout << Sessions[i].arr[winner] << " won" << endl;
		}
	}

	void PerformGameSession(vector<Player>& players, vector<Hero>& heroes, int num) {
		for (int i = 0; i < num; i++) {
			Session session(players, heroes);
			session.StartGame(players);
			session.ShowTime();
			session.ShowTeamBlue();
			session.ShowTeamRed();
			Sessions.push_back(session);
		}
	}
};