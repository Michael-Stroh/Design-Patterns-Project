o_files = main.o Logger.o Result.o LapResult.o RaceResult.o GrandPrixResult.o RaceSeasonResult.o GrandPrix.o Subject.o Race.o RaceSeason.o RaceSubject.o SeasonSubject.o PracticeState.o QualifyingState.o OfficialState.o RaceState.o RaceTeam.o Driver.o Circuit.o 

main: $(o_files)
	@g++ $(o_files) -o main

run: main
	@./main

clean:
	@rm -rf *.o main
	@echo "Cleaned"


Circuit.o: ../Circuit.cpp ../Circuit.h
	@g++ -c ../Circuit.cpp .

Driver.o: ../Driver.cpp ../Driver.h
	@g++ -c ../Driver.cpp .

Subject.o: ../Subject.cpp ../Subject.h
	@g++ -c ../Subject.cpp .

SeasonSubject.o: ../SeasonSubject.cpp ../SeasonSubject.h
	@g++ -c ../SeasonSubject.cpp .

RaceTeam.o: ../RaceTeam.cpp ../RaceTeam.h
	@g++ -c ../RaceTeam.cpp .

RaceState.o: ../RaceState.cpp ../RaceState.h
	@g++ -c ../RaceState.cpp .

Race.o: ../Race.cpp ../Race.h
	@g++ -c ../Race.cpp .

OfficialState.o: ../OfficialState.cpp ../OfficialState.h
	@g++ -c ../OfficialState.cpp .

QualifyingState.o: ../QualifyingState.cpp ../QualifyingState.h
	@g++ -c ../QualifyingState.cpp .

PracticeState.o: ../PracticeState.cpp ../PracticeState.h
	@g++ -c ../PracticeState.cpp .

RaceSubject.o: ../RaceSubject.cpp ../RaceSubject.h
	@g++ -c ../RaceSubject.cpp .

RaceSeason.o: ../RaceSeason.cpp ../RaceSeason.h
	@g++ -c ../RaceSeason.cpp .

GrandPrix.o: ../GrandPrix.cpp ../GrandPrix.h
	@g++ -c ../GrandPrix.cpp .

Result.o: ../Result.cpp ../Result.h
	@g++ -c ../Result.cpp .

RaceResult.o: ../RaceResult.cpp ../RaceResult.h
	@g++ -c ../RaceResult.cpp .

GrandPrixResult.o: ../GrandPrixResult.cpp ../GrandPrixResult.h
	@g++ -c ../GrandPrixResult.cpp .

RaceSeasonResult.o: ../RaceSeasonResult.cpp ../RaceSeasonResult.h
	@g++ -c ../RaceSeasonResult.cpp .

LapResult.o: ../LapResult.cpp ../LapResult.h
	@g++ -c ../LapResult.cpp .

Logger.o: ../utilities/Logger.h ../utilities/Logger.cpp
	@g++ -c ../utilities/Logger.cpp .





