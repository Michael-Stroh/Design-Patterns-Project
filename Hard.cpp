#include "Hard.h"

Hard::Hard() {
	setDurability(150);
	setGrip(50);
	setPressure(1.234);
	cout << "Hard tyre\tD:\t" << getDurability() << "\tG:\t" << getGrip() << "\tP:\t" << getPressure() << endl;

}

Hard::Hard(int durability, int grip, float pressure) {
	setDurability(durability);
	setGrip(grip);
	setPressure(pressure);
	cout << "Hard tyre\tD:\t" << getDurability() << "\tG:\t" << getGrip() <<"\tP:\t" <<getPressure() << endl;
}

void Hard::usage() {
	// TODO - implement Hard::usage
	throw "Not yet implemented";
}
