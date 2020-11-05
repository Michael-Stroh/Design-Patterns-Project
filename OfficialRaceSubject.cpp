#include "OfficialRaceSubject.h"

OfficialRaceSubject::OfficialRaceSubject() : Subject()
{
}

OfficialRaceSubject::~OfficialRaceSubject()
{
}

void OfficialRaceSubject::notify( Result *r ) {


	for ( vector< RaceTeam* >::iterator it = observerList.begin(); it != observerList.end(); ++ it ) {

		// TODO: fix whatever is wrong with this
		//it->updateOfficialRaceResult( r );
	}
}
