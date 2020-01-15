#include <iostream>
#include <ctime>
#include <string>

#include "Managers(PH).h"
#include "SessionManager.h"

using namespace std;

int main() 
{
	PlayerManager pm;
	HeroManager hm;
	SessionManager sm;

	pm.GenerationP(10);
	hm.GenerationH(10);

	pm.ListOfPlayers();

	sm.PerformGameSession(pm.players, hm.heroes, 5);
	sm.ListOfSessions();

	system("pause");
	return 0;
}
