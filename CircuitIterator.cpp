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

    array->print();
    return false;
}

void CircuitIterator::currentItem() {


}