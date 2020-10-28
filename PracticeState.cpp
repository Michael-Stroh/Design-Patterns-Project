#include "PracticeState.h"

PracticeState::PracticeState() : RaceState()
{
}

PracticeState::~PracticeState()
{
}

Result *PracticeState::runRace(Result *result, vector<RaceTeam *> *teams, Circuit *circuit)
{
	// 3 practice sessions
	// #1 & #2 are 1.5 hours long, #3 is 1 hour long

	// General algorithm:
	// Have all teams perform a single lap, store the longest laptime & subtract this from a variable representing the time left. Loop until there's no time left

	Result *raceResult = new RaceResult();
	float timeleft;
	float longestLapTime;

	// Races #1, #2 & #3:
	for (int i = 0; i < 3; i++)
	{
		if (i == 2)
		{
			timeleft = 3600.00; // 1 hour stored as seconds
		}
		else
		{
			timeleft = 5400.00; // 1.5 hours stored as seconds
		}
		longestLapTime = 0;
		// @todo: account for if last lap puts timeleft into the negative
		while (timeleft > 0)
		{
			for (vector<RaceTeam *>::iterator team = teams->begin(); team != teams->end(); ++team)
			{
				// @todo: account for multiple drivers per team
				LapResult *lap = team->performLap();
				raceResult->addResult(lap);
				if (lap->getLapTime() > longestLapTime)
				{
					longestLapTime = lap->getLapTime();
				}
			}
			timeleft -= longestLapTime;
		}
	}
}
