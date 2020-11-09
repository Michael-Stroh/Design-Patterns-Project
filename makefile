_o_files = Main_File_Final.o Logger.o Result.o LapResult.o RaceSeason.o RaceSeasonResult.o SeasonSubject.o GrandPrix.o RaceTeam.o GrandPrixResult.o Subject.o Race.o EngineeringCrew.o RaceResult.o RaceSubject.o PracticeState.o QualifyingState.o OfficialState.o RaceState.o Driver.o RaceTrack.o Circuit.o CompositeRoad.o ControlledDriving.o Strategies.o PitStopStrategy.o RaceStrategy.o DriverStrategy.o CarComposite.o TyreStrategy.o Tyre.o CarBuilder.o Budget.o Car.o CarMemento.o Body.o Engine.o Soft.o Medium.o Hard.o EngineFactory.o ChassisFactory.o TransmissionFactory.o SteeringFactory.o CoolingFactory.o BodyFactory.o SuspensionFactory.o BrakesFactory.o ElectronicFactory.o EngineeringDepartment.o CarPartFactory.o Electronics.o Brakes.o CarPart.o PartState.o EngineDepartment.o ChassisDepartment.o CircuitIterator.o AccelerationSimulation.o Suspension.o CoolingSystem.o SteeringWheel.o ElectronicsDepartment.o Simulation.o HandlingSimulation.o Transmission.o Iterator.o PitStop.o CautiousDriving.o AggressiveDriving.o Chassis.o AerodynamicsDepartment.o QualifyingRaceSubject.o OfficialRaceSubject.o LogisticsStrategy.o SpeedSimulation.o PitCrew.o Logistics.o WindTunnel.o Container.o
o_files = $(patsubst %,$(OBJDIR)/%,$(_o_files))
OBJDIR = Build
SYSTEMDIR = System

main: $(o_files)
	@g++ -o main $(o_files)

run: main
	@echo "" 
	@echo "[Makefile] Running" 
	@./main

clean:
	@rm -rf $(OBJDIR)/*.o main Final.tar.gz
	@echo "[Makefile] Cleaned"

compress: clean
	@echo "[Makefile] Compressing"
	@tar -cvzf Final.tar.gz Build/ System/ Data/ Report/ makefile readme.txt

$(OBJDIR)/%.o: $(SYSTEMDIR)/%.cpp
	@echo "[Makefile] Compiling $<"
	@g++ -c $< -o $@

$(OBJDIR)/%.o: $(SYSTEMDIR)/%.cpp $(SYSTEMDIR)/%.h
	@echo "[Makefile] Compiling $<"
	@g++ -c $< -o $@

$(OBJDIR)/Logger.o: $(SYSTEMDIR)/utilities/Logger.cpp $(SYSTEMDIR)/utilities/Logger.h
	@echo "[Makefile] Compiling $<"
	@g++ -c $(SYSTEMDIR)/utilities/Logger.cpp -o $@





