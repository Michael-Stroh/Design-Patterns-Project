#include "Soft.h"

Soft::Soft(): Tyre( 60, 100, 1.2 ){


}

Soft::Soft( int durability, int grip, float pressure ): Tyre( durability, grip, pressure ) {

	cout << "Soft tyre created" << endl;
	this->type = "Soft";
}

Soft::~Soft() {

}

void Soft::usage( int distance ) {

    setDurability(getDurability() / distance);
	setGrip(getGrip() -1);

}
