#include "CautiousDriving.h"

CautiousDriving::CautiousDriving():Driver() {
	cout << "Cautious driving" << endl;
}


CautiousDriving::CautiousDriving(string name, float specialMove): Driver(name, 30, specialMove){
	cout << "Cautious Driving" << endl;
}

CautiousDriving::CautiousDriving(Driver* d): Driver(d->getName(), 30, d->getSpecialMove()){
	cout << "Cautious Driving" << endl;
}

CautiousDriving::~CautiousDriving(){
}


void CautiousDriving::displayDriver(){
	 cout <<"Name: "<< getName() << "\tSpecial Move: " << getSpecialMove() << "\tAggression: "<< getAggression() << "\tLevel: Cautious" << endl;
}
