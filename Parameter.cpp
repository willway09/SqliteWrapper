#include "Parameter.hpp"

#include "sqlite3.h"

#include <cstring>
#include <cstdio>

Parameter::Parameter(int val) {
  intVal = val;
  type = INTEGER;
}

Parameter::Parameter(double val) {
  realVal = val;
  type = REAL;
}

Parameter::Parameter(const char* val) {
  textVal = val;
  type = TEXT;
}

Parameter::Parameter(std::string& val) {
  textVal = val;
  type = TEXT;
}

Parameter::Parameter(void* obj, int size) {
  if(obj == nullptr) {
    type = NULLTYPE;
  } else {
    blobVal = obj;
    blobSize = size;
    type = BLOB;
  }
}

Parameter::Type Parameter::getType() {
  return type;
}

const int Parameter::getValueInt() const {
    return intVal;
}

const double Parameter::getValueReal() const {
  return realVal;
}

const std::string& Parameter::getValueText() const {
  return textVal;
}

const void* Parameter::getValueBlob() const {
  return blobVal;
}

const int Parameter::getBlobSize() const {
  return blobSize;
}
