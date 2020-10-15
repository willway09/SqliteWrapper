#ifndef _DATABASE_HPP
#define _DATABASE_HPP

class Database;

#include <string>

#include "sqlite3.h"
#include "Statement.hpp"
#include "StatementException.hpp"
#include "SqliteErrorCodes.hpp"

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


  Statement prepare(const std::string& query);

};

#endif //_DATABASE_HPP
