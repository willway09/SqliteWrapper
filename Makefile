all: Database.o Statement.o SqliteErrorCodes.o Parameter.o
	g++ -fPIC -shared -L. -o libsqlitewrapper.so main.cpp Database.o Statement.o SqliteErrorCodes.o Parameter.o -lsqlite3 -lpthread
	#sqlite3 test.db "DELETE FROM Test";
	./main

d: Database.o Statement.o SqliteErrorCodes.o Parameter.o
	g++ -L. -o main main.cpp Database.o Statement.o SqliteErrorCodes.o Parameter.o -lsqlite3 -lpthread
	gdb main

Database.o : Database.hpp Database.cpp
	g++ -fPIC -shared -Iinclude -c -o Database.o Database.cpp

DatabaseException.o : DatabaseException.hpp DatabaseException.cpp
		g++ -fPIC -shared -Iinclude -c -o DatabaseException.o DatabaseException.cpp

Statement.o : Statement.hpp Statement.cpp
		g++ -fPIC -shared -Iinclude -c -o Statement.o Statement.cpp

SqliteErrorCodes.o : SqliteErrorCodes.hpp SqliteErrorCodes.cpp
	g++ -fPIC -shared -Iinclude -c -o SqliteErrorCodes.o SqliteErrorCodes.cpp

Parameter.o : Parameter.hpp Parameter.cpp
	g++ -fPIC -shared -Wall -Iinclude -c -o Parameter.o Parameter.cpp

sqlite3: sqlite3.c sqlite3.h
	gcc -o sqlite3.dll -fPIC -shared sqlite3.c


clean:
	rm *.o
	rm main
