o_files = main.o Logger.o

main: $(o_files)
	@g++ $(o_files) -o main

run: main
	@./main

clean:
	@rm -rf *.o main
	@echo "Cleaned"

.o: ../$@.cpp ../$@.h
	@g++ -c ../$@.cpp .

Logger.o: ../utilities/Logger.h ../utilities/Logger.cpp
	@g++ -c ../utilities/Logger.cpp .





