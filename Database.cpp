#include "Database.hpp"
#include "DatabaseException.hpp"

#include <iostream>
#include <string>


Database::Database(std::string dbName) {
  std::cout << "Database created" << std::endl;

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
    throw DatabaseException(std::string("The database could not be opened at this times: ") + sqlite3_errmsg(db));
  }
}


//The big three
Database::~Database() {
  if(*references == 1) {
    std::cout << "Destroying database" << std::endl;
    sqlite3_close(db);
  } else {
    std::cout << "One reference removed" << std::endl;
    (*references)--;
  }

}


Database& Database::operator=(const Database& db) {
  std::cout << "New reference created" << std::endl;

  references = db.references;

  *references++;
  return *this;
}


Database::Database(const Database& db) {
  *this = db;
}
