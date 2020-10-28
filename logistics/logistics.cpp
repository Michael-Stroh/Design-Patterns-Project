#include "Logistics.h"

Logistics::Logistics(string name) {
	this->name = name;
}

Logistics::Logistics( string name, bool euro ) {
	this->name = name;
	this->euro = euro;
	
	this->garage = new Container();
	this->catering = new Container();
	this->carComponents =  new Container();
	
	if(euro){
		cout<< "Containers are been trucked to "  << name<< endl;
	}else{
		cout << "Containers are been shipped to " << name << endl;
	}
}

Logistics::~Logistics() {
	delete garage;
	delete catering;
	delete carComponents;
}
