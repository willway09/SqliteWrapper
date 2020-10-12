#ifndef _STATEMENTEXCEPTION_HPP
#define _STATEMENTEXCEPTION_HPP

#include <stdexcept>
#include "SqliteErrorCodes.hpp"

class StatementException : public std::exception {
private:
    std::string description;
    int errorCode;

public:
  StatementException(const std::string& s) {
    description = s;
    errorCode = -1;
  }

  StatementException(int code) {
    errorCode = code;
    description = SqliteErrorCodes::getErrorName(errorCode) + ": " + SqliteErrorCodes::getErrorMessage(errorCode);
  }

  int getErrorCode() { return errorCode ;}

  virtual const char* what() const throw() {
    return description.c_str();
  }
};

#endif //_STATEMENTEXCEPTION_HPP
