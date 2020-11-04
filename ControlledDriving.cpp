#include "ControlledDriving.h"

ControlledDriving::ControlledDriving():Driver() {
	cout << "Controlled driving" << endl;
	setAggression(60);
}

ControlledDriving::ControlledDriving(string name, float specialMove): Driver(name, 60, specialMove){
	cout << "Controlled Driving" << endl;
}

ControlledDriving::ControlledDriving(Driver* d):Driver(d->getName(), 60, d->getSpecialMove()){
	cout << "Controlled Driving" << endl;
}

ControlledDriving::~ControlledDriving(){
}

void ControlledDriving::displayDriver() {
	cout <<"Name: "<< getName() << "\tSpecial Move: " << getSpecialMove() << "\tAggression: "<< getAggression() << "\tLevel: Controlled" << endl;
}
