#include "GrandPrix.h"
#include "RaceTeam.h"
#include "RaceSeason.h"
#include <iostream>
#include <stdlib.h>

/*
	Remember:
	Alex: SeasonSubject Notify Functions
	Race.h Top author change and startRace function
	Qualifing Race Subject notify
*/


//Main Helper Functions pre-declaration
void createGrandPrixs();
vector<RaceTeam* > createRaceTeams( int );
void populateCircuit( const string& );
void prepareForNextRace( vector<RaceTeam*>, GrandPrix* );
void endGrandPrix();
vector<RaceTeam*> makeTeamsAndDrivers();

//this will hold all the created circuits
CompositeRoad* circuit;
vector< GrandPrix* > grandPrixs;
vector< RaceTeam* > raceTeams;

void printCarStatistics(CarComposite* car)		//helper functin, delete
{
	float aggregateH = car->getHandling();
	float aggregateA = car->getAcceleration();
	float aggregateS = car->getSpeed();

	cout << endl;
	cout << "Car total Speed: " << aggregateS << endl;
	cout << "Car total acceleration: " << aggregateA << endl;
	cout << "Car total Handling: " << aggregateH << endl;
	cout << endl;
}

int main() {

	
		system("Color 05");
		int numberOfTeams = 10;           
		
		////////////////Creation////////////////

		//instantiate the CompositeRoad pointer
		circuit = new CompositeRoad();
		//call the function to read the circuits in from the file
		populateCircuit("Data/races.txt" );																	//working
										   /// TODO: the file path will change depending what files are stored in which folders

		grandPrixs = vector<GrandPrix *>();								//working
		createGrandPrixs();                                                               //Alex: done
		raceTeams = makeTeamsAndDrivers();                                               //Brent 

		//delete me
		RaceSeason* raceSeason = new RaceSeason(grandPrixs, raceTeams);
		//Notification
		Logger::red("Main: calling prepareRaceSeason", "");
		raceSeason->prepareSeason();																//Brent do inform grandPrixs
		Logger::red("Main: prepared for Season", "");

		//RaceLoop
		for ( int i = 0; i < grandPrixs.size(); ++i ) {
 			Logger::red("Main: Preparing for next Race", to_string(i));
			prepareForNextRace( raceTeams, grandPrixs[ i ]);     									//Tim and Kayla calls doDayPreparetion in RaceTeam
			Logger::red("Main: runnning next Race", "");
			raceSeason->runNextGrandPrix();                     									//Alex: checked - working as intended
			Logger::red("Main: printing grandPrix results", "");
			grandPrixs[ i ]->displayResult();                    									//Alex, now using logger
			Logger::red("Main: ending grandPrix", "");
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

		string temp = "";
		cin >> temp;
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

//Backup Function
vector<RaceTeam* > createRaceTeams( int numberOfTeams ) {

	vector<RaceTeam*> vec;

	for (int i = 0; i < numberOfTeams; ++i)
	{
		vec.push_back(new RaceTeam());
	}

	return vec;
}

void prepareForNextRace( vector<RaceTeam*> team, GrandPrix* gp ) {

	/*
		Brents Portion
	*/
	Logger::customDebug("Main PrepareForNextRace decide Next STrategy");
	for (int i = 0; i < team.size(); ++i) {

		team[i]->decideNextStrategy(gp);
	}

	/*
		End of Brents Portion
	*/

	/*
		Tim's portion
	*/
	Logger::customDebug("Main PrepareForNextRace decide team preparefor next race");
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

vector<RaceTeam*> makeTeamsAndDrivers() {
	vector<RaceTeam*> teams;
	int i = 0;
	string line;
	ifstream file;

	bool changer = false;
	vector<Driver*> temp;

	file.open("Data/driver.txt");   //changed from ../Data
	if (file.is_open()) {
		Logger::debug("MakeDrivers and Teams", "File opened correctly");
		while (getline(file, line)) {

			int pos = 0;
			int size = line.size();

			string teamName, racerName;
			float errorProne;

			pos = line.find_first_of('|');
			teamName = trim(line.substr(0, pos - 1));
			line = line.substr(pos + 1, size);

			pos = line.find_first_of('|');
			racerName = trim(line.substr(0, pos - 1));
			line = line.substr(pos + 1, size);

			pos = line.find_first_of('|');
			errorProne = stof(trim(line.substr(0, pos - 1)));
			line = line.substr(pos + 1, size);

			Logger::debug("MakeDrivers and Teams", "creating new COntrolledDriving");
			temp.push_back(new ControlledDriving(racerName, errorProne));
			Logger::debug("MakeDrivers and Teams", "new COntrolledDriving created");
			if (changer != true) {

				changer = true;
			}
			else {
				changer = false;
				Logger::debug("MakeDrivers and Teams", "creating new Team");
				teams.push_back(new RaceTeam(teamName, temp));
				Logger::debug("MakeDrivers and Teams", " new Team created");
				temp.clear();
			}

		}
	}
	return teams;
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
				Logger::cyan( "Error", "Incorrect direction value given in " + fileName + "." );
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
				Logger::cyan( "Error", "Incorrect european value given in " + fileName + "." );
			}


			//create the RaceTrack from the given data and add it to the Circuit
			circuit->addRoad( new RaceTrack( name, dir, dist, wind, straightDist, pitStop,
											 bestLap, numCorners, numLaps, isEuro, startDate, endDate ) );
		}
	}
	else {

		//the file could not open, most likely does not exist
		Logger::cyan( "Error", "The file not found therefore could not create circuits( main )." );
	}

}

