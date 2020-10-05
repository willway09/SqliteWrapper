#ifndef _DATABASE_HPP
#define _DATABASE_HPP

#include <string>

#include "sqlite3.h"


class Database {
private:
  unsigned int* references = nullptr;
  sqlite3* db = NULL; //For C compatability

public:
  //Constructors
  Database(std::string dbName = "");

  //The big three
  ~Database();
  Database(const Database& db);
  Database& operator=(const Database& db);



};

#endif //_DATABASE_HPP
