#include "Medium.h"

Medium::Medium(): Tyre(90,60,1.25) {
	this->type = "Medium";
}

Medium::Medium( int durability, int grip, float pressure ): Tyre( durability, grip, pressure ) {
	this->type = "Medium";
}

Medium::~Medium() {

}

void Medium::usage(int distance) {
	setDurability(getDurability() / distance);
	setGrip(getGrip() -1);
}

string Medium::getType() {
	return this->type;
}
