#include "DBClass.h"
#include <iostream>
#include <string>

void DBClass::printAll()
{
	if (db.size() == 0)
	{
		std::cout << "Error" << std::endl;
	}
	else
	{
		for (int i = 0; i < db.size(); i++)
			db[i].print();
	}
}

int DBClass::load(const std::string& filename)
{
	std::fstream fs;
	fs.open(filename, std::fstream::in);
	if (!fs.is_open())
	{
		return -1;
	}
	std::string tempstr;

	int posB, posE;
	DBRecord tempRecord;

	while (!fs.eof())
	{
		getline(fs, tempstr);
		if (tempstr == "{")
		{
			getline(fs, tempstr);
			posB = tempstr.find("Name");
			if (posB > -1)
			{
				posB += 6;
				posB = tempstr.find("\"", posB);
				posE = tempstr.find("\",");
				tempstr = tempstr.substr(posB + 7, posE - (posB + 7));

				tempRecord.name = tempstr;
			}
		}

	}

	fs.close();
	return 0;
}
