#include "CircuitIterator.h"

CircuitIterator::CircuitIterator(): Iterator() {


}

CircuitIterator::CircuitIterator( Circuit* track ): Iterator(), array( track ) {


}

CircuitIterator::~CircuitIterator() {

}

void CircuitIterator::first() {

    index = 0;
}

void CircuitIterator::next() {

    index++;
}

void CircuitIterator::isDone() {


}

void CircuitIterator::currentItem() {


}