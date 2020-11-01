#include "CompositeRoad.h"

CompositeRoad::CompositeRoad(): Road(), tracks() {

}

CompositeRoad::CompositeRoad( string RoadName ): Road( RoadName ), tracks() {

}

CompositeRoad::~CompositeRoad() {

    //go through each RaceTrack object stored
        //for ( auto& track : tracks ) {
    for ( Road*& track : tracks ) {

        //free the memory
        delete track;
    }

    //empty and resize the vector
    tracks.clear();
}

void CompositeRoad::addRoad( Road* CreateRoad ) {

    //add the given RaceTrack to the vector
	tracks.push_back( CreateRoad );
}

void CompositeRoad::removeRoad( Road* RemoveRoad ) {

    /*
        The Road object must be deleted by the user
     */

    //counter
    int x = 0;

    //go through each RaceTrack object stored
        //for ( auto& track : tracks ) {
    for ( Road*& track : tracks ) {

        //check if current RaceTrack is what we are looking for
        if ( track->getName() == RemoveRoad->getName() ) {

            //output the RaceTrack has been found
            Logger::cyan( "Success", "Road " + track->getName() + " was removed." );

            //remove the RaceTrack and resize the vector
            tracks.erase( tracks.begin() + x );
            tracks.size();

            return;
        }

        //increment the counter
        x++;
    }

    //output the given RaceTrack object was not found
    Logger::cyan( "Error", "Road " + RemoveRoad->getName() + " was not found." );
}

void CompositeRoad::removeRoad( const string& RemoveRoad ) {

    //counter
    int x = 0;

    //go through each RaceTrack object stored
     //for ( auto& track : tracks ) {
    for ( Road*& track : tracks ) {

        //check if current RaceTrack is what we are looking for
        if ( track->getName() == RemoveRoad ) {

            //output the RaceTrack has been found and delete the object
            Logger::cyan( "Success", "Road " + track->getName() + " was removed." );
            delete track;

            //remove the RaceTrack and resize the vector
            tracks.erase( tracks.begin() + x );
            tracks.size();
            return;
        }

        //increment the counter
        x++;
    }

    //output the given RaceTrack name was not found
    Logger::cyan( "Error", "Road " + RemoveRoad + " was not found." );
}

void CompositeRoad::print() {

    //go through each RaceTrack object stored
        //for ( auto& track : tracks ) {
    for ( Road*& track : tracks ) {

        //call the print function to display the details
        track->print();
    }
}

Iterator* CompositeRoad::createIterator() {

    //create and return an iterator on the current object
    return ( new RoadIterator( this ) );
}
