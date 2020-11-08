#include "OfficialRaceSubject.h"

OfficialRaceSubject::OfficialRaceSubject() : Subject() {

}

OfficialRaceSubject::~OfficialRaceSubject() {

}

void OfficialRaceSubject::notify( Result *r ) {

	for ( vector< RaceTeam* >::iterator it = observerList.begin(); it != observerList.end(); ++ it ) {

        ( *it )->updateOfficialRaceResult( r );
	}
}

void OfficialRaceSubject::notify(RaceState*) //added by Tim
{
	throw "Should not be used";
}