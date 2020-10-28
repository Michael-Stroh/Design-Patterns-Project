#include "Soft.h"

Soft::Soft(): Tyre(60, 100, 1.2) {
	cout << "soft tyre created" << endl;
}

Soft::Soft( int durability, int grip, float pressure ): Tyre( durability, grip, pressure ) {
	cout << "soft tyre created" << endl;
}

Soft::~Soft() {

}

void Soft::usage() {
	setDurability(getDurability() /*distance of lap*/);
	setGrip(getGrip() -1);
}
