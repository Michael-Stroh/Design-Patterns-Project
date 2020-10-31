#include "Circuit.h"
#include "RaceTrack.h"
#include "CompositeRoad.h"

#include "iostream"

int main() {


    //Test RaceTrack class
        //can at least a single road be made
    Road* jack = new RaceTrack( "Bob", 2.1, 5.6, 2.666 );

    //Check if the correct details are printed
    jack->print();

    cout << endl << endl << endl;


    //Test CompositeRoad class
        //can a group of roads be made
    auto* track = new CompositeRoad( "Race One" );

    track->addRoad( new RaceTrack( "Bob", 2.1, 5.6, 2.666 ) );
    track->addRoad( new RaceTrack( "SS", 4.2, 2.7, 4.858 ) );
    track->addRoad( new RaceTrack( "Ko", 3.3, 2.8, 7.222 ) );
    track->addRoad( new RaceTrack( "Name", 2.4, 2.9, 1.334865 ) );

    //Check if all the correct details are printed
    track->print();

    //check if delete is working
    track->removeRoad( "Bob" );

    //Check if all the correct details are printed
    track->print();
}
