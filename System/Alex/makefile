_o_files = main.o Logger.o Result.o LapResult.o RaceSeason.o RaceSeasonResult.o SeasonSubject.o GrandPrix.o RaceTeam.o GrandPrixResult.o Subject.o Race.o EngineeringCrew.o RaceResult.o RaceSubject.o PracticeState.o QualifyingState.o OfficialState.o RaceState.o Driver.o RaceTrack.o Circuit.o
o_files = $(patsubst %,$(OBJDIR)/%,$(_o_files))
OBJDIR = obj

main: $(o_files)
	@g++ -o main $(o_files)

run: main
	@echo "" 
	@echo "Running:" 
	@./main

clean:
	@rm -rf $(OBJDIR)/*.o main
	@echo "Cleaned"

$(OBJDIR)/%.o: %.cpp
	@echo "Compiling $<"
	@g++ -c $< -o $@

$(OBJDIR)/%.o: ../%.cpp ../%.h
	@echo "Compiling $<"
	@g++ -c $< -o $@

$(OBJDIR)/Logger.o: ../utilities/Logger.cpp ../utilities/Logger.h
	@echo "Compiling $<"
	@g++ -c ../utilities/Logger.cpp -o $@





