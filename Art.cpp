#include "Art.h"

Art::Art(): CarPart(), next( nullptr ) {
	//uses the CarPart default constructor but since it does not print/return any of those
	//variables it should be fine
}

Art::Art( string desc ): CarPart(), artDescription( desc ) {

	next = nullptr;
}

Art::~Art() {

	delete next;	//will cause a chain reaction of deletions that results in all memory being deallocated correctly
}

void Art::print()
{

	// TODO - implement Art::print
	throw "Not yet implemented";
}

CarPart * Art::getNext() {

	return next;
}

//remember that Art is a CarPart. This needs to be double checked
void Art::setNext( CarPart * newNext ) 
{
	if (next == nullptr)
	{
		next = newNext;
	}
	else
	{
		Art* prev = nullptr;
		Art* iter = this;
		//REason why this loop works: Only CarParts that use the default constructor will have a brand of Volvo
		//Thus when we come across a carPart that is volvo we know it is an Art*
		while (iter->getBrand() != "NoBrand" &&  iter->next != nullptr)
		{
			prev = iter;
			iter = (Art*)(iter->next);
		}


	}
}

string Art::getDescription() {

	return artDescription;
}

void Art::setDescription( string desc ) {

	artDescription = desc;
}
