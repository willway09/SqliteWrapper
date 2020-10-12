#ifndef _PARAMETER_HPP
#define _PARAMETER_HPP

#include <string>
#include <iostream>

class Parameter {
public:
  enum Type { NULLTYPE, INTEGER, REAL, TEXT, BLOB };

private:
  Type type;

  //Probably should use a union, but it doesn't work well with std::string and dynamic allocations
  //Could also use void*, but that seems risky...
  int intVal = 0;
  double realVal = 0;
  std::string textVal;
  void* blobVal = nullptr;
  int blobSize = 0;

public:
  Parameter(int val);
  Parameter(double val);
  Parameter(std::string& val);
  Parameter(const char* val);
  Parameter(void* obj, int size = 0);


  Parameter::Type getType();

  const int getValueInt() const;
  const double getValueReal() const;
  const std::string& getValueText() const;
  const void* getValueBlob() const;
  const int getBlobSize() const;


};

#endif //_PARAMETER_HPP
