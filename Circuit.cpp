#include "Circuit.h"

Circuit::Circuit() {

}

Circuit::Circuit( string RoadName ): name( RoadName ) {

}


Circuit::~Circuit() {

}

string Circuit::getName() {

    return name;
}

void Circuit::setName( string ChangeName ) {

    name = ChangeName;
}
