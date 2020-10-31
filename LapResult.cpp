#include "LapResult.h"

LapResult::LapResult(): Result() {

	// TODO - implement LapResult::LapResult
	throw "Not yet implemented";
}

LapResult::LapResult( float Time ): lapTime( Time ) {

	// TODO - implement LapResult::LapResult
	throw "Not yet implemented";
}

LapResult::LapResult( string name ): teamName( name ) {

}

LapResult::LapResult( string name, float Time ): teamName( name ), lapTime( Time ) {

}

LapResult::~LapResult() {

}

bool LapResult::addLapTime( Result* r ) {

	// TODO - implement LapResult::addLapTime
	throw "Not yet implemented";
}

void LapResult::print() {

	// TODO - implement LapResult::print
	throw "Not yet implemented";
}

string LapResult::getTeamName() {

	return teamName;
}

void LapResult::setTeamName( string name ) {

	teamName = name;
}
