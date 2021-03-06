#include "GrandPrix.h"
#include "RaceSeason.h"
#include <iostream>

//Main Helper Functions pre-declaration
void prepareForNextRace( vector<RaceTeam*>, GrandPrix* );
void endGrandPrix(vector<RaceTeam *>, GrandPrix* gp);
void printWinningTeamCar(vector<pair<string, int>>);
vector<RaceTeam* > createRaceTeams( int );
vector<RaceTeam*> makeTeamsAndDrivers();
void populateCircuit( const string& );
void createGrandPrixs();


//this will hold all the created objects
CompositeRoad* circuit;
vector< GrandPrix* > grandPrixs;
vector< RaceTeam* > raceTeams;



void printCarStatistics( CarComposite* car ) {

	float aggregateH = car->getHandling();
	float aggregateA = car->getAcceleration();
	float aggregateS = car->getSpeed();

	cout << endl;
	Logger::red("Car total Speed: ", to_string(aggregateS));
	Logger::red("Car total acceleration: ", to_string(aggregateA));
	Logger::red("Car total Handling: " ,to_string(aggregateH));
	cout << endl;
}

int main() {

    system( "Color 05" );                                                                //Needed for the Colors To Print Correctly

    ////////////////Creation////////////////

    //instantiate the CompositeRoad pointer
    circuit = new CompositeRoad();
    //call the function to read the circuits in from the file
    populateCircuit( "Data/races.txt" );


    grandPrixs = vector< GrandPrix* >();
    createGrandPrixs();
    raceTeams = makeTeamsAndDrivers();

    RaceSeason* raceSeason = new RaceSeason( grandPrixs, raceTeams );


    Logger::red( "Main: calling prepareRaceSeason", "" );
    raceSeason->prepareSeason();
    Logger::red( "Main: prepared for Season", "All Teams notified of GrandPrix Schedule" );

    //RaceLoop
    for ( int i = 0; i < grandPrixs.size(); ++ i ) {

        Logger::red( "Main: Preparing for next Race", to_string( i ) );
        prepareForNextRace( raceTeams, grandPrixs[ i ] );

        Logger::red( "Main: runnning next Race", "" );
        raceSeason->runNextGrandPrix();

        Logger::red( "Main: printing grandPrix results", "" );
        grandPrixs[ i ]->displayResult();

        Logger::red( "Main: ending grandPrix", "" );
        endGrandPrix( raceTeams, grandPrixs[ i ] );
    }

    raceSeason->getResult()->print();
    vector< pair< string, int>> vec = ( ( RaceSeasonResult* ) ( raceSeason->getResult() ) )->getTotalTeamPoints();
    printWinningTeamCar( vec );


    ////Free memory////

    //delete the circuit before the Grand Prix that holds it
    delete circuit;

    //delete the RaceSeason( Grand Prix is deleted inside here )
    Logger::customDebug("Deleting the RaceSeason");
    delete raceSeason;

    Logger::customDebug("RaceSeason and associated data deleted");

    return 0;
}

void printWinningTeamCar(vector<pair<string, int>> vec) {

	for (int i = 0; i < raceTeams.size(); ++i)
	{
		if (raceTeams[i]->getName() == vec[0].first)
		{
			Logger::red("Printing the winning Team's Car Statistics", "");
			printCarStatistics(raceTeams[i]->getCar());
			string option;
			Logger::red("Enter Y to view in depth details about the car", "---");
			cin >> option;
			if (option == "Y" || option == "y")
				raceTeams[i]->getCar()->print();
		}
	}
}

void createGrandPrixs() {

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

	//Free memory
    delete it;
}

vector<RaceTeam* > createRaceTeams( int numberOfTeams ) {

    //Backup Function
	vector<RaceTeam*> vec;

	vec.reserve(numberOfTeams);
    for ( int i = 0; i < numberOfTeams; ++i ) {

        vec.push_back( new RaceTeam() );
	}

	return vec;
}

void prepareForNextRace( vector<RaceTeam*> team, GrandPrix * gp ) {

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

void endGrandPrix(vector<RaceTeam *> team, GrandPrix * gp) {

	for (int i = 0; i < team.size(); ++i) {

	    team[i]->endOfGrandPrix(gp->getCircuit()->getName());
	}
}

string trim( string line ) {

	return line.erase( 0, line.erase( line.find_last_not_of( "\t\n\v\f\r " ) + 1 ).find_first_not_of( "\t\n\v\f\r " ) );
}

vector<RaceTeam*> makeTeamsAndDrivers() {

	vector<RaceTeam*> teams;
	string line;
	ifstream file;

	bool changer = false;
	vector<Driver*> temp;

	file.open("Data/driver.txt");   //changed from ../Data
	if (file.is_open()) {
		Logger::debug("MakeDrivers and Teams", "File opened correctly");
		while (getline(file, line)) {

			int pos, size = line.size();

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

		circuit->determineMaxValues();
		circuit->determineMinValues();
		cout << endl << endl;
		circuit->print();
		cout << endl << endl;
*/
