#include "CarMemento.h"

CarMemento::CarMemento() {

	
}

CarMemento::~CarMemento() {

	for (int i = 0; i < state.size(); ++i)
	{
		delete state[i];
	}
}

vector<PartState*> CarMemento::getState()
{
	return state;
}

//makes shallow copies of the pointers given in by the carState vector. Must remember not to delete them accidentally in the
//car Composite class
void CarMemento::setState(vector<PartState *> carState) 
{
	for (int i = 0; i < carState.size(); ++i)
	{
		state.push_back(carState[i]);
	}

}