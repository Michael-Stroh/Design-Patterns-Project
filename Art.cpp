#include "Art.h"

Art::Art(): Car(), next( nullptr ) {

	// TODO - implement Art::Art
	throw "Not yet implemented";
}

Art::Art( string desc ): Car(), artDescription( desc ) {

	// TODO - implement Art::Art
	throw "Not yet implemented";
}

Art::~Art() {

	//need to decide if next should be deleted here
}

void Art::print() {

	// TODO - implement Art::print
	throw "Not yet implemented";
}

Art* Art::getNext() {

	return next;
}

void Art::setNext( Art* artWork ) {


	if ( next ) {

		next->setNext( artWork );
	} else {

		next = artWork;
	}
}

string Art::getDescription() {

	return artDescription;
}

void Art::setDescription( string desc ) {

	artDescription = desc;
}
