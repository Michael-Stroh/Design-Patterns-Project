#include "CircuitIterator.h"

CircuitIterator::CircuitIterator() : Iterator()
{
}

CircuitIterator::CircuitIterator(CompositeRoad *track) : Iterator(), array(track)
{
}

CircuitIterator::~CircuitIterator()
{
}

void CircuitIterator::first()
{

    index = 0;
}

void CircuitIterator::next()
{

    index++;
}

bool CircuitIterator::isDone()
{

    //check if the current index is still in range
    return (array->getSize() > index);
}

Circuit *CircuitIterator::currentItem()
{

    /*
        find and return the current object
        this will return the leaf participant( RaceTrack object )
    */

    return array->getRoad(index);
}