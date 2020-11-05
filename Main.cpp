#include "GrandPrix.h"
#include "RaceTeam.h"
#include "RaceSeason.h"

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


void populateCircuit( const string& fileName ) {

	ifstream file;

	file.open( "../Data/races.txt" );
	file.open( fileName );
	if ( file.is_open() ) {

		string line;
		while ( getline( file, line ) ) {

			int pos = 0;
			int size = line.size();
			cout << size << endl;
			string temp = line;

			for ( int i = 0; i < 10; i++ ) {

				pos = temp.find_first_of( '|' );
				cout << temp.substr( 1, pos - 1 ) << endl;
				temp = temp.substr( pos + 1, size );
			}
		}
	} else {
		cout << "file not found" << endl;
	}

	file.close();


	/*


	 	string line;
    ifstream file;

	file.open("../Data/races.txt");
	if (file.is_open()) {
        while (getline(file, line)) {
			int pos =0;
			int size = line.size();
			string name, direction, startingDate, endingDate, euro;
			float disLap, wind, longestStraight, fastestLap,averagePitStop;
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

			RaceTrack* tmp;
			if(direction == "clockwise"){
				tmp = new RaceTrack(name, RaceTrack::direction::clockwise, disLap, wind, longestStraight, numCorners,numLaps);
			}else if (direction == "anticlockwise"){
				tmp = new RaceTrack(name, RaceTrack::direction::anticlockwise, disLap, wind,longestStraight, numCorners,numLaps);
			}else{
				cout << "Error: " << direction << endl;
			}
			tmp->setStartDate(startingDate);
			tmp->setEndDate(endingDate);
			bool maybe;
			euro = trim(euro);
			if(euro =="true"){
				maybe = true;
			}else if(euro == "false"){
				maybe = false;
			}else{
				cout << "Error: "<< euro << endl;
			}
			tmp->setAvgPitStops(averagePitStop);
			tmp->setEuro(maybe);
			races.push_back(tmp);
		}
    }
    else {
        cout << "file not found" << endl;
    }

	*/

}