#include "Medium.h"

Medium::Medium(): Tyre( 90,60,1.25 ) {

	cout << "Medium tyre created" << endl;
	setType( "Medium" );
}

Medium::Medium( int durability, int grip, float pressure ): Tyre( durability, grip, pressure ) {

	cout << "Medium tyre created" << endl;
    setType( "Medium" );
}

Medium::~Medium() {

}

void Medium::usage(float track) {
    setDurability(getDurability() - (int)ceil(track));
    setGrip(getGrip() - 2);
    if (getDurability() <= 0) {
        //dead 
    }
}

string Medium::getType() {
    return type;
}
