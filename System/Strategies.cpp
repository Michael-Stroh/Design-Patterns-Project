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

			float wind, dist, straightDist, bestLap, pitStop;
			int size = line.size(), pos, numCorners, numLaps;
			string name, direction, startDate, endDate, euro;

			//find the value for the name
			pos = line.find_first_of('|');
			name = trim(line.substr(0, pos - 1));
			line = line.substr(pos + 1, size);

			//find the value for best lap time
			pos = line.find_first_of('|');
			bestLap = stof(trim(line.substr(0, pos - 1)));
			line = line.substr(pos + 1, size);

			//find the value for distance of a lap
			pos = line.find_first_of('|');
			dist = stof(trim(line.substr(0, pos - 1)));
			line = line.substr(pos + 1, size);

			//find the value for number of laps the track will be raced
			pos = line.find_first_of('|');
			numLaps = stoi(trim(line.substr(0, pos - 1)));
			line = line.substr(pos + 1, size);

			//find the value for straight distance of the track
			pos = line.find_first_of('|');
			straightDist = stof(trim(line.substr(0, pos - 1)));
			line = line.substr(pos + 1, size);

			//find the value for the number of corners on the track
			pos = line.find_first_of('|');
			numCorners = stoi(trim(line.substr(0, pos - 1)));
			line = line.substr(pos + 1, size);

			//find the value for starting date the track will be used for
			pos = line.find_first_of('|');
			startDate = trim(line.substr(0, pos - 1));
			line = line.substr(pos + 1, size);

			//find the value for ending date the track will not be used for
			pos = line.find_first_of('|');
			endDate = line.substr(0, pos - 1);
			line = line.substr(pos + 1, size);

			//find the value for the average amount of pit stops made on the track
			pos = line.find_first_of('|');
			pitStop = stof(trim(line.substr(0, pos - 1)));
			line = line.substr(pos + 1, size);

			//find the value for if the track is in Europe or not
			pos = line.find_first_of('|');
			euro = trim(line.substr(0, pos - 1));
			line = line.substr(pos + 1, size);

			//find the value for the direction the track will be raced in
			pos = line.find_first_of('|');
			direction = trim(line.substr(0, pos - 1));
			line = line.substr(pos + 1, size);

			//find the value for wind on the track
			pos = line.find_first_of('|');
			wind = stof(trim(line.substr(0, pos - 1)));
			line = line.substr(pos + 1, size);


			//determine the enum direction from the string value
			RaceTrack::direction dir = RaceTrack::direction::clockwise;
			if (direction == "clockwise") {

				//the track will be raced clockwise
				dir = RaceTrack::direction::clockwise;
			}
			else if (direction == "anticlockwise") {

				//the track will be raced anti-clockwise
				dir = RaceTrack::direction::anticlockwise;
			}
			else {

				//the value given is invalid so take the default of true and output the error
				Logger::yellow("Error", "Incorrect direction value given in.");
			}

			//determine the bool value for European from the string value
			euro = trim(euro);
			bool isEuro = true;
			if (euro == "true") {

				//the race is in Europe
				isEuro = true;
			}
			else if (euro == "false") {

				//the race is not in Europe
				isEuro = false;
			}
			else {

				//the value given is invalid so take the default of true and output the error
			}


			//create the RaceTrack from the given data and add it to the Circuit
			races.push_back(new RaceTrack(name, dir, dist, wind, straightDist, pitStop, bestLap, numCorners, numLaps, isEuro, startDate, endDate));

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
	logisticsStrategy->endOfRace(name);
	raceStrategy.clear();
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
	}
}

vector<RaceTrack*> Strategies::getRaceTrack() {
	return races;
}
















