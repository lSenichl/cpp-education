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
	std::cout << name << "\t" << lastName << "\t" << passport << std::endl;
}