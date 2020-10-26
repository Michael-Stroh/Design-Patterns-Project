#include "Soft.h"

Soft::Soft() {
	setDurability(50);
	setGrip(150);
	setPressure(1.5);
	cout << "Soft tyre\tD:\t" << getDurability() << "\tG:\t" << getGrip() << "\tP:\t" << getPressure() << endl;
}

Soft::Soft(int durability, int grip, float pressure) {
	setDurability(durability);
	setGrip(grip);
	setPressure(pressure);
	cout << "Soft tyre\tD:\t" << getDurability() << "\tG:\t" << getGrip() << "\tP:\t" << getPressure() << endl;
}

void Soft::usage() {
	int durability = getDurability();
	// TODO - implement Soft::usage
	throw "Not yet implemented";
}

