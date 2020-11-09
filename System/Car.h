/**
   @file Car.h
   @class Car
   @authors Michael Timothy
   @version 1.0.1
   @brief A class that serves as an interface from which
   		  both the car and the parts it comprises of inherits.
 */

#ifndef CAR_H
#define CAR_H
#include <iostream>

using namespace std;

/**
	An enum used to facilitate tha access of specific car parts 
	in the CarComposite.
*/
enum PartIndices { ENGINE =0, CHASSIS=1, TRANSMISSION=2, 
		STEERINGWHEEL=3, COOLINGSYSTEM=4, BODY=5, SUSPENSION=6,
		BRAKES=7, ELECTRONICS=8

};

#include <iostream>

using namespace std;
class CarPart;

class Car {

	public:
	
		/**
			Constructor
		*/
		Car();

		/**
			Copy constructor used for the prototype design pattern
		*/
		Car( Car& );

		/**
			Destructor
		*/
		virtual ~Car();

		/**
			Makes and returns a clone of the current Car object
			@return
		*/
		virtual Car* clone() = 0;

		/**
			Prints out details about the Car object
		*/
		virtual void print() = 0;

		/**
			Adds the given car object to the given index
			@param index
			@param
		*/
		virtual void add( int, CarPart* ) = 0;
		 
		/**
			Removes the car object at the given index
			@param index
		*/
		virtual void remove( int ) = 0;

		/**
			Returns the stored handling
		 	@return
		*/
		virtual float getHandling() = 0;

		/**
			Sets the stored handling to the given value
			@param
		*/
		virtual void setHandling( float ) = 0;

		/**
			Returns the stored speed
		*/
		virtual float getSpeed() = 0;

		/**
			Sets the stored handling to the given value
			@param
		*/
		virtual void setSpeed( float ) = 0;

		/**
			Returns the acceleration handling
		*/
		virtual float getAcceleration() = 0;

		/**
			Sets the stored handling to the given value
			@param
		*/
		virtual void setAcceleration( float ) = 0;
};

#endif
