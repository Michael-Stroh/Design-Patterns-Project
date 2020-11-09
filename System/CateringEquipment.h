/**
   @file CateringEquipment.h
   @class CateringEquipment
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CATERINGEQUIPMENT_H
#define CATERINGEQUIPMENT_H

#include "Container.h"

#include <iostream>
using namespace std;

class CateringEquipment: public Container {


	public:
		/**
			Constructor
		*/
		CateringEquipment();

		/**
			Destructor
		*/
		~CateringEquipment();
};

#endif
