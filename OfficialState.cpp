#include "OfficialState.h"

OfficialState::OfficialState() : RaceState(), raceSubject( new RaceSubject( ) ) {

}

OfficialState::~OfficialState() {

	delete raceSubject;
}

Result *OfficialState::runRace( Result *result, vector<RaceTeam *> teams, RaceTrack* circuit ) {

	float remainingDistance = 305.00;
	float lapDistance = circuit->getDistance();
	float timeLeft = 7200.00; // 2 hours in seconds
	float longestLapTime = 0;
	RaceResult *officialRaceResult = new RaceResult();
	RaceResult *previousQualifiersResult = dynamic_cast<RaceResult *>(result);
	previousQualifiersResult->printGridPositions();

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
	Logger::debug("Official Race Results", "");
	officialRaceResult->print();
	return officialRaceResult;
}

string OfficialState::getStateName()
{
	return "Official";
}
