#include "Circuit.h"

Circuit::Circuit(): road() {

}

Circuit::Circuit( Road* StartRoad ): road( StartRoad ) {

}

Circuit::~Circuit() {

    delete road;
}
