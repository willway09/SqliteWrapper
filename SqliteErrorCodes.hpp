#ifndef _SQLITE_ERROR_CODES_HPP
#define _SQLITE_ERROR_CODES_HPP

#include <map>
#include <string>
#include "sqlite3.h"

class SqliteErrorCodes {

	public:
		static const std::string& getErrorMessage(int ec);

		static const std::string& getErrorName(int ec);

	private:
		static bool initialized;

		static std::map<int, const std::string> errorMessages;
		static std::map<int, const std::string> errorNames;


		static void initialize();
};

#endif //_SQLITE_ERROR_CODES_HPP
