#include <iostream>

#include "Database.hpp"

int main() {
  Database db("test.db");
  Database db2 = db;
  Database db3 = db2;
}
