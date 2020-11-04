#include "RaceResult.h"
using namespace std;

RaceResult::RaceResult(): Result(), polePositionFastestLap( 0.00 ), lapResults(), totalDriversLaptime(),
                          driverGridPositions(), driversTeams() {
}

RaceResult::RaceResult( Result& result ) {


}


RaceResult::~RaceResult() {

}

bool sortByAscending(const pair<string, float> &a, const pair<string, float> &b)
{
	return ( a.second < b.second );
}

bool sortByDescending(const pair<string, float> &a, const pair<string, float> &b)
{
	return ( a.second > b.second );
}



void RaceResult::addResult(Result *r)
{
	this->lapResults.push_back(r);
	LapResult *lapResult = dynamic_cast<LapResult *>(r);
	vector<pair<string, float>>::iterator it;
	vector<pair<string, string>>::iterator it2;
	bool alreadyRecorded = false;

	// Insert into teamsDrivers
	for (it2 = driversTeams.begin(); it2 != driversTeams.end(); ++it2)
	{
		if (it2->first == lapResult->getDriverName())
		{
			alreadyRecorded = true;
			it2->second += lapResult->getTeamName();
			break;
		}
	}
	if (!alreadyRecorded)
	{
		driversTeams.push_back(make_pair<string, string>(lapResult->getDriverName(), lapResult->getTeamName()));
	}

	// Insert into totalDriversLaptimes
	for (it = totalDriversLaptime.begin(); it != totalDriversLaptime.end(); ++it)
	{
		if (it->first == lapResult->getDriverName())
		{
			alreadyRecorded = true;
			it->second += lapResult->getLapTime();
			break;
		}
	}
	if (!alreadyRecorded)
	{
		totalDriversLaptime.push_back(make_pair<string, float>(lapResult->getDriverName(), lapResult->getLapTime()));
	}

	// Insert into driversFastestLaptimes
	for (it = driversFastestLaptime.begin(); it != driversFastestLaptime.end(); ++it)
	{
		if (it->first == lapResult->getDriverName())
		{
			alreadyRecorded = true;
			if (it->second > lapResult->getLapTime())
			{
				it->second = lapResult->getLapTime();
			}
			break;
		}
	}
	if (!alreadyRecorded)
	{
		driversFastestLaptime.push_back(make_pair<string, float>(lapResult->getDriverName(), lapResult->getLapTime()));
	}
	this->sortDrivers();
}

void RaceResult::print()
{
	vector<pair<string, float>>::iterator it;
	int position = 1;
	for (it = totalDriversLaptime.begin(); it != totalDriversLaptime.end(); ++it)
	{
		cout << position << " - " << it->first << endl;
		position++;
	}
}

void RaceResult::printGridPositions()
{
	sort(driverGridPositions.begin(), driverGridPositions.end(), sortByAscending);
	vector<pair<string, int>>::iterator it;
	for (it = driverGridPositions.begin(); it != driverGridPositions.end(); ++it)
	{
		cout << it->second << " - " << it->first << endl;
	}
}

void RaceResult::sortDrivers()
{
	sort(totalDriversLaptime.begin(), totalDriversLaptime.end(), sortByAscending);
	sort(driversFastestLaptime.begin(), driversFastestLaptime.end(), sortByAscending);
	sort(driverGridPositions.begin(), driverGridPositions.end(), sortByAscending);
}

vector<pair<string, int>> RaceResult::getDriverGridPositions()
{
	sort(driverGridPositions.begin(), driverGridPositions.end(), sortByAscending);
	return this->driverGridPositions;
}

void RaceResult::placeBottomXOnGrid(int x)
{
	vector<pair<string, float>>::iterator it;
	vector<pair<string, float>>::reverse_iterator rit;

	// Get count of drivers without grid positions
	int counter = 0;
	for (it = driversFastestLaptime.begin(); it != driversFastestLaptime.end(); ++it)
	{
		if (!this->driverHasGridPosition(it->first))
		{
			counter++;
		}
	}

	// Place the X bottom drivers that do NOT have grid positions on the grid
	int gridPlacements = 0;
	for (rit = driversFastestLaptime.rbegin(); rit != driversFastestLaptime.rend(); ++rit)
	{
		if (!this->driverHasGridPosition(rit->first))
		{
			driverGridPositions.push_back(make_pair(rit->first, counter));
			counter--;
			gridPlacements++;
			if (counter == 1)
			{
				this->polePositionFastestLap = rit->second;
			}
			if (gridPlacements >= x)
			{
				break;
			}
		}
	}
}

