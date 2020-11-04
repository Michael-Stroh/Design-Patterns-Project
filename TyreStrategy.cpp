#include "TyreStrategy.h"

TyreStrategy::TyreStrategy() {

	// TODO - implement TyreStrategy::TyreStrategy
	throw "Not yet implemented";
}

TyreStrategy::~TyreStrategy() {

}

vector<Tyre*> TyreStrategy::getTyres() {

	return tyres;
}

void TyreStrategy::setTyres( vector< Tyre* > newTyre ) {

	tyres = newTyre;
}
