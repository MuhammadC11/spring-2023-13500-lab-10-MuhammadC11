
main: main.o time.o
	g++ -o main main.o time.o

tests: tests.o time.o
	g++ -o tests tests.o time.o

main.o: main.cpp time.h movie.h timeslot.h
	g++ -c -std=c++11 main.cpp

tests.o: tests.cpp doctest.h time.h movie.h timeslot.h
	g++ -c -std=c++11 tests.cpp

time.o: time.cpp time.h
	g++ -c -std=c++11 time.cpp

clean:
	rm -f main.o time.o tests.o