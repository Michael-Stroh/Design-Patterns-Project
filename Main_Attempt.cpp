
/**
   @file 
   @class 
   @authors 
   @version
   @brief
   @warning Must Add Details Here

 */

#include "GrandPrix.h"
#include "RaceTeam.h"
#include "RaceSeason.h"

vector<GrandPrix *> createGrandPrixArray(int numGrandPrixs);
RaceTeam ** createRaceTeamArray(int numTeams);

int main()
{
	cout << "successful Compilation" << endl;
	//Creation
	int numGrandPrixs = 0;
	int numTeams = 0;
	vector<GrandPrix *> gps = createGrandPrixArray(numGrandPrixs);
	RaceTeam ** teams = createRaceTeamArray(numTeams);
	//RaceSeason * raceSeason = new RaceSeason(teams, gps);

	//Notification
	//raceSeason->prepareSeason();

	//RaceLoop
	for (int i = 0; i < numGrandPrixs; ++i)
	{
		//prepareForNextRace(teams, days); //do Engineering
		//raceSeason->runNextRace(); 		//run race
		//printCurrentGrandprixResult();
	}

	//raceSeason->printFinalResults();

	//deletion
	return 0;
}

vector<GrandPrix*> createGrandPrixArray(int numGrandPrixs)
{
	vector<GrandPrix*> vec;

	return vec;
}

RaceTeam** createRaceTeamArray(int numTeams)
{
	return nullptr;
}