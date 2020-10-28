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

            Logger::cyan( "Success", "Road " + track->getName() + " was removed." );
            delete track;

            return;
        }
    }

    Logger::cyan( "Error", "Road " + RemoveRoad->getName() + " was not found." );
}

void CompositeRoad::removeRoad( const string& RemoveRoad ) {

    for ( auto& track : tracks ) {

        if ( track->getName() == RemoveRoad ) {

            Logger::cyan( "Success", "Road " + track->getName() + " was removed." );
            delete track;

            return;
        }
    }

    Logger::cyan( "Error", "Road " + RemoveRoad + " was not found." );
}

void CompositeRoad::print() {

    // for each child
    for ( vector< Road* >::iterator it = tracks.begin(); it != tracks.end(); it++ ) {

        //call the print function to display the details
        ( *it )->print();
    }
}
