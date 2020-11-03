#include "QualifyingState.h"

QualifyingState::QualifyingState() : RaceState(), qualifyingRaceSubject(new QualifyingRaceSubject())
{
}

QualifyingState::~QualifyingState()
{
	if (this->qualifyingRaceSubject)
	{
		delete this->qualifyingRaceSubject;
	}
	this->qualifyingRaceSubject = NULL;
}

Result *QualifyingState::runRace(Result *result, vector<RaceTeam *> *teams, Circuit *circuit)
{

	float timeLeft;
	float longestLapTime;
	RaceResult qualifyingResult = new RaceResult();

	// 3 stage "knockout" system

	// Stage 1 - All 20 teams
	// 18 minutes long
	timeLeft = 1080.00; // 18 minutes in seconds
	longestLapTime = 0;
	while (timeLeft > 0)
	{
		for (vector<RaceTeam *>::iterator team = teams->begin(); team != teams->end(); ++team)
		{
			LapResult *lapA = team->performLap(0, this->circuit);
			LapResult *lapB = team->performLap(1, this->circuit);
			qualifyingResult->addResult(lapA);
			qualifyingResult->addResult(lapB);
			if (lap->getLapTime() > longestLapTime)
			{
				longestLapTime = lap->getLapTime();
			}
		}
		timeleft -= longestLapTime;
	}
	qualifyingResult->placeBottomXOnGrid(5);

	// Stage 2 - Top 15 teams
	// 15 minutes long
	timeLeft = 900.00; // 15 minutes in seconds
	longestLapTime = 0;
	while (timeLeft > 0)
	{
		for (vector<RaceTeam *>::iterator team = teams->begin(); team != teams->end(); ++team)
		{
			if(!qualifyingResult->driverHasGridPosition(team->getDriver(0)->getName()){
				LapResult *lapA = team->performLap(0, this->circuit);
				qualifyingResult->addResult(lapA);
			}
			if(!qualifyingResult->driverHasGridPosition(team->getDriver(1)->getName()){
				LapResult *lapB = team->performLap(1, this->circuit);
				qualifyingResult->addResult(lapB);
			}
			if (lap->getLapTime() > longestLapTime)
			{
				longestLapTime = lap->getLapTime();
			}
		}
		timeleft -= longestLapTime;
	}
	qualifyingResult->placeBottomXOnGrid(5);

	// Stage 3 - Top 10 teams
	// 12 minutes long
	timeLeft = 720.00; // 12 minutes in seconds
	longestLapTime = 0;
	while (timeLeft > 0)
	{
		for (vector<RaceTeam *>::iterator team = teams->begin(); team != teams->end(); ++team)
		{
			if(!qualifyingResult->driverHasGridPosition(team->getDriver(0)->getName(), 10){
				LapResult *lapA = team->performLap(0, this->circuit);
				qualifyingResult->addResult(lapA);
			}
			if(!qualifyingResult->driverHasGridPosition(team->getDriver(1)->getName(), 10){
				LapResult *lapB = team->performLap(1, this->circuit);
				qualifyingResult->addResult(lapB);
			}
			if (lap->getLapTime() > longestLapTime)
			{
				longestLapTime = lap->getLapTime();
			}
		}
		timeleft -= longestLapTime;
	}
	qualifyingResult->placeBottomXOnGrid(10);

	qualifyingResult->apply107Rule();
	return qualifyingResult;
}
