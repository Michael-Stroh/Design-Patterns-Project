#include "Soft.h"

Soft::Soft(): Tyre( 60, 100, 1.2 ){

    cout << "Soft tyre created" << endl;
    setType( "Soft" );
}

Soft::Soft( int durability, int grip, float pressure ): Tyre( durability, grip, pressure ) {

	cout << "Soft tyre created" << endl;
    setType( "Soft" );
}

Soft::~Soft() {

}
