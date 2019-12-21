#pragma once

#include <iostream>
#include <string>
class DBRecord
{
public:
	DBRecord();
	~DBRecord();

	std::string name, lastName, passport;

	void print();

};

