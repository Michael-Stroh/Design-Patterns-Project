#include "Soft.h"

Soft::Soft(): Tyre( 50, 40, 1.25 ){


}

Soft::Soft( int durability, int grip, float pressure ): Tyre( durability, grip, pressure ) {

	cout << "Soft tyre created" << endl;
	this->type = "Soft";
}

Soft::~Soft() {

}

void Soft::usage() {

	setDurability(getDurability() /*distance of lap*/);
	setGrip(getGrip() -1);

}
