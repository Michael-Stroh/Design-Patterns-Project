#include "LogisticsStrategy.h"

LogisticsStrategy::LogisticsStrategy(RaceTrack* rt) {
	this->rt = rt;
LogisticsStrategy::LogisticsStrategy(vector<RaceTrack*> races) {
	this->races = races;
	setDates(races);
	tracker =0;
	while(dates.at(20-tracker) == "StartOfSeason"){		
		logisitics.push_back( new Logistics(races.at(tracker)->getName(), races.at(tracker)->getEuro()));
		tracker = tracker +1;
	}
}

void LogisticsStrategy::setDates(vector<RaceTrack*> races){
	dates.reserve(21);
	names.reserve(21);
	for( int i = 20; i >= 0 ;i--){
		RaceTrack* temp = races.at(i);
		names.push_back(temp->getName());
		if(temp->getEuro()){
			if(races.at(i-1) != NULL){
				dates.push_back(races.at(i-1)->getName());
			}else{
				dates.push_back("StartOfSeason");
			}
		}else{
			int month = getMonth(temp->getStartDate());
			RaceTrack* tmp;
			bool found = false;
			for( int j =i; j > 0; j--){
				if(getMonth(races.at(j)->getEndDate()) - month == -3 ){
					tmp = races.at(j);
					found = true;
				}
			}
			if(found == false){
				dates.push_back("StartOfSeason");
			}else{
				dates.push_back(tmp->getName());
			}
		}
	}
}


LogisticsStrategy::~LogisticsStrategy() {
	logisitics.clear();
	dates.clear();
	races.clear();
	names.clear();
}

void LogisticsStrategy::endOfRace(){
	
void LogisticsStrategy::endOfRace(string name){
	for(int i = tracker; i < 20; i++){
		if(name == dates.at(20 - i)){
			RaceTrack* temp = getRace(names.at(20-i));
			logisitics.push_back( new Logistics(temp->getName(), temp->getEuro()));
		}
	}
	tracker++;
}

void LogisticsStrategy::newMonthNewLog(int month){
	int threeMonth = month+3;
	int oneMonth = month +1;
	int i =0;
	while( i < 21){
		if(getMonth(rt->getStartDate()) == oneMonth){
			if(rt->getEuro() == true){
				logisitics.push_back(new Logistics(rt->getName(), true));
			}
		}else if(getMonth(rt->getStartDate()) == threeMonth){
			if(rt->getEuro() == false){
				logisitics.push_back(new Logistics(rt->getName(), false));
			}
int LogisticsStrategy::getMonth(string date){
		int pos = date.find_first_of('-');
		return stoi(date.substr(0, pos));
}

RaceTrack* LogisticsStrategy::getRace(string name){
	for( int i =0; i < (int)races.capacity(); i++){
		if(races.at(i)->getName() == name){
			return races.at(i);
		}
	}

}

int LogisticsStrategy::getMonth(string date){
	int pos = date.find_first_of('-');
	return stoi(date.substr(0,pos));
Logistics* LogisticsStrategy::getLogistics(string name){
	for( int i =1; i < (int)logisitics.capacity(); i++){
		if(name == logisitics.at(i)->getName()){
			return logisitics.at(i);
		}
	}
}