/*  Tim testing values for getCarLapTime
	// Delete ME!!
	cout << "Compilled and running" << endl;
	Logger::setDebug(true);
	RaceTeam * team = new RaceTeam();
	string name = "RaceTrack1";

	RaceTrack* raceTrack = new RaceTrack(name, RaceTrack::clockwise,1200.0, 10.09, 1200.0, 17, 20);
	raceTrack->setBestLapTime(60.00);
	cout << "RaceTrackBest Time: "<<raceTrack->getBestLapTime()<< " team lap Time: "<<team->getCarLapTime(0, raceTrack) << endl;

	RaceTrack* raceTrack2 = new RaceTrack(name, RaceTrack::clockwise, 1200.0, 5.09, 1000.0, 23, 20);
	raceTrack2->setBestLapTime(60.00);
	cout << "RaceTrackBest Time: " << raceTrack->getBestLapTime() << " team lap Time: " << team->getCarLapTime(0, raceTrack2) << endl;

	RaceTrack* raceTrack3 = new RaceTrack(name, RaceTrack::clockwise, 1200.0, 12.09, 1100.0, 10, 20);
	raceTrack3->setBestLapTime(60.00);
	cout << "RaceTrackBest Time: " << raceTrack->getBestLapTime() << " team lap Time: " << team->getCarLapTime(0, raceTrack3) << endl;

	Logger::debug("Finished", "end");
	while (true) {}
	return 0;
	//DELETE ME!!
*/

/*
	//DELETE ME!!
		Logger::setDebug(true);
		raceTeams = makeTeamsAndDrivers();                                               //Brent 

		Logger::debug("Main after creating raceTeams", to_string(raceTeams.size()));
		for (int i = 0; i < raceTeams.size(); ++i)						//MAKE VARIABLES PRIVATE AGAIN!!!
		{
			Logger::debug("Main car " , to_string(i));
			raceTeams[i]->drivers[0]->displayDriver();
			raceTeams[i]->drivers[1]->displayDriver();
			printCarStatistics(raceTeams[i]->engineeringCrew->getCar());
		}

		while(true) {}
		return 0;
		//DELETE ME!!
*/

/*

		Logger::debug("Main after creating raceTeams", to_string(raceTeams.size()));
		for (int i = 0; i < raceTeams.size(); ++i)						//MAKE VARIABLES PRIVATE AGAIN!!!
		{
			Logger::debug("RaceTeam ", to_string(i));
			RaceTrack* raceTrack = new RaceTrack("Albert Park", RaceTrack::clockwise, 1200.0, 10.09, 1200.0, 17, 20);
			raceTrack->setBestLapTime(60.00);
			cout << "RaceTrackBest Time: " << raceTrack->getBestLapTime() <<endl;
			raceTeams[i]->decideNextStrategy(grandPrixs[0]);
			cout<<" team lap Time: " << raceTeams[i]->getDriverLapTime(0, raceTrack) << endl;
		}

		while (true) {}
		return 0;
		//DELETE ME!!
*/

/*

		//test to see if the RaceTracks were created
		/*
		circuit->determineMaxValues();
		circuit->determineMinValues();
		cout << endl << endl;
		circuit->print();
		cout << endl << endl;
		*/
