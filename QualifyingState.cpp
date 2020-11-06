#include "QualifyingState.h"

QualifyingState::QualifyingState() : RaceState()
{
	this->qualifyingRaceSubject = new RaceSubject();
}

QualifyingState::~QualifyingState()
{
	if (this->qualifyingRaceSubject)
	{
		delete this->qualifyingRaceSubject;
	}
	this->qualifyingRaceSubject = NULL;
}

Result *QualifyingState::runRace(Result *result, vector<RaceTeam *> teams, RaceTrack *circuit)
{

	for (vector<RaceTeam *>::iterator team = teams.begin(); team != teams.end(); ++team)
	{
		this->qualifyingRaceSubject->attach((*team));
	}
	RaceResult *qualifyingResult = new RaceResult();
	dynamic_cast<QualifyingRaceSubject*>(this->qualifyingRaceSubject)->notify(qualifyingResult);

	float timeLeft;
	float longestLapTime;
	Logger::debug("Running first stage of qualifiers","");
	// 3 stage "knockout" system

	// Stage 1 - All 20 teams
	// 18 minutes long
	timeLeft = 1080.00; // 18 minutes in seconds
	longestLapTime = 0;
	while (timeLeft > 0)
	{
		for (vector<RaceTeam *>::iterator team = teams.begin(); team != teams.end(); ++team)
		{
			LapResult *lapA = (*team)->performLap(0, circuit);
			LapResult *lapB = (*team)->performLap(1, circuit);
			qualifyingResult->addResult(lapA);
			qualifyingResult->addResult(lapB);
			if (lapA->getLapTime() > longestLapTime)
			{
				longestLapTime = lapA->getLapTime();
			}
			if (lapB->getLapTime() > longestLapTime)
			{
				longestLapTime = lapB->getLapTime();
			}
		}
		timeLeft -= longestLapTime;
	}
	qualifyingResult->placeBottomXOnGrid(5);

	Logger::debug("Running second stage of qualifiers", "");
	// Stage 2 - Top 15 teams
	// 15 minutes long
	timeLeft = 900.00; // 15 minutes in seconds
	longestLapTime = 0;
	while (timeLeft > 0)
	{
		for (vector<RaceTeam *>::iterator team = teams.begin(); team != teams.end(); ++team)
		{
			if(!qualifyingResult->driverHasGridPosition((*team)->getDriver(0)->getName())){
				LapResult *lapA = (*team)->performLap(0, circuit);
				qualifyingResult->addResult(lapA);
				if (lapA->getLapTime() > longestLapTime)
				{
					longestLapTime = lapA->getLapTime();
				}
			}
			if(!qualifyingResult->driverHasGridPosition((*team)->getDriver(1)->getName())){
				LapResult *lapB = (*team)->performLap(1, circuit);
				qualifyingResult->addResult(lapB);
				if (lapB->getLapTime() > longestLapTime)
				{
					longestLapTime = lapB->getLapTime();
				}
			}
		}
		timeLeft -= longestLapTime;
	}
	qualifyingResult->placeBottomXOnGrid(5);

	Logger::debug("Running final stage of qualifiers", "");
	// Stage 3 - Top 10 teams
	// 12 minutes long
	timeLeft = 720.00; // 12 minutes in seconds
	longestLapTime = 0;
	while (timeLeft > 0)
	{
		for (vector<RaceTeam *>::iterator team = teams.begin(); team != teams.end(); ++team)
		{
			if(!qualifyingResult->driverHasGridPosition((*team)->getDriver(0)->getName())){
				LapResult *lapA = (*team)->performLap(0, circuit);
				qualifyingResult->addResult(lapA);
				if (lapA->getLapTime() > longestLapTime)
				{
					longestLapTime = lapA->getLapTime();
				}
			}
			if(!qualifyingResult->driverHasGridPosition((*team)->getDriver(1)->getName())){
				LapResult *lapB = (*team)->performLap(1, circuit);
				qualifyingResult->addResult(lapB);
				if (lapB->getLapTime() > longestLapTime)
				{
					longestLapTime = lapB->getLapTime();
				}
			}
		}
		timeLeft -= longestLapTime;
	}
	qualifyingResult->placeBottomXOnGrid(10);
	Logger::debug("Final qualifying round grid positions", "");
	qualifyingResult->printGridPositions();
	for (vector<RaceTeam *>::iterator team = teams.begin(); team != teams.end(); ++team)
	{
		this->qualifyingRaceSubject->detach((*team));
	}
	// qualifyingResult->apply107Rule();
	return qualifyingResult;
}

string QualifyingState::getStateName()
{
	return "Qualifying";
}