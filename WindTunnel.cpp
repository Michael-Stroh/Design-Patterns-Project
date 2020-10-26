#include "WindTunnel.h"

WindTunnel::WindTunnel(): Simulation() {

	// TODO - implement WindTunnel::WindTunnel
	throw "Not yet implemented";
}

WindTunnel::~WindTunnel() {

}

Simulation* WindTunnel::simulate( CarComposite* car, Driver* driver ) {

	// TODO - implement WindTunnel::simulate
	throw "Not yet implemented";
}

int WindTunnel::getUsage() {

	return this->usage;
}

void WindTunnel::setUsage( int used ) {

	usage = used;
}

int WindTunnel::getAllowedUsage() {

	return usageAllowed;
}

void WindTunnel::setAllowedUsage( int allowedUsed ) {

	usageAllowed = allowedUsed;
}
