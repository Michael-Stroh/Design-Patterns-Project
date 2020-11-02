#include "CircuitIterator.h"

CircuitIterator::CircuitIterator(): Iterator() {


}

CircuitIterator::CircuitIterator( CompositeRoad* track ): Iterator(), array( track ) {


}

CircuitIterator::~CircuitIterator() {

}

void CircuitIterator::first() {

    index = 0;
}

void CircuitIterator::next() {

    index++;
}

bool CircuitIterator::isDone() {

    return ( array->getSize() > index );
}

Circuit* CircuitIterator::currentItem() {

    return NULL;
}