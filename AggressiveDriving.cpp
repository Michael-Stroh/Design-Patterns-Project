#include "AggressiveDriving.h"

AggressiveDriving::AggressiveDriving():Driver() {
cout << "Aggressive" << endl;
}

AggressiveDriving::AggressiveDriving(string name, float specialMove): Driver(name, 90, specialMove){
	cout << "Aggressive" << endl;
}

AggressiveDriving::AggressiveDriving(Driver* d): Driver(d->getName(), 90, d->getSpecialMove()){
	cout << "Aggressive" << endl;
}

AggressiveDriving::~AggressiveDriving(){
}

void AggressiveDriving::displayDriver() {
	cout <<"Name: "<< getName() << "\tSpecial Move: " << getSpecialMove() << "\tAggression: "<< getAggression() << "\tLevel: Aggressive" << endl;
}
