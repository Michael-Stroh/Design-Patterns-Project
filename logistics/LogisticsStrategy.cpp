#include "LogisticsStrategy.h"

LogisticsStrategy::LogisticsStrategy() {
	logisitics = new vector<Logisitics*>;
}

LogisticsStrategy::~LogisticsStrategy() {
	logisitics.clear();
}

void LogisiticsStrategy::endOfRace(){
	
}

void LogisiticsStrategy::newMonthNewLog(){
	int month = getMonth();
	int threeMonth = month+3;
	int oneMonth = month +1;
	int i =0;
	while( i < 21){
		if(stoi(race.getStartMonth) == oneMonth){
			if(european == true){
				logisitics.push_back(new Logistics(/*grandPrix/circuit name*/"a", true));
			}
		}else if(stoi(race.getStartMonth) == threeMonth)){
			if(european == false){
				logisitics.push_back(new Logistics(/*grandPrix/circuit name*/"b", false));
			}
		}
	}

}
