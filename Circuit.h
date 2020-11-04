/**
   @file Circuit.h
   @class Circuit
   @authors Michael
   @version 1.5.0
   @brief Component and Aggregate participant in the Composite and Iterator design pattern
   @details Template that acts as an interface for the clients
 */

#ifndef Circuit_H
#define Circuit_H

#include <utilities/Logger.h>
#include <sstream>
#include <iostream>

using namespace std;

class Iterator;


class Circuit {

    public:

        /**
            @brief Constructor
            Creates the object
        */
        Circuit();

        /**
            @brief Constructor
            Creates the object with the given name
            @param[in] CircuitName used to identify the object
        */
        Circuit( string );

        /**
            @brief Destructor
            Frees the memory
        */
        virtual ~Circuit();

        /**
            Displays details of object, pure virtual
        */
        virtual void print() = 0;

        /**
            Creates an iterator to be able to traverse the object, pure virtual
            @return the created iterator on the current object
        */
        virtual Iterator *createIterator() = 0;

        /**
            Returns the stored name
            @return the stored name
        */
        string getName();

        /**
            Changes the object's name to the given parameter
            @param[in] ChangeName: name to change to
        */
        void setName( string );

    private:

        /**
            @brief the name of the specific Circuit
        */
        string name;
};

#include "Iterator.h"

#endif
