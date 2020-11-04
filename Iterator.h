/**
   @file Iterator.h
   @class Iterator
   @authors Michael
   @version 1.2.0
   @brief Iterator participant in the Iterator design pattern
   @details this is an abstract class, it is mostly used as a template
 */

#ifndef ITERATOR_H
#define ITERATOR_H

#include "Circuit.h"

class Iterator {

    public:

        /**
            @brief Constructor
            Creates the Object
        */
        Iterator();

        /**
            @brief Destructor
            Frees the memory
        */
        virtual ~Iterator();

        /**
            Sets the index to the first element, pure virtual
        */
        virtual void first() = 0;

        /**
            Sets the index to the next element, pure virtual
        */
        virtual void next() = 0;

        /**
            Determines if index is on the last element, pure virtual
        */
        virtual bool isDone() = 0;

        /**
            Returns the current element, pure virtual
        */
        virtual Circuit* currentItem() = 0;
};

#endif
