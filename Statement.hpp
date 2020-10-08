#ifndef _STATEMENT_HPP
#define _STATEMENT_HPP

#include "sqlit3.h"

#include <string>
#include "Database.hpp"



class Statement {
	friend class Database;
	private:
		int* references = nullptr;
		
		Statement(std::string query);
		
	public:
		~Statement();
		Statement(const Statement& stmt);
		Statement& operator=(const Statement& stmt);
		
		void run();
		void run(std::string ...);	
}

#endif //_STATEMENT_HPP

