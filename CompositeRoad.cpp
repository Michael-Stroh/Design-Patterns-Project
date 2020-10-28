#include "CompositeRoad.h"

CompositeRoad::CompositeRoad(): Road(), tracks() {

}

CompositeRoad::CompositeRoad( string RoadName ): Road( RoadName ), tracks() {

}

CompositeRoad::~CompositeRoad() {

    //for ( vector<Road*>::iterator it = tracks.begin(); it != tracks.end(); ++it ) {
    for ( auto& track : tracks ) {

        delete track;
    }

    tracks.clear();
}

void CompositeRoad::addRoad( Road* CreateRoad ) {

	tracks.push_back( CreateRoad );
}

void CompositeRoad::removeRoad( Road* RemoveRoad ) {

    for ( auto& track : tracks ) {

        if ( track->getName() == RemoveRoad->getName() ) {

            delete track;

            //need to print something

            return;
        }
    }

    //print it was not found
}

void CompositeRoad::print() {

	// TODO - implement CompositeRoad::print
	throw "Not yet implemented";
}
