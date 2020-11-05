#include "PitStopStrategy.h"

PitStopStrategy::PitStopStrategy(): tyres( new TyreStrategy() ), currentLap( 0 ), ps( new PitStop() ) {

}

PitStopStrategy::PitStopStrategy( TyreStrategy* tyreStart ): tyres( tyreStart ), currentLap( 0 ), ps( new PitStop() ) {

}

PitStopStrategy::~PitStopStrategy() {

	delete tyres;
}


bool PitStopStrategy::CheckForPitStop() {

	/*int* pits = tyres->getPitLaps();
	cout << tyres->getNumPits() << endl;

	for ( int i = 0; i < tyres->getNumPits(); i++ ){

		if ( pits[ i ] == currentLap ) {

            return true;

		}
	}*/
	return false;
}

void PitStopStrategy::CallPitStop() {

	ps->changeTyre( tyres );
}

void PitStopStrategy::IncrementLap(){

	this->currentLap = currentLap + 1;
}

void PitStopStrategy::setLap( int i ){

	this->currentLap = i;
}

int PitStopStrategy::getLap(){

	return currentLap;
}
