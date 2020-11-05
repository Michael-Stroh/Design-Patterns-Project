#include "GrandPrix.h"
#include "RaceTeam.h"
#include "RaceSeason.h"

#include <iostream>
#include <string>
using namespace std;

int main() {

	cout << "Successful compilation" << endl;

	/*
	                ******IDEA ALGORITHM******

            //Creation
            GrandPrix** gps;
            RaceTeam** teams;
            //RaceSeason * raceSeason = new RaceSeason( teams, gps );
            RaceSeason* raceSeason = new RaceSeason();
            //Notification
            raceSeason->prepareSeason();
            //RaceLoop
            int numGrandPrixs = 0;
            for ( int i = 0; i < numGrandPrixs; ++ i ) {
                prepareForNextRace( teams, days ); //do Engineering
                raceSeason->runNextRace();        //run race
                printCurrentGrandprixResult();
            }
            raceSeason->printFinalResults();
            //deletion
            deleteEverything();
	 */
}

void prepareForNextRace( RaceTeam* team, string days ) {

    /*
    for ( int i = 0; i < numTeams; ++ i ) {

        teams[ i ]->prepareForNextRace(); //Brent strategy call once lekker
    }
     */

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////                 This is from Brent's Strategy.                                               ////////
////////            I took it out from there as it does not make sense to read it in from there       ////////
////////            I want to talk about this, if it should go there I will work on it more           ////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

string trim( string temp ) {

    string nono = "\t\n\v\f\r ";
    temp.erase(0, temp.erase(temp.find_last_not_of(nono)+1).find_first_not_of( nono ) );
    return temp;
}

void populateCircuit( const string& fileName ) {

	string line;
    ifstream file;

    file.open( fileName );
	if ( file.is_open() ) {

        while ( getline(file, line) ) {

			int pos =0;
			int size = line.size();
			string name, direction, startingDate, endingDate, euro;
			float disLap, wind = 0, longestStraight, fastestLap,averagePitStop;
			int numCorners, numLaps;


			string temp = line;

			pos = temp.find_first_of('|' );
			name = trim(temp.substr(0,pos-1));
			temp = temp.substr(pos+1, size);

			pos = temp.find_first_of('|' );
			fastestLap = stof(trim(temp.substr(0,pos-1)));
			temp = temp.substr(pos+1, size);

			pos = temp.find_first_of('|' );
			disLap = stof(trim(temp.substr(0,pos-1)));
			temp = temp.substr(pos+1, size);

			pos = temp.find_first_of('|' );
			numLaps = stoi(trim(temp.substr(0,pos-1)));
			temp = temp.substr(pos+1, size);

			pos = temp.find_first_of('|' );
			longestStraight = stof(trim(temp.substr(0,pos-1)));
			temp = temp.substr(pos+1, size);

			pos = temp.find_first_of('|' );
			numCorners = stoi(trim(temp.substr(0,pos-1)));
			temp = temp.substr(pos+1, size);

			pos = temp.find_first_of('|' );
			startingDate = trim(temp.substr(0,pos-1));
			temp = temp.substr(pos+1, size);

			pos = temp.find_first_of('|' );
			endingDate = temp.substr(0,pos-1);
			temp = temp.substr(pos+1, size);

			pos = temp.find_first_of('|' );
			averagePitStop = stof(trim(temp.substr(0,pos-1)));
			temp = temp.substr(pos+1, size);

			pos = temp.find_first_of('|' );
			euro = trim(temp.substr(0,pos-1));
			temp = temp.substr(pos+1, size);

			pos = temp.find_first_of('|' );
			direction = trim(temp.substr(0,pos-1));
			temp = temp.substr(pos+1, size);

			RaceTrack* tmp = nullptr;
			if ( direction == "clockwise" ) {

			    tmp = new RaceTrack(name, RaceTrack::direction::clockwise, disLap, wind, longestStraight, numCorners,numLaps);
			} else if ( direction == "anticlockwise" ) {

			    tmp = new RaceTrack(name, RaceTrack::direction::anticlockwise, disLap, wind,longestStraight, numCorners,numLaps);
			} else {

                Logger::cyan( "Error", "Wrong direction given.");
			}

			tmp->setStartDate( startingDate );
			tmp->setEndDate( endingDate );
			bool maybe = true;
			euro = trim( euro );

			if ( euro =="true" ) {

				maybe = true;
			} else if ( euro == "false" ) {

				maybe = false;
			} else {

                Logger::cyan( "Error", "The file not found.");
			}
			tmp->setAvgPitStops( averagePitStop );
			tmp->setEuro( maybe );
		}
    }
    else {

        Logger::cyan( "Error", "The file not found.");
    }

}
