/**
   @file GarageEquipment.h
   @class GarageEquipment
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef GARAGEEQUIPMENT_H
#define GARAGEEQUIPMENT_H

#include <iostream>
#include <string>

#include "Container.h"

using namespace std;

class GarageEquipment: public Container {

	public:

		/**
			Constructor
		*/
		GarageEquipment();

		/**
			Constructor
			@param
		*/
		GarageEquipment( string );

		/**
			Destructor
		*/
		~GarageEquipment();

		/**
			
			@return
		*/
		string getTools();
};

#endif
