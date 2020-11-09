#include "CautiousDriving.h"

CautiousDriving::CautiousDriving() :Driver() {
	this->type = "Cautious";
	setAggression(30);
}


CautiousDriving::CautiousDriving(string name, float error) : Driver(name, 30, error) {
	this->type = "Cautious";
}

CautiousDriving::CautiousDriving(Driver* d) : Driver(d->getName(), 30, d->getErrorProne()) {
	this->type = "Cautious";
}

CautiousDriving::~CautiousDriving() {
}

void CautiousDriving::displayDriver() {
	cout << "Name: " << getName() << "\tAggression: " << getAggression() << "\tLevel: Cautious" << endl;
}

string CautiousDriving::getType() {
	return type;
}

