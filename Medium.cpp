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
