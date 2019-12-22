#include "DBRecord.h"
#include <fstream>

DBRecord::DBRecord()
{
}

DBRecord::~DBRecord()
{
}

void DBRecord::print()
{
	std::string tName = name;
	std::string tLastName = lastName;
	std::string tPassport = passport;

	tName.resize(15);
	tLastName.resize(15);
	tPassport.resize(15);

	std::cout << tName << "\t" << tLastName << "\t" << tPassport << std::endl;
}