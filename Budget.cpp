#include "Budget.h"

Budget::Budget() {

	// TODO - implement Budget::Budget
	throw "Not yet implemented";
}

Budget::Budget( float max ): balance( max ) {

	// TODO - implement Budget::Budget
	throw "Not yet implemented";
}

Budget::~Budget() {

	// TODO - implement Budget::~Budget
	throw "Not yet implemented";
}

void Budget::attach( EngineeringDepartment* observer ) {

	// TODO - implement Budget::attach
	throw "Not yet implemented";
}

void Budget::detach( EngineeringDepartment* e ) {

	// TODO - implement Budget::detach
	throw "Not yet implemented";
}

void Budget::notifyAll() {

	// TODO - implement Budget::notifyAll
	throw "Not yet implemented";
}

float Budget::getBudget() {

	return balance;
}

void Budget::setBudget( float amount ) {

	balance = amount;
}