bool RaceResult::driverHasGridPosition(string driverName)
{
	vector<pair<string, int>>::iterator it;
	bool found = false;
	for (it = driverGridPositions.begin(); it != driverGridPositions.end(); ++it)
	{
		if (it->first == driverName)
		{
			found = true;
			break;
		}
	}
	return found;
}

vector<pair<string, int>> RaceResult::getDriverResults()
{
	vector<pair<string, int>> driverResults = vector<pair<string, int>>();
	vector<pair<string, float>>::iterator it;
	int position = 1;
	for (it = totalDriversLaptime.begin(); it != totalDriversLaptime.end(); ++it)
	{
		driverResults.push_back(make_pair(it->first, position));
		position++;
	}
	return driverResults;
}

vector<pair<string, int>> RaceResult::getDriverPoints()
{
	vector<pair<string, int>> driverResults = this->getDriverResults();
	vector<pair<string, int>> driverPoints = vector<pair<string, int>>();
	vector<pair<string, int>>::iterator it;
	for (it = driverResults.begin(); it != driverResults.end(); ++it)
	{
		int pointsEarned = 0;
		switch (it->second)
		{
		case 1:
			pointsEarned = 25;
			break;
		case 2:
			pointsEarned = 18;
			break;
		case 3:
			pointsEarned = 15;
			break;
		case 4:
			pointsEarned = 12;
			break;
		case 5:
			pointsEarned = 10;
			break;
		case 6:
			pointsEarned = 8;
			break;
		case 7:
			pointsEarned = 6;
			break;
		case 8:
			pointsEarned = 4;
			break;
		case 9:
			pointsEarned = 2;
			break;
		case 10:
			pointsEarned = 1;
			break;
		}
		driverPoints.push_back(make_pair(it->first, pointsEarned));
	}
	return driverPoints;
}

vector<pair<string, int>> RaceResult::getTeamPoints()
{
	vector<pair<string, int>> teamPoints = vector<pair<string, int>>();
	vector<pair<string, int>> driverPoints = this->getDriverPoints();
	vector<pair<string, string>>::iterator it;
	vector<pair<string, int>>::iterator it2;
	vector<pair<string, int>>::iterator it3;
	bool alreadyRecorded = false;

	// Populate vector with all teams
	for (it = driversTeams.begin(); it != driversTeams.end(); ++it)
	{
		alreadyRecorded = false;
		for (it2 = teamPoints.begin(); it2 != teamPoints.end(); ++it2)
		{
			if (it2->first == it->second)
			{
				alreadyRecorded = true;
			}
		}
		if (!alreadyRecorded)
		{
			teamPoints.push_back(make_pair(it->second, 0));
		}
	}

	// Add all the drivers points to the respective teams
	for (it2 = teamPoints.begin(); it2 != teamPoints.end(); ++it2)
	{
		for (it3 = driverPoints.begin(); it3 != driverPoints.end(); ++it3)
		{
			if (it2->first == this->getDriverTeam(it3->first))
			{
				it2->second += it3->second;
			}
		}
	}
	sort(teamPoints.begin(), teamPoints.end(), sortByDescending);
	return teamPoints;
}

void RaceResult::apply107Rule()
{
	vector<pair<string, float>>::iterator it;
	for (it = driversFastestLaptime.begin(); it != driversFastestLaptime.end(); ++it)
	{
		if (it->second > 1.07 * this->polePositionFastestLap)
		{
			Logger::debug("107 Rule", "Removed driver from grid" + it->first);
			this->removeDriverFromGrid(it->first);
		}
	}
	this->reassignGridPositions();
}

void RaceResult::removeDriverFromGrid(string driverName)
{
	vector<pair<string, int>>::iterator it;
	for (it = this->driverGridPositions.begin(); it != driverGridPositions.end(); ++it)
	{
		if (it->first == driverName)
		{
			this->driverGridPositions.erase(it);
			break;
		}
	}
}

void RaceResult::reassignGridPositions()
{
	vector<pair<string, int>> newDriverGridPositions = vector<pair<string, int>>();
	vector<pair<string, int>>::iterator it;
	this->sortDrivers();
	int position = 1;
	for (it = driverGridPositions.begin(); it != driverGridPositions.end(); ++it)
	{
		newDriverGridPositions.push_back(make_pair(it->first, position));
		position++;
	}
	this->driverGridPositions = newDriverGridPositions;
}

string RaceResult::getDriverTeam(string driverName)
{
	vector<pair<string, string>>::iterator it;
	for (it = driversTeams.begin(); it != driversTeams.end(); ++it)
	{
		if (it->first == driverName)
		{
			return it->second;
		}
	}
	return "not found";
}