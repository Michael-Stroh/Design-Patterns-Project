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
