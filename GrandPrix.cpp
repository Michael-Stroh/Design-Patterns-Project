#include "GrandPrix.h"

GrandPrix::GrandPrix()
{
	this->circuit = NULL;
	this->race = new Race();
	this->result = new GrandPrixResult();
}

GrandPrix::GrandPrix(Circuit *)
{
	throw "Not yet implemented";
}

Result *GrandPrix::runGrandPrix(RaceTeam *teams)
{
	throw "Not yet implemented";
}

void GrandPrix::displayResult()
{
	throw "Not yet implemented";
}

void GrandPrix::setCircuit(Circuit *)
{
	throw "Not yet implemented";
}
