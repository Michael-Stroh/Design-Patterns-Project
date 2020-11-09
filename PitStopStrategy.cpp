#include "PitStopStrategy.h"


PitStopStrategy::PitStopStrategy() {
	tyre = new TyreStrategy();
}

PitStopStrategy::PitStopStrategy(TyreStrategy* tyreStrat) {
	tyre = tyreStrat;
	tyre->setTyres(tyreStrat->getTyres());
	//tyre->print();

}

PitStopStrategy::~PitStopStrategy() {
	delete tyre;
}

void PitStopStrategy::setTyreStrategy(TyreStrategy* tyreStrat)
{
	tyre->setTyres(tyreStrat->getTyres());
}

TyreStrategy* PitStopStrategy::getTyreStrategy()
{
	return tyre;
}

bool PitStopStrategy::CheckForPitStop(int currentLap) {
	int* pits = tyre->getPitLaps();
	for (int i = 0; i < tyre->getNumPits(); i++) {
		if (pits[i] == currentLap) {
			return true;
		}
	}
	return false;
}


void PitStopStrategy::CallPitStop() {

	PitStop* newCarStop = new CarStop();
	TyreChanger* tyreChanger = new TyreChanger();
	string tmp = "Previous tyre: " + tyre->getTyres().back()->getTyreType();
	(tyreChanger->getNewTyre())->setTyres(tyre->getTyres());

	tyreChanger->registerAtPitStop(newCarStop);

	newCarStop->setPitStop(tyreChanger->getPitStop());


	this->setTyreStrategy(tyreChanger->replacePart(tyre));
	tmp += " New Tyre: " + tyre->getTyres().back()->getTyreType();

	Logger::green("PitStopStrategy", tmp);
	delete newCarStop;
	delete tyreChanger;
}


