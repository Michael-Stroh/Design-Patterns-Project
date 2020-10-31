#include "LapResult.h"

LapResult::LapResult() : Result()
{
	this->lapTime = 0;
	this->driverName = "";
	this->teamName = "";
}

LapResult::LapResult(string d, string s, float Time) : Result(), lapTime(Time), driverName(d), teamName(s)
{
}

void LapResult::print()
{
	cout << this->driverName << " [" << this->teamName << "] - " << this->lapTime << endl;
}

float LapResult::getLapTime()
{
	return this->lapTime;
}

string LapResult::getDriverName()
{
	return this->driverName;
}

string LapResult::getTeamName()
{
	return this->teamName;
}
