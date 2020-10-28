#include "Road.h"

Road::Road() {

}

Road::Road( string RoadName ): name( RoadName ) {

}


Road::~Road() {

}

string Road::getName() {

    return name;
}

void Road::setName( string ChangeName ) {

    name = ChangeName;
}
