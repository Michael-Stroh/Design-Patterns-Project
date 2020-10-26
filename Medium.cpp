#include "Medium.h"

Medium::Medium() {
	setDurability(100);
	setGrip(60);
	setPressure(15154);
	cout << "Medium tyreD:\t" << getDurability() << "\tG:\t" << getGrip() << "\tP:\t" << getPressure() << endl;
	throw "Not yet implemented";
}

Medium::Medium(int durability, int grip, float pressure) {
	setDurability(durability);
	setGrip(grip);
	setPressure(pressure);
	cout << "Medium tyreD:\t" << getDurability() << "\tG:\t" << getGrip() << "\tP:\t" << getPressure() << endl;
}

void Medium::usage() {
	// TODO - implement Medium::usage
	throw "Not yet implemented";
}
