o_files = main.o Logger.o Result.o LapResult.o RaceResult.o GrandPrixResult.o RaceSeasonResult.o

main: $(o_files)
	@g++ $(o_files) -o main

run: main
	@./main

clean:
	@rm -rf *.o main
	@echo "Cleaned"

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





