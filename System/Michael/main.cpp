#include "../RaceTrack.h"
#include "../CompositeRoad.h"   //changed to allow compilation on Tim's machine (added ../)
#include "../CircuitIterator.h"
#include "../Circuit.h"

#include <iostream>
#include <fstream>


void createGrandPrixs();
void test1();
void test2();
CompositeRoad* circuit;


int main() {

    //instantiate the CompositeRoad pointer
    circuit = new CompositeRoad();

    //test created RaceTrack items
    test1();

    //instantiate the CompositeRoad pointer
    circuit = new CompositeRoad();

    //test RaceTracks rad in from a file
    test2();
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

void test1() {

    ////////Test RaceTrack class////////

        //can at least a single road be made
    RaceTrack* singleRoad = new RaceTrack( "Bob", 2.1, 5.6 );

    cout << "Currently testing " + singleRoad->getName() << endl;

    //Check if the correct details are printed
    singleRoad->print();

    //see if you can change details
    singleRoad->setName( "Bob's road" );
    singleRoad->setDistance( 77 );
    singleRoad->setWindForce( 8.0 );

    //Check if the correct details are updated
    singleRoad->print();

    //free the memory
    delete singleRoad;

    cout << endl << endl << endl;

    ////////Test CompositeRoad class////////

        //can a group of roads be made
    circuit = new CompositeRoad( "Race One" );

    //Add them to the CompositeRoad
    circuit->addRoad( new RaceTrack( "Bob's Road", 2.1, 5.6 ) );
    circuit->addRoad( new RaceTrack( "South Road", 4.2, 2.7 ) );
    circuit->addRoad( new RaceTrack( "Coral Street", 3.3, 2.8 ) );
    circuit->addRoad( new RaceTrack( "Long Road", 2.4, 2.9 ) );

    //Check if all the correct details are printed
    circuit->print();

    cout << endl << endl << endl;

    //check if delete is working when the name does not exist
    circuit->removeRoad("Bob");
    //check if delete is working
    circuit->removeRoad("Bob's Road");

    //Check if all the correct details are printed
    circuit->print();

    //Create an iterator and set it to the first value
    Iterator* it = circuit->createIterator();
    it->first();

    //continue going through until we have traversed all the items
    while ( !it->isDone() ) {

        //get the current RaceTrack and print out the details
         it->currentItem()->print();

        //go to the next item in the iterator
        it->next();
    }

    //free the memory
    delete it;
    delete circuit;
}

void test2() {

    //call the function to read the circuits in from the file
    populateCircuit("Data/races.txt" );

    //Check to see the Min and Max values created
    circuit->determineMaxValues();
    circuit->determineMinValues();

    cout << endl << endl;

    //print out every RaceTrack in the Circuit
    circuit->print();

    cout << endl << endl;

    //Free the memory
    delete circuit;
}