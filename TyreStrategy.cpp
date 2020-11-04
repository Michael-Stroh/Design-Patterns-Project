#include "TyreStrategy.h"

TyreStrategy::TyreStrategy(RaceTrack*  rt) {
	srand(time(NULL));
	cout << rt->getLaps() << endl;
	cout << rt->getDistance() << endl;
	int raceDistance =  rt->getLaps() * rt->getDistance();
	cout << raceDistance << endl;;
	numPits = rand() % 3 +3;
	
	int* tmpTyre = new int[numPits];
 	pitLaps = new int[numPits];
 	
	for( int i =0; i < numPits; i++){
		tmpTyre[i] = 60;
	}
		
	int distanceOfTyre = 60 * numPits;
	
	while(distanceOfTyre < raceDistance){
		int j = rand() % numPits;
		if(tmpTyre[j] != 120){
			tmpTyre[j] += 30;
			distanceOfTyre +=30;
		}
	}
		
	int pos =0;
	int totalLaps=0;
	for(int i =0; i < numPits; i++){
		switch (tmpTyre[i]){
			case 60:
				tyres.push_back(new Soft());
				break;
			case 90:
				tyres.push_back(new Medium());
				break;
			case 120:
				tyres.push_back(new Hard());
				break;
		}
		pitLaps[pos] = totalLaps + floor(tmpTyre[i] / rt->getDistance()); //length of lap << need to wait for others
		totalLaps += floor(tmpTyre[i] / rt->getDistance());
		pos++;
	}
}

TyreStrategy::~TyreStrategy() {
	tyres.clear();
	delete pitLaps;
}

vector<Tyre*> TyreStrategy::getTyres() {
	return tyres;
}

void TyreStrategy::setTyres( vector< Tyre* > newTyre ) {
	this->tyres = newTyre;
}


int * TyreStrategy::getPitLaps(){
	return pitLaps;
}


void TyreStrategy::setPitLaps(int* arr){
	this->pitLaps = arr;
}

int TyreStrategy::getNumPits(){
	return numPits;
}

void TyreStrategy::setNumPits(int a){
	this->numPits = a;
}

void TyreStrategy::print(){
	for( int i =0; i < numPits; i++){
		cout << i+1 << ". " << tyres.at(i)->getType() << endl;
	}

}
