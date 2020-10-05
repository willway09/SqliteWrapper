all: Database.o DatabaseException.o
	g++ -o main main.cpp Database.o -lsqlite3 -lpthread -ldl
	./main

Database.o : Database.hpp Database.cpp
	g++ -Iinclude -c -o Database.o Database.cpp

DatabaseException.o : DatabaseException.hpp DatabaseException.cpp
		g++ -Iinclude -c -o DatabaseException.o DatabaseException.cpp



clean:
	rm *.o
	rm main
