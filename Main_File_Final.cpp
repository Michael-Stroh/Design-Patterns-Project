#include "GrandPrix.h"
#include "RaceTeam.h"
#include "RaceSeason.h"

#include <iostream>
#include <string>
using namespace std;

//Main Helper Functions
vector<GrandPrix*> createGrandPrixs(Circuit* circuit);
vector<RaceTeam* > createRaceTeams(int numberOfTeams);
Circuit * populateCircuit(const string& fileName);		//NB MIKE: need to change this function to return a circuit *
void prepareForNextRace(vector<RaceTeam*> team, GrandPrix* gp);
void endGrandPrix();

int main() {

	cout << "Successful compilation" << endl;

	int numberOfTeams = 10;
	string circuitFileName = "";

	//******IDEA ALGORITHM******
			//Creation
			Circuit * circuit = populateCircuit(circuitFileName);						//Mike -create these function definitions
			vector<GrandPrix*> grandPrixs = createGrandPrixs(circuit);	//Alex 
			vector<RaceTeam*>  raceTeams = createRaceTeams(numberOfTeams);		    //Tim
			RaceSeason * raceSeason = new RaceSeason( grandPrixs, raceTeams);
	

			//Notification
			raceSeason->prepareSeason();		//Brent do inform grandPrixs

			//RaceLoop
			for ( int i = 0; i < grandPrixs.size(); ++ i ) {
				prepareForNextRace( raceTeams, grandPrixs[i] );	 //Tim and Kayla calls doDayPreparetion in RaceTeam
				raceSeason->runNextGrandPrix();					 //Alex: run race, maybe check maybe dont I am not your mom
				grandPrixs[i]->displayResult();					//Alex, Make sure it uses logger
				endGrandPrix();									//Brent: Do what needs be done for logistics after a grandprix.
			}
			raceSeason->getResult()->print();					//Alex double check this printss nicely
			//deletion
															//Mike Will handle Deletion
	 
	//Delete me, here for Testing purposes
	while (true)
	{

	}
}

vector<GrandPrix*> createGrandPrixs(Circuit* circuit)
{
	vector<GrandPrix*> vec;

	/*
			Alex: create the GrandPrixs
	*/
	return vec;
}

vector<RaceTeam* > createRaceTeams(int numberOfTeams)
{
	vector<RaceTeam*> vec;

	/*
			Tim: create the RaceTeams
	*/
	return vec;
}

void prepareForNextRace(vector<RaceTeam*> team,	GrandPrix * gp) {

	/*
		Brents Portion
	*/
		//for each team call 'decideNextStrategy'

	/*
		End of Brents Portion
	*/

	/*
		Tim's potrion
	*/
	
	for ( int i = 0; i < team.size(); ++ i ) 
	{
			team[ i ]->prepareForNextRace(); 
	}
	

	/*
	End of Tim's Portion
	*/
}

void endGrandPrix()
{
	//Brent to go Ham
	//for each team
}


/*
	Funtions to implement for main
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////                 This is from Brent's Strategy.                                               ////////
////////            I took it out from there as it does not make sense to read it in from there       ////////
////////            I want to talk about this, if it should go there I will work on it more           ////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

string trim(string temp) {

	temp.erase(0, temp.erase(temp.find_last_not_of("\t\n\v\f\r ") + 1).find_first_not_of("\t\n\v\f\r "));
	return temp;
}

Circuit *  populateCircuit(const string& fileName) {

	string line;
	ifstream file;

	file.open(fileName);
	if (file.is_open()) {

		while (getline(file, line)) {

			int pos = 0;
			int size = line.size();
			string name, direction, startingDate, endingDate, euro;
			float disLap, wind = 0, longestStraight, fastestLap, averagePitStop;
			int numCorners, numLaps;


			string temp = line;

			pos = temp.find_first_of('|');
			name = trim(temp.substr(0, pos - 1));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			fastestLap = stof(trim(temp.substr(0, pos - 1)));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			disLap = stof(trim(temp.substr(0, pos - 1)));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			numLaps = stoi(trim(temp.substr(0, pos - 1)));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			longestStraight = stof(trim(temp.substr(0, pos - 1)));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			numCorners = stoi(trim(temp.substr(0, pos - 1)));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			startingDate = trim(temp.substr(0, pos - 1));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			endingDate = temp.substr(0, pos - 1);
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			averagePitStop = stof(trim(temp.substr(0, pos - 1)));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			euro = trim(temp.substr(0, pos - 1));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			direction = trim(temp.substr(0, pos - 1));
			temp = temp.substr(pos + 1, size);

			RaceTrack* tmp = nullptr;
			if (direction == "clockwise") {

				tmp = new RaceTrack(name, RaceTrack::direction::clockwise, disLap, wind, longestStraight, numCorners, numLaps);
			}
			else if (direction == "anticlockwise") {

				tmp = new RaceTrack(name, RaceTrack::direction::anticlockwise, disLap, wind, longestStraight, numCorners, numLaps);
			}
			else {

				Logger::cyan("Error", "Wrong direction given.");
			}

			tmp->setStartDate(startingDate);
			tmp->setEndDate(endingDate);
			bool maybe = true;
			euro = trim(euro);

			if (euro == "true") {

				maybe = true;
			}
			else if (euro == "false") {

				maybe = false;
			}
			else {

				Logger::cyan("Error", "The file not found.");
			}
			tmp->setAvgPitStops(averagePitStop);
			tmp->setEuro(maybe);
		}
	}
	else {

		Logger::cyan("Error", "The file not found.");
	}

	return nullptr;
}