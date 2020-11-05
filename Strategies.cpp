#include "Strategies.h"

Strategies::Strategies(){
	createRaces();
	setLogisitics();
}

Strategies::~Strategies() {
	races.clear();
}

void Strategies::setRaceStrategy(Driver* driver, string name){
	raceStrategy = new RaceStrategy(driver, logisticsStrategy->getRace(name));
}

void Strategies::endOfRace(string name){
	//delete raceStrategy;
	logisticsStrategy->endOfRace(name);
}

RaceStrategy* Strategies::getRaceStrategy(){
	return raceStrategy;
}

void Strategies::setLogisitics(){
	logisticsStrategy =  new LogisticsStrategy(races);
}

void Strategies::print(){
	for( int i =0; i < 21; i++){
		RaceTrack* temp = races.at(i);
		cout << temp->getName() << " " << temp->getDistance() << " " << temp->getLaps() << endl;
	}
}

void Strategies::createRaces(){	
	string line;
    ifstream file;

	file.open("../Data/races.txt");
	if (file.is_open()) {
        while (getline(file, line)) {
			int pos =0;
			int size = line.size();
			string name, direction, startingDate, endingDate, euro;
			float disLap, wind, longestStraight, fastestLap,averagePitStop;
			int numCorners, numLaps;
			
			
			string temp = line;
			
			pos = temp.find_first_of('|' );
			name = trim(temp.substr(0,pos-1));
			temp = temp.substr(pos+1, size);
			
			pos = temp.find_first_of('|' );
			fastestLap = stof(trim(temp.substr(0,pos-1)));
			temp = temp.substr(pos+1, size);
			
			pos = temp.find_first_of('|' );
			disLap = stof(trim(temp.substr(0,pos-1)));
			temp = temp.substr(pos+1, size);
			
			pos = temp.find_first_of('|' );
			numLaps = stoi(trim(temp.substr(0,pos-1)));
			temp = temp.substr(pos+1, size);
			
			pos = temp.find_first_of('|' );
			longestStraight = stof(trim(temp.substr(0,pos-1)));
			temp = temp.substr(pos+1, size);
			
			pos = temp.find_first_of('|' );
			numCorners = stoi(trim(temp.substr(0,pos-1)));
			temp = temp.substr(pos+1, size);
			
			pos = temp.find_first_of('|' );
			startingDate = trim(temp.substr(0,pos-1));
			temp = temp.substr(pos+1, size);
			
			pos = temp.find_first_of('|' );
			endingDate = temp.substr(0,pos-1);
			temp = temp.substr(pos+1, size);
			
			pos = temp.find_first_of('|' );
			averagePitStop = stof(trim(temp.substr(0,pos-1)));
			temp = temp.substr(pos+1, size);
		
			pos = temp.find_first_of('|' );
			euro = trim(temp.substr(0,pos-1));
			temp = temp.substr(pos+1, size);
			
			pos = temp.find_first_of('|' );
			direction = trim(temp.substr(0,pos-1));
			temp = temp.substr(pos+1, size);
			
			RaceTrack* tmp;
			if(direction == "clockwise"){
				tmp = new RaceTrack(name, RaceTrack::direction::clockwise, disLap, wind, longestStraight, numCorners,numLaps);
			}else if (direction == "anticlockwise"){
				tmp = new RaceTrack(name, RaceTrack::direction::anticlockwise, disLap, wind,longestStraight, numCorners,numLaps);
			}else{
				cout << "Error: " << direction << endl;
			}
			tmp->setStartDate(startingDate);
			tmp->setEndDate(endingDate);
			bool maybe;
			euro = trim(euro);
			if(euro =="true"){
				maybe = true;
			}else if(euro == "false"){
				maybe = false;
			}else{
				cout << "Error: "<< euro << endl;
			}
			tmp->setAvgPitStops(averagePitStop);
			tmp->setEuro(maybe);
			races.push_back(tmp);
		}
    }
    else {
        cout << "file not found" << endl;
    }
}

string Strategies::trim(string temp){
	string nono = "\t\n\v\f\r ";
	temp.erase(0, temp.erase(temp.find_last_not_of(nono)+1).find_first_not_of(nono));
	return temp; 
}

vector<RaceTrack*> Strategies::getRaceTrack(){
	return races;
}















