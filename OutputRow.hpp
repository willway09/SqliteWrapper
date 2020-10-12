#ifndef _OUTPUTROW_HPP
#define _OUTPUTROW_HPP

#include <vector>
#include "Parameter.hpp"

class OutputRow {
private:
  bool initialized = false;
  int columnCount = 0;

  std::vector<Parameter> params;

public:
  void initialize(int count) {
    columnCount = count;
    initialized = true;
    for(int i = 0; i < count; i++) {
      Parameter test((void*)nullptr);
      params.push_back(Parameter((void*)nullptr));
    }
  }

  Parameter& operator[](int i) {
    return params[i];
  }

  bool isInitialized() {
    return initialized;
  }

  int getColumnCount() {
    return columnCount;
  }

};

#endif //_OUTPUTROW_HPP
