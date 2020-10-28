#include "Medium.h"

Medium::Medium(): Tyre(90,60,1.25) {
	cout << "Medium tyre created" << endl;
}

Medium::Medium( int durability, int grip, float pressure ): Tyre( durability, grip, pressure ) {
	cout << "Medium tyre created" << endl;
}

Medium::~Medium() {

}

void Medium::usage() {
	setDurability(getDurability() /*distance of lap*/);
	setGrip(getGrip() -1);
}
