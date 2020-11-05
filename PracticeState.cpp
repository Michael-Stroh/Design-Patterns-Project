#include "PracticeState.h"
#include "RaceTeam.h"

PracticeState::PracticeState() : RaceState()
{
}

PracticeState::~PracticeState()
{
}

Result *PracticeState::runRace(Result *result, vector<RaceTeam *> teams, Circuit *circuit)
{
	// 3 practice sessions
	// #1 & #2 are 1.5 hours long, #3 is 1 hour long

	// General algorithm:
	// Have all teams perform a single lap, store the longest laptime & subtract this from a variable representing the time left. Loop until there's no time left

	Result *raceResult = new RaceResult();
	float timeLeft;
	float longestLapTime;

	// Races #1, #2 & #3:
	for (int i = 0; i < 3; i++)
	{
		if (i == 2)
		{
			timeLeft = 3600.00; // 1 hour stored as seconds
		}
		else
		{
			timeLeft = 5400.00; // 1.5 hours stored as seconds
		}
		longestLapTime = 0;
		// @todo: account for if last lap puts timeLeft into the negative
		while (timeLeft > 0)
		{
			for (vector<RaceTeam *>::iterator team = teams.begin(); team != teams.end(); ++team)
			{
				LapResult *lapA = (*team)->performLap(0, circuit);
				LapResult *lapB = (*team)->performLap(1, circuit);
				raceResult->addResult(lapA);
				raceResult->addResult(lapB);
				if (lapA->getLapTime() > longestLapTime)
				{
					longestLapTime = lapA->getLapTime();
				}
				if (lapA->getLapTime() > longestLapTime)
				{
					longestLapTime = lapA->getLapTime();
				}
			}
			timeLeft -= longestLapTime;
		}
	}
}
