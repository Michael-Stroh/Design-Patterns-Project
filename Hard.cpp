#include "Hard.h"

Hard::Hard(): Tyre(120,30,1.25) {
<<<<<<< HEAD

	cout << "Hard tyre created" << endl;
=======
>>>>>>> BrentsBranch
	this->type = "Hard";
}

Hard::Hard( int durability, int grip, float pressure ): Tyre( durability, grip, pressure) {
<<<<<<< HEAD

	cout << "Hard tyre created" << endl;
=======
>>>>>>> BrentsBranch
	this->type = "Hard";
}

Hard::~Hard() {

}

<<<<<<< HEAD
void Hard::usage() {

	setDurability(getDurability() /*distance of lap*/);
=======
void Hard::usage(int distance) {
	setDurability(getDurability() / distance);
>>>>>>> BrentsBranch
	setGrip(getGrip() -1);
}
