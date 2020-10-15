#include <iostream>

#include "Database.hpp"
#include "Statement.hpp"
#include "OutputRow.hpp"

int main() {
  Database db("test.db");

  //Statement stmt = db.prepare("INSERT INTO Test (name, age) VALUES (?, ?);");
  Statement stmt = db.prepare("SELECT * FROM Test WHERE name LIKE (?);");

  stmt.bind("%%");

  OutputRow oRow;
  while(stmt.run(&oRow)) {
    std::cout << oRow[0].getValueText() << " " << oRow[1].getValueInt() << std::endl;
  }

  stmt.bind("Will");
  while(stmt.run(&oRow)) {
    std::cout << oRow[0].getValueText() << " " << oRow[1].getValueInt() << std::endl;
  }

  Database memory;

  Statement create = memory.prepare("CREATE TABLE Asdf (num INTEGER, string VARCHAR(255));");
  Statement insert = memory.prepare("INSERT INTO Asdf VALUES ((?), (?));");
  Statement output = memory.prepare("SELECT * FROM Asdf;");

  create.run();

  insert.bind(5);
  insert.bind("Billy");

  insert.run();

  OutputRow asdf;

  while(stmt.run(&asdf)) {
    std::cout << asdf[0].getValueInt() << " " << asdf[1].getValueText() << std::endl;
  }


}
