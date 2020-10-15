#include "Database.hpp"
#include "DatabaseException.hpp"

#include "SqliteErrorCodes.hpp"

#include <iostream>
#include <string>


Database::Database(std::string dbName) {
  references = new unsigned int;
  *references = 1;


  char* zErrMsg = 0;
  int rc;

  if(!dbName.compare("")) {
    rc = sqlite3_open_v2("memory", &db, SQLITE_OPEN_MEMORY, NULL);
  } else {
    rc = sqlite3_open(dbName.c_str(), &db);
  }

  if(rc) {
    sqlite3_close(db);
    std::cout << SqliteErrorCodes::getErrorName(sqlite3_extended_errcode(db)) << std::endl;
    throw DatabaseException(std::string("The database could not be opened at this times: ") + sqlite3_errmsg(db));
  }
}


//The big three
Database::~Database() {
  if(*references == 1) {
    sqlite3_close(db);
    delete references;
  } else {
    (*references)--;
  }

}


Database& Database::operator=(const Database& db) {
  references = db.references;

  *references++;
  return *this;
}


Database::Database(const Database& db) {
  *this = db;
}

Statement Database::prepare(const std::string& query) {

	sqlite3_stmt* stmtptr = NULL;
	const char* zTail = NULL;

	int success = sqlite3_prepare_v2(db, query.c_str(), -1, &stmtptr, &zTail);

	return Statement(stmtptr);

}
