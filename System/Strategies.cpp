#include "Strategies.h"

Strategies::Strategies() {
	createSchedule();
	setLogistics();
}

Strategies::~Strategies() {
	races.clear();
}

//////////////////////////////////////////////////////////////
/////                    DO NOT TOUCH                    /////
/////  either get me and racetrack vector or dont touch  /////
//////////////////////////////////////////////////////////////

void Strategies::createSchedule()
{
	string line;
	ifstream file;

	file.open("Data/races.txt");
	if (file.is_open()) {
		while (getline(file, line)) {

			int pos = 0;
			int size = line.size();
			string name, direction, startingDate, endingDate, euro;
			float disLap, wind = 0, longestStraight, fastestLap, averagePitStop;
			int numCorners, numLaps;


			string temp = line;

			pos = temp.find_first_of('|');
			name = trim(temp.substr(0, pos - 1));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			fastestLap = stof(trim(temp.substr(0, pos - 1)));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			disLap = stof(trim(temp.substr(0, pos - 1)));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			numLaps = stoi(trim(temp.substr(0, pos - 1)));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			longestStraight = stof(trim(temp.substr(0, pos - 1)));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			numCorners = stoi(trim(temp.substr(0, pos - 1)));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			startingDate = trim(temp.substr(0, pos - 1));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			endingDate = temp.substr(0, pos - 1);
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			averagePitStop = stof(trim(temp.substr(0, pos - 1)));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			euro = trim(temp.substr(0, pos - 1));
			temp = temp.substr(pos + 1, size);

			pos = temp.find_first_of('|');
			direction = trim(temp.substr(0, pos - 1));
			temp = temp.substr(pos + 1, size);

			RaceTrack* tmp = nullptr;
			if (direction == "clockwise") {
				tmp = new RaceTrack(name, RaceTrack::direction::clockwise, disLap, wind, longestStraight, numCorners, numLaps);
			}
			else if (direction == "anticlockwise") {
				tmp = new RaceTrack(name, RaceTrack::direction::anticlockwise, disLap, wind, longestStraight, numCorners, numLaps);
			}
			else {
				Logger::yellow("Error", "Wrong direction given.");
			}

			tmp->setStartDate(startingDate);
			tmp->setEndDate(endingDate);
			bool maybe = true;
			euro = trim(euro);

			if (euro == "true") {
				maybe = true;
			}
			else if (euro == "false") {
				maybe = false;
			}
			else {
				Logger::yellow("Error", "The file not found.");
			}
			tmp->setAvgPitStops(averagePitStop);
			tmp->setEuro(maybe);
			races.push_back(tmp);
		}

	}
}

string Strategies::trim(string temp) {
	temp.erase(0, temp.erase(temp.find_last_not_of("\t\n\v\f\r ") + 1).find_first_not_of("\t\n\v\f\r "));
	return temp;
}

void Strategies::setRaceStrategy(Driver* driver1, Driver* driver2, string name) {
	Logger::debug("Strategies::setRaceStrategy", "raceStrategy 1");
	raceStrategy.push_back(new RaceStrategy(driver1, logisticsStrategy->getRace(name)));
	Logger::debug("Strategies::setRaceStrategy", "raceStrategy 2");
	raceStrategy.push_back(new RaceStrategy(driver2, logisticsStrategy->getRace(name)));

}

void Strategies::endOfRace(string name) {
	raceStrategy.clear();
	logisticsStrategy->endOfRace(name);
}

RaceStrategy* Strategies::getRaceStrategy(int index) {
	return raceStrategy.at(index);
}

void Strategies::setLogistics() {
	Logger::debug("Strategies::setLogistics", "");
	logisticsStrategy = new LogisticsStrategy(races);
}

void Strategies::print() {

	for (int i = 0; i < 21; i++) {

		RaceTrack* temp = races.at(i);
		cout << temp->getName() << " " << temp->getDistance() << " " << temp->getLaps() << endl;
	}
}

vector<RaceTrack*> Strategies::getRaceTrack() {
	return races;
}
















