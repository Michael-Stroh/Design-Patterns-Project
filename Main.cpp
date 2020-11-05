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


}