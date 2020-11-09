#include "DriverStrategy.h"

DriverStrategy::DriverStrategy() {

}

DriverStrategy::DriverStrategy(Driver* d) {
	this->raceDriver = d;
}

DriverStrategy::DriverStrategy(TyreStrategy* tyre) {
	this->tyreStrategy = tyre;
}

DriverStrategy::~DriverStrategy() {
	drivers.clear();
	delete raceDriver;
	delete tyreStrategy;
}

vector<Driver*> DriverStrategy::decideStrategy() {
	vector<Tyre*> tyres = tyreStrategy->getTyres();
	int size = (int)tyres.capacity();

	vector<Driver*> drive;
	drive.reserve(size);
	Driver* temp;

	for (int i = 0; i < size; i++) {
		string type = tyres.at(i)->getTyreType();
		if (type == "Soft") {
			temp = new AggressiveDriving(raceDriver);
			drive.push_back(temp);
		}
		else if (type == "Medium") {
			temp = new ControlledDriving(raceDriver);
			drive.push_back(temp);
		}
		else if (type == "Hard") {
			temp = new CautiousDriving(raceDriver);
			drive.push_back(temp);
		}
		else {
			cout << "error" << endl;
		}
	}
	drivers = drive;
	changeStrategy(drivers.back()->getType());
	return drive;
}

void DriverStrategy::displayDriver() {
	raceDriver->displayDriver();
	for (int i = 0; i < tyreStrategy->getNumPits(); i++) {
		drivers.at(i)->displayDriver();
	}
	cout << endl;
}

Driver* DriverStrategy::getDriver() {
	return raceDriver;
}


void DriverStrategy::setDriver(Driver* d) {
	//delete raceDriver;
	this->raceDriver = d;
}

void DriverStrategy::changeStrategy() {
	if (drivers.size() != 0) {
		Driver* temp = drivers.back();
		string change = temp->getName() + " changed strategy from: " + raceDriver->getType() + " to: " + temp->getType();
		Logger::yellow("DriverStrategy - changeStrategy", change);
		changeStrategy(temp->getType());
		drivers.pop_back();
	}
}

void DriverStrategy::changeStrategy(string type) {
	cout << type << endl;
	if (type == "Aggressive") {
		setDriver(new AggressiveDriving(raceDriver));
	}
	else if (type == "Controlled") {
		setDriver(new ControlledDriving(raceDriver));
	}
	else {
		setDriver(new CautiousDriving(raceDriver));
	}
}

void DriverStrategy::lapChanges(bool good) {
	int increment;
	if (raceDriver->getType() == "Aggressive") {
		increment = 3;
	}
	else if (raceDriver->getType() == "Cautious") {
		increment = 2;
	}
	else {
		increment = 1;
	}

	if (good == true) {
		increment = increment * -1;
	}

	if (raceDriver->getAggression() + increment <= 100 && raceDriver->getAggression() + increment >= 0) {
		raceDriver->setAggression(raceDriver->getAggression() + increment);

		if (raceDriver->getAggression() >= 90 && raceDriver->getType() != "Aggressive") {
			changeStrategy("Aggressive");
		}
		else if (raceDriver->getAggression() >= 60 && raceDriver->getType() != "Controlled") {
			changeStrategy("Controlled");
		}
		else if (raceDriver->getAggression() >= 30 && raceDriver->getType() != "Cautious") {
			changeStrategy("Cautious");
		}
	}
}

void DriverStrategy::changeAggressionDueToPositions(int amount)
{
	if (raceDriver->getAggression() + amount <= 100 && raceDriver->getAggression() + amount >= 0) {
		raceDriver->setAggression(raceDriver->getAggression() + amount);
		if (raceDriver->getAggression() >= 90 && raceDriver->getType() != "Aggressive") {
			changeStrategy("Aggressive");
		}
		else if (raceDriver->getAggression() >= 60 && raceDriver->getType() != "Controlled") {
			changeStrategy("Controlled");
		}
		else if (raceDriver->getAggression() >= 30 && raceDriver->getType() != "Cautious") {
			changeStrategy("Cautious");
		}
	}
}









