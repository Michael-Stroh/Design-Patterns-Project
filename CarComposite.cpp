#include "CarComposite.h"

//The default constructor. Sets all parts to nullptr. Adding of parts
//Will be handled By CarBuilder Class
CarComposite::CarComposite() {

	for(int i=0; i<NUMPARTS; ++i)
			carParts[i] = nullptr;
		
	aeroDynamicMultiplier = 0.65;
}

//The copy constructor, it clones every single part
//of the passed in car and adds them to itself.
CarComposite::CarComposite(Car& c) {

	for(int i=0; i<NUMPARTS; ++i)
		carParts[i] = c.get(i)->clone();

	aeroDynamicMultiplier = c.aeroDynamicMultiplier;
	
}

//Deallocates the memory of all parts
//that this object owns.
CarComposite::~CarComposite()
{
	for(int i=0; i<NUMPARTS; ++i)
		delete carParts[i];

	//for(int i=0; i<NUMTYRES; ++i)
	//	delete Tyres[i];

	//delete [] Tyres;	
}

//Uses the copy constructor to create a new CarComposite Object
Car * CarComposite::clone() {
	
	return new CarComposite(*this);
}

//is subject to change depending on whether
//or not we use a logger.
void CarComposite::print() {
	
	for(int i=0; i<carParts.size(); ++i)
		carParts[i]->print();

}

//should be used in conjunction with remove
void CarComposite::add(int index, Car * part) {
	if(index <0 || index >= NUMPARTS)
		throw "CarComposite::add; index out of bounds";
	else
	{
		if(carParts[i] != nullptr)	//an extra check to avoid memory leaks
			delete carParts[i];
		carParts[i] = part;
	}
}


void CarComposite::remove(int index) {
	if(index <0 || index >= NUMPARTS)
		throw "CarComposite::add; index out of bounds";
	else
	{
		delete carParts[i];
		carParts[i] = nullptr;
	}
}

Memento * CarComposite::createCarMemento() {
	// TODO - implement CarComposite::createCarMemento
	throw "Not yet implemented";
}

void CarComposite::setCarMemento(CarMemento * memento) {
	// TODO - implement CarComposite::setCarMemento
	throw "Not yet implemented";
}
