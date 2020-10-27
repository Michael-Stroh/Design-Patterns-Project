#include "CompositeRoad.h"

CompositeRoad::CompositeRoad(): Road() {

}

CompositeRoad::CompositeRoad( string RoadName ): Road( RoadName ) {

}

CompositeRoad::~CompositeRoad() {

    for ( auto it = tracks.begin(); it != tracks.end(); ++it ) {

        delete *it;
    }

    tracks.clear();
}

void CompositeRoad::addRoad( Road* CreateRoad ) {

	// TODO - implement CompositeRoad::addRoad
	throw "Not yet implemented";
}

void CompositeRoad::removeRoad( Road* RemoveRoad ) {

	// TODO - implement CompositeRoad::removeRoad
	throw "Not yet implemented";
}

void CompositeRoad::print() {

	// TODO - implement CompositeRoad::print
	throw "Not yet implemented";
}
