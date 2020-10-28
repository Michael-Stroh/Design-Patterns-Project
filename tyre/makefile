CXX=g++ 
CFLAGS=-I. -std=c++17 -Wall -g 
TARGET= main
OBJS= Hard.o Medium.o Soft.o Tyre.o TyreStrategy.o Main.o
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

