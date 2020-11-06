#include "RaceSeasonResult.h"
#include <algorithm>

bool sortByDescending(const pair<string, int> &a, const pair<string, int> &b)
{
	return (a.second > b.second);
}

RaceSeasonResult::RaceSeasonResult()
{
	this->grandPrixResults = vector<Result *>();
	this->totalDriverPoints = vector<pair<string, int>>();
	this->totalTeamPoints = vector<pair<string, int>>();
}

RaceSeasonResult::~RaceSeasonResult(){
	
}

void RaceSeasonResult::addResult(Result *r)
{
	this->grandPrixResults.push_back(r);

	bool alreadyRecorded = false;
	vector<pair<string, int>>::iterator it;
	vector<pair<string, int>>::iterator it2;
	GrandPrixResult *grandPrixResult = dynamic_cast<GrandPrixResult *>(r);
	vector<pair<string, int>> inputDriverPoints = grandPrixResult->getDriverPoints();
	vector<pair<string, int>> inputTeamPoints = grandPrixResult->getTeamPoints();

	// Insert into drivers total points
	for (it = inputDriverPoints.begin(); it != inputDriverPoints.end(); ++it)
	{
		alreadyRecorded = false;
		for (it2 = this->totalDriverPoints.begin(); it2 != this->totalDriverPoints.end(); ++it2)
		{
			if (it->first == it2->first)
			{
				it2->second += it->second;
				alreadyRecorded = true;
				break;
			}
		}
		if (!alreadyRecorded)
		{
			this->totalDriverPoints.push_back(make_pair(it->first, it->second));
		}
	}

	// Insert into teams total points
	for (it = inputTeamPoints.begin(); it != inputTeamPoints.end(); ++it)
	{
		alreadyRecorded = false;
		for (it2 = this->totalTeamPoints.begin(); it2 != this->totalTeamPoints.end(); ++it2)
		{
			if (it->first == it2->first)
			{
				it2->second += it->second;
				alreadyRecorded = true;
				break;
			}
		}
		if (!alreadyRecorded)
		{
			this->totalTeamPoints.push_back(make_pair(it->first, it->second));
		}
	}
	sort(this->totalDriverPoints.begin(), this->totalDriverPoints.end(), sortByDescending);
	sort(this->totalTeamPoints.begin(), this->totalTeamPoints.end(), sortByDescending);
}

void RaceSeasonResult::print()
{
	this->printDrivers();
	this->printTeams();
}

void RaceSeasonResult::printDrivers()
{
	cout << "Drivers Championship: " << endl;
	vector<pair<string, int>>::iterator it;
	for (it = this->totalDriverPoints.begin(); it != this->totalDriverPoints.end(); ++it)
	{
		cout << it->first << " : " << it->second << " pts" << endl;
	}
}

void RaceSeasonResult::printTeams()
{
	cout << "Constructors Championship: " << endl;
	vector<pair<string, int>>::iterator it;
	for (it = this->totalTeamPoints.begin(); it != this->totalTeamPoints.end(); ++it)
	{
		cout << it->first << " : " << it->second << " pts" << endl;
	}
}
