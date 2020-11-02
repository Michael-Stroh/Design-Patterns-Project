/**
   @file PartState.h
   @class PartState
   @authors Timothy
   @version 1.0.1
   @brief Stores the state of the car part, to be used in conjunction with the @link CarMemento class.
 */

#ifndef PARTSTATE_H
#define PARTSTATE_H

class PartState
{
	public:
		/**
			@brief
			@param
			@param
			@param
			@param
		*/
		PartState(float, float, float, float coolingRate = -1);

		~PartState();

		float getAcceleration();

		float getSpeed();

		float getHandling();

		float getCoolingRate();


	private:
		/**
			@brief
		*/
		float acceleration;
		/**
			@brief
		*/
		float handling;
		/**
			@brief
		*/
		float speed;
		/**
			@brief
		*/
		float coolingRate;

};


#endif
