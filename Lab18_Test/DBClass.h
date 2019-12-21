#pragma once

#include <vector>
#include "DBRecord.h"
#include <fstream>

class DBClass
{
public:
	std::vector<DBRecord> db;

	void printAll();
	int load(const std::string& filename);
};

