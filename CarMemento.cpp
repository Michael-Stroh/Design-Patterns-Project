#include "CarMemento.h"

CarMemento::CarMemento() {
	// TODO - implement CarMemento::CarMemento
	throw "Not yet implemented";
}

State * CarMemento::getState() {
	return this->state;
}

void CarMemento::setState(State * state) {
	this->state = state;
}
