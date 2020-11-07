#include "GrandPrix.h"
#include "RaceTeam.h"
#include "RaceSeason.h"
#include <iostream>

//Main Helper Functions pre-declaration
void createGrandPrixs();
vector<RaceTeam* > createRaceTeams( int );
void populateCircuit( const string& );
void prepareForNextRace( vector<RaceTeam*>, GrandPrix* );
void endGrandPrix();

//this will hold all the created circuits
CompositeRoad* circuit;
vector< GrandPrix* > grandPrixs;
vector< RaceTeam* > raceTeams;

int main() {


		int numberOfTeams = 10;                                                                     //Should this not be 5?? no theres 10 teams where did you come up with 5

		////////////////Creation////////////////

		//instantiate the CompositeRoad pointer
		circuit = new CompositeRoad();
		//call the function to read the circuits in from the file
		populateCircuit("Data/races.txt" );
                /// TODO: the file path will change depending what files are stored in which folders

		//test to see if the RaceTracks were created
		/*circuit->determineMaxValues();
		circuit->determineMinValues();
		cout << endl << endl;

		circuit->print();
		cout << endl << endl;*/




		grandPrixs = vector<GrandPrix *>();
		createGrandPrixs();                                                                         //Alex: done


		raceTeams = createRaceTeams( numberOfTeams );                                               //Tim
		RaceSeason* raceSeason = new RaceSeason( grandPrixs, raceTeams );



		//Notification
		raceSeason->prepareSeason();																//Brent do inform grandPrixs

		//RaceLoop
		for ( int i = 0; i < grandPrixs.size(); ++i ) {

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

		//delete the circuit before the GrandPrix that holds it
		delete circuit;

        //go through each object stored
        for ( GrandPrix* prix : grandPrixs ) {

            //free the memory
            delete prix;
        }

        //empty and resize the vector
        grandPrixs.clear();
}

void createGrandPrixs() {

	/*
		Alex: has created the GrandPrixs
	*/


	//create and set the iterator
	CircuitIterator* it = circuit->createIterator();
    it->first();

	//continue going through until we have traversed all the items
	while ( !it->isDone() ) {

	    //create the GrandPrix with the current iterator item
        grandPrixs.push_back( new GrandPrix( ( it->currentItem() ) ) );

        //go to the next item in the iterator
        it->next();
	}

    delete it;
}

vector<RaceTeam* > createRaceTeams( int numberOfTeams ) {

	vector<RaceTeam*> vec;

	/*
			Tim: create the RaceTeams
	*/
	return vec;
}

void prepareForNextRace( vector<RaceTeam*> team, GrandPrix* gp ) {

	/*
		Brents Portion
	*/
		//for each team call 'decideNextStrategy'

	/*
		End of Brents Portion
	*/

	/*
		Tim's portion
	*/

	for ( int i = 0; i < team.size(); ++i ) {

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

string trim( string line ) {

	return line.erase( 0, line.erase( line.find_last_not_of( "\t\n\v\f\r " ) + 1 ).find_first_not_of( "\t\n\v\f\r " ) );
}

void  populateCircuit( const string& fileName ) {

	/*
		Order of the races.txt file

	 		circuitName | bestLapTime( seconds ) | lapLength( km ) | numberOfLaps | longestStriaght( m ) | numberOfCorners | startDate( M-D ) | endDate( M-D ) | pitStop( s)  | European | direction
	*/

	//create a file variable and open the given file
	ifstream file;
	file.open( fileName.c_str() );

	//check if the file can open
	if ( file.is_open() ) {

		//the file can open, therefore exists

		//go through each line in the file
		string line;
		while ( getline(file, line ) ) {

			//variables to hold the data read from the file
			float wind, dist, straightDist, bestLap, pitStop;
			int size = line.size(), pos, numCorners, numLaps;
			string name, direction, startDate, endDate, euro;

			//find the value for the name
			pos = line.find_first_of( '|' );
			name = trim( line.substr( 0, pos - 1 ) );
			line = line.substr( pos + 1, size );

			//find the value for best lap time
			pos = line.find_first_of( '|' );
			bestLap = stof( trim( line.substr( 0, pos - 1 ) ) );
			line = line.substr( pos + 1, size );

			//find the value for distance of a lap
			pos = line.find_first_of( '|' );
			dist = stof( trim( line.substr( 0, pos - 1 ) ) );
			line = line.substr( pos + 1, size );

			//find the value for number of laps the track will be raced
			pos = line.find_first_of( '|' );
			numLaps = stoi( trim( line.substr( 0, pos - 1 ) ) );
			line = line.substr( pos + 1, size );

			//find the value for straight distance of the track
			pos = line.find_first_of( '|' );
			straightDist = stof( trim( line.substr( 0, pos - 1 ) ) );
			line = line.substr( pos + 1, size );

			//find the value for the number of corners on the track
			pos = line.find_first_of( '|' );
			numCorners = stoi( trim( line.substr( 0, pos - 1 ) ) );
			line = line.substr( pos + 1, size );

			//find the value for starting date the track will be used for
			pos = line.find_first_of( '|' );
			startDate = trim( line.substr( 0, pos - 1 ) );
			line = line.substr( pos + 1, size );

			//find the value for ending date the track will not be used for
			pos = line.find_first_of( '|' );
			endDate = line.substr( 0, pos - 1 );
			line = line.substr( pos + 1, size );

			//find the value for the average amount of pit stops made on the track
			pos = line.find_first_of( '|' );
			pitStop = stof( trim( line.substr( 0, pos - 1 ) ) );
			line = line.substr( pos + 1, size );

			//find the value for if the track is in Europe or not
			pos = line.find_first_of( '|' );
			euro = trim( line.substr( 0, pos - 1 ) );
			line = line.substr( pos + 1, size );

			//find the value for the direction the track will be raced in
			pos = line.find_first_of( '|' );
			direction = trim( line.substr( 0, pos - 1 ) );
			line = line.substr( pos + 1, size );

			//find the value for wind on the track
			pos = line.find_first_of( '|' );
			wind = stof( trim( line.substr( 0, pos - 1 ) ) );
			line = line.substr( pos + 1, size );


			//determine the enum direction from the string value
			RaceTrack::direction dir = RaceTrack::direction::clockwise;
			if ( direction == "clockwise" ) {

				//the track will be raced clockwise
				dir = RaceTrack::direction::clockwise;
			} else if ( direction == "anticlockwise" ) {

				//the track will be raced anti-clockwise
				dir = RaceTrack::direction::anticlockwise;
			} else {

				//the value given is invalid so take the default of true and output the error
				Logger::red( "Error", "Incorrect direction value given in " + fileName + "." );
			}

			//determine the bool value for European from the string value
			euro = trim( euro );
			bool isEuro = true;
			if ( euro == "true" ) {

				//the race is in Europe
				isEuro = true;
			} else if ( euro == "false" ) {

				//the race is not in Europe
				isEuro = false;
			} else {

				//the value given is invalid so take the default of true and output the error
				Logger::red( "Error", "Incorrect european value given in " + fileName + "." );
			}


			//create the RaceTrack from the given data and add it to the Circuit
			circuit->addRoad( new RaceTrack( name, dir, dist, wind, straightDist, pitStop,
											 bestLap, numCorners, numLaps, isEuro, startDate, endDate ) );
		}
	}
	else {

		//the file could not open, most likely does not exist
		Logger::red( "Error", "The file not found therefore could not create circuits( main )." );
	}

}