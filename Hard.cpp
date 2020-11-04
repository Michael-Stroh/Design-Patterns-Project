#include "Hard.h"

Hard::Hard(): Tyre(120,30,1.25) {
	cout << "Hard tyre created" << endl;
	this->type = "Hard";
}

Hard::Hard( int durability, int grip, float pressure ): Tyre( durability, grip, pressure) {
	cout << "Hard tyre created" << endl;
	this->type = "Hard";
}

Hard::~Hard() {

}

void Hard::usage() {
	setDurability(getDurability() /*distance of lap*/);
	setGrip(getGrip() -1);
}

string Hard::getType() {
	return this->type;
}
