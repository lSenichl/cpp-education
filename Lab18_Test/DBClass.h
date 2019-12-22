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
	int find(const std::string& second);
	int add(const std::string& name, const std::string& second_name, const std::string& passport);
	int remove(const int n);
	void save(const std::string& filename);
	void sort(bool is);
};

