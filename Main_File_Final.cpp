#include "GrandPrix.h"
#include "RaceTeam.h"
#include "RaceSeason.h"
#include <iostream>

//Main Helper Functions
vector<GrandPrix*> createGrandPrixs( CompositeRoad* );
vector<RaceTeam* > createRaceTeams( int );
CompositeRoad* populateCircuit( const string& );
void prepareForNextRace( vector<RaceTeam*>, GrandPrix* );
void endGrandPrix();

int main() {

		cout << "Successful compilation" << endl;

		int numberOfTeams = 10;                                                                                //Should this not be 5??


		//Creation
		CompositeRoad* circuit = populateCircuit("Data/races.txt" );                        //Mike -create these function definitions

		vector< GrandPrix* > grandPrixs = createGrandPrixs( circuit );                              //Alex: done
		vector< RaceTeam* > raceTeams = createRaceTeams( numberOfTeams );                           //Tim
		RaceSeason* raceSeason = new RaceSeason( grandPrixs, raceTeams );



		//Notification
		raceSeason->prepareSeason();																//Brent do inform grandPrixs

		//RaceLoop
		for ( int i = 0; i < grandPrixs.size(); ++ i ) {

			prepareForNextRace( raceTeams, grandPrixs[ i ] );     									//Tim and Kayla calls doDayPreparetion in RaceTeam
			raceSeason->runNextGrandPrix();                     									//Alex: checked - working as intended
			grandPrixs[ i ]->displayResult();                    									//Alex, now using logger
			endGrandPrix();																			//Brent: Do what needs be done for logistics after a grandprix.
		}
		raceSeason->getResult()->print();															//Alex: is now printing nicely


		/*
			Deletion
			Mike Will handle Deletion
		*/

}

vector<GrandPrix*> createGrandPrixs( CompositeRoad* circuit ) {

	/*
		Alex: has created the GrandPrixs
	*/
	vector<GrandPrix *> vec = vector<GrandPrix *>();
	CircuitIterator *circuitIterator = dynamic_cast<CircuitIterator*>(circuit->createIterator());
	while(!circuitIterator->isDone()){
		vec.push_back(new GrandPrix((circuitIterator->currentItem())));
		circuitIterator->next();
	}
	return vec;
}

vector<RaceTeam* > createRaceTeams( int numberOfTeams ) {

	vector<RaceTeam*> vec;

	/*
			Tim: create the RaceTeams
	*/
	return vec;
}

void prepareForNextRace( vector<RaceTeam*> team,	GrandPrix* gp ) {

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
	
	for ( int i = 0; i < team.size(); ++ i ) {

			team[ i ]->prepareForNextRace(); 
	}
	

	/*
	End of Tim's Portion
	*/
}

void endGrandPrix() {

	//Brent to go Ham
	//for each team
}

string trim( string temp ) {

	temp.erase( 0, temp.erase( temp.find_last_not_of( "\t\n\v\f\r " ) + 1 ).find_first_not_of( "\t\n\v\f\r " ) );
	return temp;
}

CompositeRoad*  populateCircuit( const string& fileName ) {

	string line;
	ifstream file;

	file.open( fileName.c_str() );
	if ( file.is_open() ) {

		while ( getline(file, line ) ) {

			int pos = 0;
			int size = line.size();
			string name, direction, startingDate, endingDate, euro;
			float disLap, wind = 0, longestStraight, fastestLap, averagePitStop;
			int numCorners, numLaps;


			string temp = line;

			pos = temp.find_first_of( '|' );
			name = trim( temp.substr( 0, pos - 1 ) );
			temp = temp.substr( pos + 1, size );

			pos = temp.find_first_of( '|' );
			fastestLap = stof( trim( temp.substr( 0, pos - 1 ) ) );
			temp = temp.substr( pos + 1, size );

			pos = temp.find_first_of( '|' );
			disLap = stof( trim( temp.substr( 0, pos - 1 ) ) );
			temp = temp.substr( pos + 1, size );

			pos = temp.find_first_of( '|' );
			numLaps = stoi( trim( temp.substr( 0, pos - 1 ) ) );
			temp = temp.substr( pos + 1, size );

			pos = temp.find_first_of( '|' );
			longestStraight = stof( trim( temp.substr( 0, pos - 1 ) ) );
			temp = temp.substr( pos + 1, size );

			pos = temp.find_first_of( '|' );
			numCorners = stoi( trim( temp.substr( 0, pos - 1 ) ) );
			temp = temp.substr( pos + 1, size );

			pos = temp.find_first_of( '|' );
			startingDate = trim( temp.substr( 0, pos - 1 ) );
			temp = temp.substr( pos + 1, size );

			pos = temp.find_first_of( '|' );
			endingDate = temp.substr( 0, pos - 1 );
			temp = temp.substr( pos + 1, size );

			pos = temp.find_first_of( '|' );
			averagePitStop = stof( trim( temp.substr( 0, pos - 1 ) ) );
			temp = temp.substr( pos + 1, size );

			pos = temp.find_first_of( '|' );
			euro = trim( temp.substr( 0, pos - 1 ) );
			temp = temp.substr( pos + 1, size );

			pos = temp.find_first_of( '|' );
			direction = trim( temp.substr( 0, pos - 1 ) );
			temp = temp.substr( pos + 1, size );

			RaceTrack* tmp = nullptr;
			if ( direction == "clockwise" ) {

				tmp = new RaceTrack( name, RaceTrack::direction::clockwise, disLap, wind, longestStraight, numCorners,
									 numLaps );
			} else if ( direction == "anticlockwise" ) {

				tmp = new RaceTrack( name, RaceTrack::direction::anticlockwise, disLap, wind, longestStraight,
									 numCorners, numLaps );
			} else {

				Logger::cyan( "Error", "Wrong direction given." );
			}

			tmp->setStartDate( startingDate );
			tmp->setEndDate( endingDate );
			bool maybe = true;
			euro = trim( euro );

			if ( euro == "true" ) {

				maybe = true;
			} else if ( euro == "false" ) {

				maybe = false;
			} else {

				Logger::cyan( "Error", "The file not found." );
			}
			tmp->setAvgPitStops( averagePitStop );
			tmp->setEuro( maybe );
		}
	}
	else {

		Logger::cyan( "Error", "The file not found." );

	}

	return nullptr;
}