#include "CompositeRoad.h"

CompositeRoad::CompositeRoad() : Circuit(), tracks() {

}

CompositeRoad::CompositeRoad( string RoadName ) : Circuit( RoadName ), tracks(){

}

CompositeRoad::~CompositeRoad() {

    //go through each RaceTrack object stored
    for ( Circuit* track : tracks ) {

        //free the memory
        delete track;
    }

    //empty and resize the vector
    tracks.clear();
}

void CompositeRoad::addRoad( RaceTrack* CreateRoad ) {

    //add the given RaceTrack to the vector
    tracks.push_back( CreateRoad );
}

void CompositeRoad::removeRoad( RaceTrack* RemoveRoad ) {

    /*
        The Road object must be deleted by the user
     */

    //counter
    int x = 0;

    //go through each RaceTrack object stored
    for ( Circuit* track : tracks ) {

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

void CompositeRoad::removeRoad( const string &RemoveRoad ) {

    //counter
    int x = 0;

    //go through each RaceTrack object stored
    for ( RaceTrack*& track : tracks ) {

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
    for ( RaceTrack*& track : tracks ) {

        //call the print function to display the details
        track->print();
    }
}

CircuitIterator* CompositeRoad::createIterator() {

    //create and return an iterator on the current object
    return ( new CircuitIterator( this ) );
}

int CompositeRoad::getSize() {

    //return the size
    return tracks.size();
}

RaceTrack *CompositeRoad::getRoad( int index ) {

    //check if the vector is populated and the index is valid
    if ( ( !tracks.empty() ) && ( index >= 0 ) && ( index < tracks.size() ) ) {

        //check if the index exists in the vector
        if ( tracks[ index ] != nullptr ) {

            //return the found object
            return tracks[ index ];
        }
    }

    //there was an error do no return anything
    return nullptr;
}


void CompositeRoad::determineMaxValues() {

    /*
        numCorners
        windForce
        straightDistance
    */

    int maxCorners = -999;
    for ( RaceTrack*& track : tracks ) {

        int hold = track->getCorners();
        if ( hold > maxCorners ) {

            maxCorners = hold;
        }

    }


    float maxWind = -999;
    for ( RaceTrack*& track : tracks ) {

        float hold = track->getWindForce();
        if ( hold > maxWind ) {

            maxWind = hold;
        }
    }

    float maxStrDist = -999;
    for ( RaceTrack*& track : tracks ) {

        float hold = track->getStraightDistance();
        if ( hold > maxWind ) {

            maxStrDist = hold;
        }

    }

    Logger::cyan( "Max Distances", "Corners: " + to_string( maxCorners ) + "  Wind:  " + to_string( maxWind ) + "  Straight Distance: " + to_string( maxStrDist ) );
}

void CompositeRoad::determineMinValues() {

    /*
        numCorners
        windForce
        straightDistance
    */

    int maxCorners = 10000;
    for ( RaceTrack*& track : tracks ) {

        int hold = track->getCorners();
        if ( hold < maxCorners ) {

            maxCorners = hold;
        }

    }

    float maxWind = 10000;
    for ( RaceTrack*& track : tracks ) {

        float hold = track->getWindForce();
        if ( hold < maxWind ) {

            maxWind = hold;
        }
    }

    float maxStrDist = 10000;
    for ( RaceTrack*& track : tracks ) {

        float hold = track->getStraightDistance();
        if ( hold < maxWind ) {

            maxStrDist = hold;
        }

    }

    Logger::cyan( "Min Distances", "Corners: " + to_string( maxCorners ) + "  Wind:  " + to_string( maxWind ) + "  Straight Distance: " + to_string( maxStrDist ) );
}