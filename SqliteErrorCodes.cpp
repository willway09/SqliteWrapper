#include "SqliteErrorCodes.hpp"

#include <iostream>

void SqliteErrorCodes::initialize() {
    errorMessages.emplace(SQLITE_OK, "Successful result");
    errorMessages.emplace(SQLITE_ERROR, "Generic error");
    errorMessages.emplace(SQLITE_INTERNAL, "Internal logic error in SQLite");
    errorMessages.emplace(SQLITE_PERM, "Access permission denied");
    errorMessages.emplace(SQLITE_ABORT, "Callback routine requested an abort");
    errorMessages.emplace(SQLITE_BUSY, "The database file is locked");
    errorMessages.emplace(SQLITE_LOCKED, "A table in the database is locked");
    errorMessages.emplace(SQLITE_NOMEM, "A malloc() failed");
    errorMessages.emplace(SQLITE_READONLY, "Attempt to write a readonly database");
    errorMessages.emplace(SQLITE_INTERRUPT, "Operation terminated by sqlite3_interrupt()");
    errorMessages.emplace(SQLITE_IOERR, "Some kind of disk I/O error occurred");
    errorMessages.emplace(SQLITE_CORRUPT, "The database disk image is malformed");
    errorMessages.emplace(SQLITE_NOTFOUND, "Unknown opcode in sqlite3_file_control()");
    errorMessages.emplace(SQLITE_FULL, "Insertion failed because database is full");
    errorMessages.emplace(SQLITE_CANTOPEN, "Unable to open the database file");
    errorMessages.emplace(SQLITE_PROTOCOL, "Database lock protocol error");
    errorMessages.emplace(SQLITE_EMPTY, "Internal use only");
    errorMessages.emplace(SQLITE_SCHEMA, "The database schema changed");
    errorMessages.emplace(SQLITE_TOOBIG, "String or BLOB exceeds size limit");
    errorMessages.emplace(SQLITE_CONSTRAINT, "Abort due to constraint violation");
    errorMessages.emplace(SQLITE_MISMATCH, "Data type mismatch");
    errorMessages.emplace(SQLITE_MISUSE, "Library used incorrectly");
    errorMessages.emplace(SQLITE_NOLFS, "Uses OS features not supported on host");
    errorMessages.emplace(SQLITE_AUTH, "Authorization denied");
    errorMessages.emplace(SQLITE_FORMAT, "Not used");
    errorMessages.emplace(SQLITE_RANGE, "2nd parameter to sqlite3_bind out of range");
    errorMessages.emplace(SQLITE_NOTADB, "File opened that is not a database file");
    errorMessages.emplace(SQLITE_NOTICE, "Notifications from sqlite3_log()");
    errorMessages.emplace(SQLITE_WARNING, "Warnings from sqlite3_log()");
    errorMessages.emplace(SQLITE_ROW, "sqlite3_step() has another row ready");
    errorMessages.emplace(SQLITE_DONE, "sqlite3_step() has finished executing");
    errorMessages.emplace(-1, "No associated SQLite error code");

    errorNames.emplace(SQLITE_OK, "SQLITE_OK");
    errorNames.emplace(SQLITE_ERROR, "SQLITE_ERROR");
    errorNames.emplace(SQLITE_INTERNAL, "SQLITE_INTERNAL");
    errorNames.emplace(SQLITE_PERM, "SQLITE_PERM");
    errorNames.emplace(SQLITE_ABORT, "SQLITE_ABORT");
    errorNames.emplace(SQLITE_BUSY, "SQLITE_BUSY");
    errorNames.emplace(SQLITE_LOCKED, "SQLITE_LOCKED");
    errorNames.emplace(SQLITE_NOMEM, "SQLITE_NOMEM");
    errorNames.emplace(SQLITE_READONLY, "SQLITE_READONLY");
    errorNames.emplace(SQLITE_INTERRUPT, "SQLITE_INTERRUPT");
    errorNames.emplace(SQLITE_IOERR, "SQLITE_IOERR");
    errorNames.emplace(SQLITE_CORRUPT, "SQLITE_CORRUPT");
    errorNames.emplace(SQLITE_NOTFOUND, "SQLITE_NOTFOUND");
    errorNames.emplace(SQLITE_FULL, "SQLITE_FULL");
    errorNames.emplace(SQLITE_CANTOPEN, "SQLITE_CANTOPEN");
    errorNames.emplace(SQLITE_PROTOCOL, "SQLITE_PROTOCOL");
    errorNames.emplace(SQLITE_EMPTY, "SQLITE_EMPTY");
    errorNames.emplace(SQLITE_SCHEMA, "SQLITE_SCHEMA");
    errorNames.emplace(SQLITE_TOOBIG, "SQLITE_TOOBIG");
    errorNames.emplace(SQLITE_CONSTRAINT, "SQLITE_CONSTRAINT");
    errorNames.emplace(SQLITE_MISMATCH, "SQLITE_MISMATCH");
    errorNames.emplace(SQLITE_MISUSE, "SQLITE_MISUSE");
    errorNames.emplace(SQLITE_NOLFS, "SQLITE_NOLFS");
    errorNames.emplace(SQLITE_AUTH, "SQLITE_AUTH");
    errorNames.emplace(SQLITE_FORMAT, "SQLITE_FORMAT");
    errorNames.emplace(SQLITE_RANGE, "SQLITE_RANGE");
    errorNames.emplace(SQLITE_NOTADB, "SQLITE_NOTADB");
    errorNames.emplace(SQLITE_NOTICE, "SQLITE_NOTICE");
    errorNames.emplace(SQLITE_WARNING, "SQLITE_WARNING");
    errorNames.emplace(SQLITE_ROW, "SQLITE_ROW");
    errorNames.emplace(SQLITE_DONE, "SQLITE_DONE");
    errorNames.emplace(-1, "SQLITE_NONE");

    initialized = true;
}

const std::string& SqliteErrorCodes::getErrorMessage(int ec) {
  if(!initialized) initialize();
  return errorMessages[ec];
}

const std::string& SqliteErrorCodes::getErrorName(int ec) {
  if(!initialized) initialize();
  return errorNames[ec];
}


bool SqliteErrorCodes::initialized = false;
std::map<int, const std::string> SqliteErrorCodes::errorNames = std::map<int, const std::string>();
std::map<int, const std::string> SqliteErrorCodes::errorMessages = std::map<int, const std::string>();
