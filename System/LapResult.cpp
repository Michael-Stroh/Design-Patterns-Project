#include "LapResult.h"

LapResult::LapResult()
{
	this->lapTime = 0;
	this->driverName = "";
	this->teamName = "";
}

LapResult::LapResult(string d, string s, float time)
{
	this->driverName = d;
	this->teamName = s;
	this->lapTime = time;
}

LapResult::~LapResult()
{
	this->driverName = "";
	this->teamName = "";
	this->lapTime = 0.00;
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

void LapResult::addResult(Result *r)
{
}
