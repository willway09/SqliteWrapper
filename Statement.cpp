#include "Statement.hpp"
#include <iostream>
#include <vector>

#include "Parameter.hpp"

Statement::Statement(sqlite3_stmt* stmtptr) {
	// -- NEEDS IMPLEMENTATION -- //
	references = new unsigned int;
	*references = 1;

	bindIdx = new unsigned int;
	*bindIdx = 1;

	stepDone = new bool;
	*stepDone = true;

	this->stmtptr = stmtptr;
}

Statement::~Statement() {
	if(*references == 1) {
		delete references;
		delete bindIdx;
		sqlite3_finalize(stmtptr);
	} else {
		(*references)--;
	}
}
Statement::Statement(const Statement& stmt) {
	*this = stmt;
}
Statement& Statement::operator=(const Statement& stmt) {
	references = stmt.references;
	stmtptr = stmt.stmtptr;
	bindIdx = stmt.bindIdx;
	stepDone = stmt.stepDone;
	(*references)++;
	return *this;
}

bool Statement::run(OutputRow* oRow) {
	*stepDone = true;

	if(sqlite3_bind_parameter_count(stmtptr) != *bindIdx - 1) {
		throw StatementException("Insufficient number of parameters bound to SQL statement");
	}

	int result;
	do {
		result = sqlite3_step(stmtptr);
	} while(result == SQLITE_BUSY);

	if(result == SQLITE_DONE) {
		reset();
		return false;
	} else if(result == SQLITE_ROW) {
		if(!(oRow->isInitialized())) {
			std::cout << "Initializing" << std::endl;
			int columnCount = 0;
			while(sqlite3_column_type(stmtptr, columnCount + 1) != SQLITE_NULL) columnCount++;
			oRow->initialize(columnCount);
		}

		for(int i = 0; i < oRow->getColumnCount(); i++) {
			int type = sqlite3_column_type(stmtptr, i + 1);

			switch(type) {
				case SQLITE_INTEGER:
					(*oRow)[i] = (int)sqlite3_column_int64(stmtptr, i + 1);
					break;

				case SQLITE_FLOAT:
					(*oRow)[i] = sqlite3_column_double(stmtptr, i + 1);
					break;

				case SQLITE_TEXT:
					(*oRow)[i] = (const char*)sqlite3_column_text(stmtptr, i + 1);
					break;

				/*case SQLITE_BLOB:
					(*oRow)[i] = Parameter(sqlite3_column_text(stmtptr, i + 1), sqlite3_column_bytes(stmtptr, i + 1));
					break;*/

				case SQLITE_NULL:
					(*oRow)[i] = Parameter((void*)nullptr);
					break;
			}
		}

		return true;
	} else {
		throw StatementException(result);
	}



	/*int colCount = 0;

	while(sqlite3_column_type(stmtptr, colCount + 1) != 5) {
		colCount++;
	}

	for(int i = 1; i <= colCount; i++) {
		std::cout << sqlite3_column_type(stmtptr, i) << std::endl;
	}*/
}

/*void Statement::run(Parameter val0, ...) {

	int paramCount = sqlite3_bind_parameter_count(stmtptr);


	std::cout << paramCount << std::endl;

	bind(val0);

	if(paramCount > 1) {


		va_list args;
		va_start(args, val0);

		for(int i = 0; i < paramCount - 1; i++) {

			std::cout << "Type: " << va_arg(args, Parameter).getType() << std::endl;

			//bind(va_arg(args, Parameter));
		}

		va_end(args);
	}

	run();
}*/

void Statement::reset() {
	std::cout << "Reset" << std::endl;
	sqlite3_clear_bindings(stmtptr);
	sqlite3_reset(stmtptr);
	*bindIdx = 1;
}

void Statement::bind(Parameter p) {
	if(sqlite3_bind_parameter_count(stmtptr) < *bindIdx) {
		throw StatementException("Binding more parameters than in SQL statement");
	}

	switch(p.getType()) {
		case Parameter::INTEGER:
			sqlite3_bind_int(stmtptr, *bindIdx, p.getValueInt());
			break;

		case Parameter::REAL:
			sqlite3_bind_double(stmtptr, *bindIdx, p.getValueReal());
			break;

		case Parameter::TEXT:
			sqlite3_bind_text(stmtptr, *bindIdx, p.getValueText().c_str(), -1, SQLITE_TRANSIENT);
			break;

		case Parameter::BLOB:
			sqlite3_bind_blob(stmtptr, *bindIdx, p.getValueBlob(), p.getBlobSize(), SQLITE_TRANSIENT);
			break;

		case Parameter::NULLTYPE:
			sqlite3_bind_null(stmtptr, *bindIdx);
			break;
	}
	(*bindIdx)++;
}
