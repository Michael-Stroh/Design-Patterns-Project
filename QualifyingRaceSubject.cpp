#include "QualifyingRaceSubject.h"

QualifyingRaceSubject::QualifyingRaceSubject() : Subject() {

}

QualifyingRaceSubject::~QualifyingRaceSubject() {

}

void QualifyingRaceSubject::notify( Result* r )
{
	Logger::debug("QualifyingRaceSubject::notify start", "");						//added by tim for debugging
	vector<RaceTeam *>::iterator it;
	cout << &observerList << endl;
	for ( it = this->observerList.begin(); it != this->observerList.end(); ++it ) {
		( *it )->updateQualifyingRaceResult( r );
	}
	Logger::debug("QualifyingRaceSubject::notify end", "");						//added by tim for debugging
}
