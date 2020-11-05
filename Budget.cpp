#include "Budget.h"
#include "EngineeringDepartment.h"


Budget::Budget() {
	balance = 0;
}

Budget::Budget( float max ): balance( max ) {

}

Budget::~Budget() {
	observerList.clear();
}

void Budget::attach( EngineeringDepartment* observer ) {

	observerList.push_back(observer);
}

void Budget::detach( EngineeringDepartment* e ) {

	bool found = false;
	vector<EngineeringDepartment*>::iterator it = observerList.begin();
	while((it != observerList.end()) && !found)
	{
		if(*it == e)
		{
			found = true;
			observerList.erase(it);
		}
		++it;
	}
}

void Budget::notifyAll() {

	if(!observerList.empty())
	{
		std::vector<EngineeringDepartment *>::iterator it = observerList.begin();
		for(;it != observerList.end();it++)
			(*it)->update();	
	}
}

float Budget::getBudget() {

	return balance;
}

void Budget::setBudget( float amount ) {

	balance = amount;
}
