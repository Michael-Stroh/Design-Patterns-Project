#include "QualifyingRaceSubject.h"

QualifyingRaceSubject::QualifyingRaceSubject() : Subject() {

}

QualifyingRaceSubject::~QualifyingRaceSubject() {

}

void QualifyingRaceSubject::notify( RaceState* r ) {

	vector<RaceTeam *>::iterator it;
	for ( it = this->observerList.begin(); it != this->observerList.end(); ++it ) {

		// TODO: fix whatever is causing this
		//it->updateQualfyingRaceResult(r);
	}
}
