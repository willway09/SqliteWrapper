#ifndef _STATEMENT_HPP
#define _STATEMENT_HPP

class Statement;

#include "sqlite3.h"

#include <string>
#include "Database.hpp"
#include "Parameter.hpp"
#include "StatementException.hpp"
#include "OutputRow.hpp"

class Statement {
	friend class Database;
	private:
		unsigned int* references = nullptr;
		sqlite3_stmt* stmtptr;
		Statement(sqlite3_stmt* stmtptr);
		unsigned int* bindIdx;
		bool* stepDone;

	public:
		~Statement();
		Statement(const Statement& stmt);
		Statement& operator=(const Statement& stmt);

		bool run(OutputRow* oRow = nullptr);
		//void run(Parameter val1, ...);

		void bind(Parameter p);
		void reset();
};

#endif //_STATEMENT_HPP
