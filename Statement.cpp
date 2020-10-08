#include "Statement.hpp"

Statement(std::string query) {
	// -- NEEDS IMPLEMENTATION -- //
	references = nullptr;
	*references = 1;
}
		
~Statement() {
	if(*references == 1) {
		delete references;
	} else {
		(*references)--
	}
}
Statement(const Statement& stmt) {
	*this = stmt;
}
Statement& operator=(const Statement& stmt) {
	references = stmt.references;
	(*references)++;
}

void run() {
	// -- NEEDS IMPLEMENTATION -- //
}
void run(std::string ...) {
	// -- NEEDS IMPLEMENTATION -- //
}