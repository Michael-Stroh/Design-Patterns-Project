#include "OfficialState.h"

OfficialState::OfficialState() : RaceState()
{
	this->raceSubject = new RaceSubject();
}

OfficialState::~OfficialState()
{
	if (this->raceSubject)
	{
		delete this->raceSubject;
	}
	this->raceSubject = NULL;
}

Result *OfficialState::runRace(Result *result, vector<RaceTeam *> teams, Circuit *circuit)
{
	float remainingDistance = 305.00;
	// float lapDistance = circuit->getLapDistance();
	float lapDistance = 10;
	float timeLeft = 7200.00; // 2 hours in seconds
	float longestLapTime = 0;
	RaceResult *officialRaceResult = new RaceResult();
	RaceResult *previousQualifiersResult = dynamic_cast<RaceResult *>(result);

	while (remainingDistance > 0 && timeLeft > 0)
	{
		for (vector<RaceTeam *>::iterator team = teams.begin(); team != teams.end(); ++team)
		{
			if (previousQualifiersResult->isQualified((*team)->getDriver(0)->getName()))
			{
				LapResult *lapA = (*team)->performLap(0, circuit);
				officialRaceResult->addResult(lapA);
				if (lapA->getLapTime() > longestLapTime)
				{
					longestLapTime = lapA->getLapTime();
				}
			}
			if (previousQualifiersResult->isQualified((*team)->getDriver(1)->getName()))
			{
				LapResult *lapB = (*team)->performLap(1, circuit);
				officialRaceResult->addResult(lapB);
				if (lapB->getLapTime() > longestLapTime)
				{
					longestLapTime = lapB->getLapTime();
				}
			}
		}
		timeLeft -= longestLapTime;
		remainingDistance -= lapDistance;
	}

	return officialRaceResult;
}
