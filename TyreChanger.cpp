#include "TyreChanger.h"

TyreChanger::TyreChanger(): PitCrew() {

}

TyreChanger::~TyreChanger() {
	delete newTyre;
}

TyreStrategy * TyreChanger::replacePart(TyreStrategy * tyre) {

	
	newTyre = myPitStop->changeTyre(tyre);
	return newTyre;
}

TyreStrategy * TyreChanger::getNewTyre()
{
	return newTyre;
}
