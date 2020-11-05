#include "Soft.h"

Soft::Soft(): Tyre( 50, 40, 1.25 ){


}

Soft::Soft( int durability, int grip, float pressure ): Tyre( durability, grip, pressure ) {

	// TODO - implement Soft::Soft

}

Soft::~Soft() {

}

void Soft::usage() {

	setDurability(getDurability() /*distance of lap*/);
	setGrip(getGrip() -1);

}

string Soft::getType() {

	return this->type;
}
