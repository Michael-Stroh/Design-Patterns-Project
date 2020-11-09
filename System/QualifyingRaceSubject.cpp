#include "QualifyingRaceSubject.h"

QualifyingRaceSubject::QualifyingRaceSubject() : Subject() {

}

QualifyingRaceSubject::~QualifyingRaceSubject() {

}

void QualifyingRaceSubject::notify(RaceState* p)
{
	throw "QualifyingRaceSubejct notify Dont use this";
}

void QualifyingRaceSubject::notify( Result* r )
{
	Logger::debug("QualifyingRaceSubject::notify start", "");						//added by tim for debugging
	vector<RaceTeam *>::iterator it;
	
	for ( it = this->observerList.begin(); it != this->observerList.end(); ++it ) {
		( *it )->updateQualifyingRaceResult( r );
	}
	Logger::debug("QualifyingRaceSubject::notify end", "");						//added by tim for debugging
}
