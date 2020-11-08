#include "OfficialState.h"

OfficialState::OfficialState() : RaceState()		//changed by Tim
{
	this->officialRaceSubject = new OfficialRaceSubject();   //Added by Tim
}

OfficialState::~OfficialState() {

	delete officialRaceSubject;
}

Result *OfficialState::runRace( Result *result, vector<RaceTeam *> teams, RaceTrack* circuit ) 
{
	Logger::debug("OfficialState::runRace", "");											//added by Tim
	for (vector<RaceTeam *>::iterator team = teams.begin(); team != teams.end(); ++team){
		this->officialRaceSubject->attach((*team));
	}
	RaceResult *officialRaceResult = new RaceResult();
	dynamic_cast<OfficialRaceSubject *>(this->officialRaceSubject)->notify(officialRaceResult);

	float remainingDistance = 305.00;
	float lapDistance = circuit->getDistance();
	float timeLeft = 7200.00; // 2 hours in seconds
	float longestLapTime = 0;
	RaceResult *previousQualifiersResult = dynamic_cast<RaceResult *>(result);
	Logger::debug("OfficialState::runRace printing grid results", "");											//added by Tim
	Logger::blue("Printing Official RaceState gridPositions", "");
	previousQualifiersResult->printGridPositions();
	Logger::debug("OfficialState: printed grid positions", "aboout to do while loop");							//added by Tim

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
		//Logger::debug("OfficialState runRace loop", "");
		timeLeft -= longestLapTime;
		remainingDistance -= lapDistance;
	}

	Logger::debug("OfficialState: Official Race Results", "");
	Logger::blue("Printing Official Race Results:", "");
	officialRaceResult->print();
	Logger::debug("OfficialState::runRace finished printing the results", "");			
	//for (vector<RaceTeam *>::iterator team = teams.begin(); team != teams.end(); ++team)
	//{
	//	this->officialRaceSubject->detach((*team));
	//}

	Logger::debug("OfficialState::runRace end of function", "");											//added by Tim
	return officialRaceResult;
}

string OfficialState::getStateName()
{
	return "Official";
}
