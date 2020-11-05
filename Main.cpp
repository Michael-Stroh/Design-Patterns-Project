
#include "GrandPrix.h"
#include "RaceTeam.h"
#include "RaceSeason.h"

int main()
{
	//Creation
	GrandPrix** gps = new GrandPrix();
	RaceTeam ** teams = new  RaceTeam();
	RaceSeason * raceSeason = new RaceSeason(teams, gps);

	//Notification
	raceSeason->prepareSeason();

	//RaceLoop
	for(int i=0; i< numGrandPrixs; ++i)
	{
		prepareForNextRace(teams, days); //do Engineering
		raceSeason->runNextRace(); 		//run race
		printCurrentGrandprixResult(); 
	}

	raceSeason->printFinalResults();

	//deletion
	deleteEverything();
}


void prepareForNextRace( team, days)
{
	for(int i=0; i< numTeams;++i)
	{
		teams[i]->prepareForNextRace(); //Brent strategy call once lekker
	}
}

