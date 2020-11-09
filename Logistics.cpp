#include "Logistics.h"

Logistics::Logistics(string name, bool euro) {
	this->name = name;
	this->isEuropean = euro;

	this->garage = new Container();
	this->catering = new Container();
	this->carComponents = new Container();

	if (isEuropean) {
		Logger::yellow("Containers are been trucked to Location", "Location: " + name);					//added by Tim since file issues for Brent prevented this use
	}
	else {
		Logger::yellow("Containers are been shipped to Location", "Location: " + name);
	}
}

Logistics::~Logistics() {
	delete garage;
	delete catering;
	delete carComponents;
}

string Logistics::getName() {
	return name;
}
