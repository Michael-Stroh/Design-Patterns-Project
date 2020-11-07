#include "Hard.h"

Hard::Hard(): Tyre( 120,30,1.25 ) {

	cout << "Hard tyre created" << endl;
    setType( "Hard" );
}

Hard::Hard( int durability, int grip, float pressure ): Tyre( durability, grip, pressure ) {

	cout << "Hard tyre created" << endl;
    setType( "Hard" );
}

Hard::~Hard() {

}

void Hard::usage(float track) {
    setDurability(getDurability() - (int)ceil(track));
    setGrip(getGrip() - 1);
    if (getDurability() <= 0) {
        //dead 
    }
}

string Hard::getType() {
    return type;
}