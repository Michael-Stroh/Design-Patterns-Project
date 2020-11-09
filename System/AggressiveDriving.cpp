#include "AggressiveDriving.h"

AggressiveDriving::AggressiveDriving() :Driver() {
	this->type = "Aggressive";
}

AggressiveDriving::AggressiveDriving(string name, float error) : Driver(name, 90, error) {
	this->type = "Aggressive";
}

AggressiveDriving::AggressiveDriving(Driver* d) : Driver(d->getName(), 90, d->getErrorProne()) {
	this->type = "Aggressive";
}

AggressiveDriving::~AggressiveDriving() {
}

void AggressiveDriving::displayDriver() {
	cout << "Name: " << getName() << "\tAggression: " << getAggression() << "\tLevel: Aggressive" << endl;
}

string AggressiveDriving::getType() {
	return type;
}
