#include "Art.h"

Art::Art():  next( nullptr ) {
	//uses the CarPart default constructor but since it does not print/return any of those
	//variables it should be fine
}

Art::Art( string desc ):  artDescription( desc ) {

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
}

string Art::getDescription() {

	return artDescription;
}

void Art::setDescription( string desc ) {

	artDescription = desc;
}
