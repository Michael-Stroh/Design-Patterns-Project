/**
   @file Container.h
   @class Container
   @authors Michael
   @version 1.0.0
   @brief Template for Base Containers to implement based on the type of race the containers need to handle Logistics for.
 */

#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>

using namespace std;

class Container {

	public:
	
		/**
			Constructor
		*/
		Container();

		/**
			Destructor
		*/
		virtual ~Container();
};

#endif
