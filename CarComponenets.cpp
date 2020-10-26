#include "CarComponenets.h"

CarComponenets::CarComponenets(): Container() {
	// TODO - implement CarComponenets::CarComponenets
	throw "Not yet implemented";


}

CarComponenets::CarComponenets( string details ): Container() {

    this->stored = details;
}

CarComponenets::~CarComponenets() {

}

string CarComponenets::getComponents() {

	return this->stored;
}

