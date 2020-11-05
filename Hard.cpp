#include "Hard.h"

Hard::Hard(): Tyre(120,30,1.25) {
	this->type = "Hard";
}

Hard::Hard( int durability, int grip, float pressure ): Tyre( durability, grip, pressure) {
	this->type = "Hard";
}

Hard::~Hard() {

}

void Hard::usage(int distance) {
	setDurability(getDurability() / distance);
	setGrip(getGrip() -1);
}

string Hard::getType() {
	return this->type;
}
