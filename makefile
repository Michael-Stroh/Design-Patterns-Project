CXX=g++ 
CFLAGS=-I. -std=c++17 -Wall -g 
TARGET= main
OBJS= AggressiveDriving.o CautiousDriving.o ControlledDriving.o Driver.o DriverStrategy.o Hard.o Medium.o Soft.o Tyre.o TyreStrategy.o RaceStrategy.o PitCrew.o PartReplacer.o PitStop.o PitStopStrategy.o RaceTrack.o Circuit.o CompositeRoad.o CircuitIterator.o Iterator.o CarComponenets.o CateringEquipment.o GarageEquipment.o Container.o LogisticsStrategy.o Logistics.o Main.o

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)
    
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
    
clean:
	rm -f $(TARGET) $(OBJS)
	
run:
	./main
	
valgrind: 	
	valgrind -s --leak-check=yes ./main

