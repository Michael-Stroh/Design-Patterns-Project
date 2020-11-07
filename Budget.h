/**
   @file Budget.h
   @class Budget
   @authors Kayla
   @version 2.0.0
   @brief observes any change in budget across the engineering departments and notifies said departments to update their budgets
 */

#ifndef BUDGET_H
#define BUDGET_H

#include <vector>

using namespace std;

class EngineeringDepartment;

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
	Budget(float);

	/**
		Destructor
	*/
	~Budget();

	/**
		Takes in an engineering department to attach to, to oberver
		@param observer
	*/
	void attach(EngineeringDepartment*);

	/**
		Takes in an engineering department to detach from
		@param e
	*/
	void detach(EngineeringDepartment*);

	/**
		Notifies all the attached obervers of a change
		@must be used immediantly after useBudget is called, this ensures the budget is balanced.
	*/
	void notifyAll();

	/**
		Returns the allocated budget
	*/
	float getBudget();

	/**
		Sets the allocated budget
		@param amount
	*/
	void setBudget(float);

private:

	/**
		@brief Used to indicate how much money a department can spend
	*/
	float balance;

	/**
		@brief A vector of all the observers watching the budget
	*/
	vector<EngineeringDepartment*> observerList;
};

#endif
