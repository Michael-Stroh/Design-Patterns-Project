#include "Medium.h"

Medium::Medium(): Tyre(90,60,1.25) {
<<<<<<< HEAD

	cout << "Medium tyre created" << endl;
=======
>>>>>>> BrentsBranch
	this->type = "Medium";
}

Medium::Medium( int durability, int grip, float pressure ): Tyre( durability, grip, pressure ) {
<<<<<<< HEAD

	cout << "Medium tyre created" << endl;
=======
>>>>>>> BrentsBranch
	this->type = "Medium";
}

Medium::~Medium() {

}

void Medium::usage() {

	setDurability(getDurability() /*distance of lap*/);
=======
void Medium::usage(int distance) {
	setDurability(getDurability() / distance);
>>>>>>> BrentsBranch
	setGrip(getGrip() -1);
}
