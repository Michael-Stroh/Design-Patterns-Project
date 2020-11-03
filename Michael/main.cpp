#include "RaceTrack.h"
#include "CompositeRoad.h"
#include "CircuitIterator.h"

#include "iostream"

int main() {

     //Test RaceTrack class
        //can at least a single road be made
     Circuit *jack = new RaceTrack( "Bob", 2.1, 5.6 );

     //Check if the correct details are printed
     jack->print();

     cout << endl << endl << endl;

     //Test CompositeRoad class
        //can a group of roads be made
     auto *track = new CompositeRoad( "Race One" );

     track->addRoad( new RaceTrack( "Bob", 2.1, 5.6 ) );
     track->addRoad( new RaceTrack( "SS", 4.2, 2.7 ) );
     track->addRoad( new RaceTrack( "Ko", 3.3, 2.8 ) );
     track->addRoad( new RaceTrack( "Name", 2.4, 2.9 ) );

     //Check if all the correct details are printed
     track->print();

     cout << endl << endl << endl;
     //check if delete is working
     track->removeRoad("Bob");

     //Check if all the correct details are printed
     track->print();

     Iterator *stop = jack->createIterator();

     delete track;
}
