
int main()
{
	//Creation
	GrandPrix** gps = new GrandPrix();
	RaceTeam ** teams = new  RaceTeam();
	RaceSeason * raceSeason = new RaceSeason(teams, gps);

	//Notification
	raceSeason->prepareSeason();

	//RaceLoop
	for (int i = 0; i < numGrandPrixs; ++i)
	{
		prepareForNextRace(teams, days); //do Engineering
		raceSeason->runNextRace(); 		//run race
		printCurrentGrandprixResult();
	}

	raceSeason->printFinalResults();

	//deletion
	deleteEverything();
}