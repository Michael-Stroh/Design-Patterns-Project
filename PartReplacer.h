/**
   @file PartReplacer.h
   @class PartReplacer
   @authors Michael
   @version 1.0.0
   @brief --PartReplacer--
 */


#ifndef PARTREPLACER_H
#define PARTREPLACER_H

#include "PitCrew.h"

class PartReplacer: public PitCrew {

	public:
		
		/**
			Constructor
		*/
		PartReplacer();

		/**
			Constructor
		*/
		~PartReplacer();

		/**
			
		*/
		void update();
};

#endif
