#include "QualifyingState.h"

QualifyingState::QualifyingState() : RaceState()
{
	//this->qualifyingRaceSubject = new RaceSubject();
	this->qualifyingRaceSubject = new QualifyingRaceSubject();				//changed by Tim
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
	Logger::debug("QualifyingState::runRace started", "");									//added By Tim
	for (vector<RaceTeam *>::iterator team = teams.begin(); team != teams.end(); ++team)
	{
		Logger::debug("QualifyfingState adding a team", "");
		this->qualifyingRaceSubject->attach((*team));
	}

	Logger::debug("QualifyingState::runRace all subjects attached", "");									//added By Tim
	RaceResult *qualifyingResult = new RaceResult();
	Logger::debug("QualifyingState::runRace raceResult created", "");										//added by Tim
	dynamic_cast<QualifyingRaceSubject*>(this->qualifyingRaceSubject)->notify(qualifyingResult);    //commented out gets us further
	Logger::debug("QualifyingState::runRace all subbjects notified", "");							//added by Tim

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

	this->qualifyingRaceSubject->detachAll();
	Logger::debug("QualifyingState enf ofrunRace function", "");		//added by Tim

	// qualifyingResult->apply107Rule();
	return qualifyingResult;
}

string QualifyingState::getStateName()
{
	return "Qualifying";
}