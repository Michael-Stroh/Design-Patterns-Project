#include "OfficialState.h"

OfficialState::OfficialState() : RaceState(), raceSubject(new OfficialRaceSubject())
{
}

OfficialState::~OfficialState()
{
	if (this->raceSubject)
	{
		delete this->raceSubject;
	}
	this->raceSubject = NULL;
}

Result *OfficialState::runRace(Result *result, vector<RaceTeam *> *teams, Circuit *circuit)
{
	float remainingDistance = 305.00;
	float lapDistance = circuit->getLapDistance();
	float remainingTime = 7200.00; // 2 hours in seconds
	float longestLapTime = 0;
	RaceResult officialRaceResult = new RaceResult();

	while (remainingDistance > 0 && remainingTime > 0)
	{
		for (vector<RaceTeam *>::iterator team = teams->begin(); team != teams->end(); ++team)
		{
			if(result->isQualified(team->getDriver(0)->getName()){
				LapResult *lapA = team->performLap(0, this->circuit);
				officialRaceResult->addResult(lapA);
			}
			if(result->isQualified(team->getDriver(1)->getName()){
				LapResult *lapB = team->performLap(1, this->circuit);
				officialRaceResult->addResult(lapB);
			}
			if (lap->getLapTime() > longestLapTime)
			{
				longestLapTime = lap->getLapTime();
			}
		}
		timeleft -= longestLapTime;
		remainingDistance -= lapDistance;
	}

	return officialRaceResult;
}
