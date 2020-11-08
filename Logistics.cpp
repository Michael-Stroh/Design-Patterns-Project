#include "Logistics.h"

Logistics::Logistics( string name, bool euro ) {
	this->name = name;
	this->isEuropean = euro;
	
	this->garage = new Container();
	this->catering = new Container();
	this->carComponents =  new Container();
	
	if(isEuropean){
		Logger::yellow("Containers are been trucked to Location", "Location: " + name);					//added by Tim since file issues for Brent prevented this use
		//cout<< "Containers are been trucked to "  << name<< endl;			//Add this again eventually 
	}else{
		Logger::yellow("Containers are been shipped to Location", "Location: " + name);
		//cout << "Containers are been shipped to " << name << endl;
	}
}

Logistics::~Logistics() {
	delete garage;
	delete catering;
	delete carComponents;
}

string Logistics::getName(){
	return name;
}
