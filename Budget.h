/**
   @file Budget.h
   @class Budget
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef BUDGET_H
#define BUDGET_H

#include "EngineeringDepartment.h"

class Budget {

	public:
	
		/**
			Constructor
		*/
		Budget();

		/**
			Constructor that takes a parameter for the budget
			@param max
		*/
		Budget( float );

		/**
			Destructor
		*/
		~Budget();

		/**
			Takes in an engineering department to attach to, to oberver
			@param
		*/
		void attach( EngineeringDepartment* );

		/**
			Takes in an engineering department to detach from
			@param
		*/
		void detach( EngineeringDepartment* );

		/**
			Notifys all the attached obervers of a change
		*/
		void notifyAll();
	
	private:
	
		/**
     		@brief Used to indicate how much money a department can spend
		*/
		float balance;
	
		/**
     		@brief A list of all the observers watching the budget
		*/
		EngineeringDepartment* observerList;
};

#endif
