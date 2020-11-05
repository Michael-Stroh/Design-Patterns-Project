#include "DriverStrategy.h"

DriverStrategy::DriverStrategy() {
	
}

DriverStrategy::DriverStrategy(Driver* d) {
	this->raceDriver = d;
}

DriverStrategy::DriverStrategy(TyreStrategy* tyre){
	this->tyreStrategy = tyre;
}

DriverStrategy::~DriverStrategy(){
	drivers.clear();
	delete raceDriver;
	delete tyreStrategy;
}

vector<Driver*> DriverStrategy::decideStrategy(){
	
	vector<Tyre*> tyres = tyreStrategy->getTyres();
	int size = (int) tyres.capacity();
	
	vector<Driver*> drive;
	drive.reserve(size);
	Driver* temp;
	
	for( int i = 0 ; i < size; i++ ){
		string type = tyres.at(i)->getType();
		if( type == "Soft" ){
			temp = new AggressiveDriving(raceDriver);
			drive.push_back(temp );
		}else if( type == "Medium" ){
		 	temp = new ControlledDriving(raceDriver);
		 	drive.push_back(temp);
		}else if( type == "Hard" ) {
		 	temp = new CautiousDriving(raceDriver);
		 	drive.push_back(temp);
		}else{
			cout << "error" << endl;
		}
	}
	drivers = drive;
	return drive;
}

void DriverStrategy::displayDriver() {
	cout << "Orginal:" << endl;
	raceDriver->displayDriver();
	cout << "Driver strategy: " << endl;
	for( int i =0; i < tyreStrategy->getNumPits(); i++){
		drivers.at(i)->displayDriver();
	}
	cout << endl;
}

Driver* DriverStrategy::getDriver(){
	return raceDriver;
}


void DriverStrategy::setDriver(Driver* d){
	this->raceDriver = d;
}

void DriverStrategy::changeStrategy(){
	drivers.pop_back();
	this->drivers = drivers;
}









