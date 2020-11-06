#include "Soft.h"

Soft::Soft(): Tyre( 60, 90, 1.2 ){
    setType( "Soft" );
}

Soft::Soft( int durability, int grip, float pressure ): Tyre( durability, grip, pressure ) {
    setType( "Soft" );
}

string Soft::getType() {
    return type;
}

Soft::~Soft() {

}

void Soft::usage(float track) {
    setDurability(getDurability() - (int)ceil(track));
    setGrip(getGrip() - 3);
    if (getDurability() <= 0) {
        //dead 
    }
}
