#include "LogisticsStrategy.h"

LogisticsStrategy::LogisticsStrategy(RaceTrack* rt) {
	this->rt = rt;
}

LogisticsStrategy::~LogisticsStrategy() {
	logisitics.clear();
}

void LogisticsStrategy::endOfRace(){
	
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
		}
	}

}

int LogisticsStrategy::getMonth(string date){
	int pos = date.find_first_of('-');
	return stoi(date.substr(0,pos));
}
