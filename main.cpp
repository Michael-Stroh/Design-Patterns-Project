#include <iostream>
#include <string>

#include "Circuit.h"
#include "CompositeRoad.h"
#include "RaceTrack.h"
#include "CircuitIterator.h"
#include "Iterator.h"

#include "CautiousDriving.h"
#include "ControlledDriving.h"
#include "AggressiveDriving.h"
#include "DriverStrategy.h"
#include "Driver.h"
#include "RaceStrategy.h"

#include "Soft.h"
#include "Medium.h"
#include "Hard.h"
#include "Tyre.h"
#include "TyreStrategy.h"

#include "PitStop.h"
#include "PitStopStrategy.h"

using namespace std;

int main()
{
	cout << "make a race" << endl;

   	//Test RaceTrack class
    //can at least a single road be made
	Circuit *jack = new RaceTrack( "Bob", 2.1, 5.6 );

    //Check if the correct details are printed
	jack->print();

	cout << endl << endl << endl;
	
	 auto *track = new CompositeRoad( "Race One" );

     track->addRoad( new RaceTrack( "Bob", 2.1, 5.6 ) );
     track->addRoad( new RaceTrack( "SS", 4.2, 2.7 ) );
     track->addRoad( new RaceTrack( "Ko", 3.3, 2.8 ) );
     track->addRoad( new RaceTrack( "Name", 2.4, 2.9 ) );


	Iterator *stop = jack->createIterator();


	cout << "fake race for strategy tests" << endl;
	cout << "------------------------------------------------" << endl;
	
	Driver* speedster = new AggressiveDriving("Brent", (float)64);
	RaceStrategy* rs = new RaceStrategy(speedster, track->getRoad(0));
	TyreStrategy* ts = rs->getTyreStrategy();
	ts->print();
	DriverStrategy* ds = rs->getDriverStrategy();
	PitStopStrategy* ps = rs->getPitStopStrategy();

	return 0;
}


