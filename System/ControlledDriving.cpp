#include "ControlledDriving.h"

ControlledDriving::ControlledDriving() :Driver() {
	this->type = "Controlled";
	setAggression(60);
}

ControlledDriving::ControlledDriving(string name, float error) : Driver(name, 60, error) {
	this->type = "Controlled";
}

ControlledDriving::ControlledDriving(Driver* d) : Driver(d->getName(), 60, d->getErrorProne()) {
	this->type = "Controlled";
}

ControlledDriving::~ControlledDriving() {
}

void ControlledDriving::displayDriver() {
	cout << "Name: " << getName() << "\tAggression: " << getAggression() << "\tLevel: Controlled" << endl;
}

string ControlledDriving::getType() {
	return type;
}
