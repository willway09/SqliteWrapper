#ifndef _DATABASEEXCEPTION_HPP
#define _DATABASEEXCEPTION_HPP

#include <stdexcept>

class DatabaseException : public std::exception {
private:
    std::string description;

public:
  DatabaseException(const std::string& s) {
    description = s;
  }

  virtual const char* what() const throw() {
    return description.c_str();
  }
};

#endif //_DATABASEEXCEPTION_HPP
