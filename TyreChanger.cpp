#include "TyreChanger.h"

TyreChanger::TyreChanger() : PitCrew() {
	newTyre = new TyreStrategy();
}

TyreChanger::~TyreChanger() {
	delete newTyre;
}

TyreStrategy* TyreChanger::replacePart(TyreStrategy* tyre) {


	//cout<<"changing tyres from: "<<tyre->printLast()<<" to: ";

	newTyre->setTyres(myPitStop->changeTyre(tyre)->getTyres());

	return newTyre;
}

TyreStrategy* TyreChanger::getNewTyre()
{
	return newTyre;
}
