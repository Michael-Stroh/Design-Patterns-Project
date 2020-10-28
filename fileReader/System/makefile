CXX=g++ 
CFLAGS=-I. -std=c++17 -Wall -g 
TARGET= main
OBJS= testerForFileReader.o
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

