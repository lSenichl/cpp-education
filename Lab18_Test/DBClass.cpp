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
				posB += 7;
				posE = tempstr.rfind("\",");
				tempstr = tempstr.substr(posB, posE-posB);

				tempRecord.name = tempstr;
			}

			getline(fs, tempstr);
			posB = tempstr.find("Second name");
			if (posB > -1)
			{
				posB += 14;
				posE = tempstr.rfind("\",");
				tempstr = tempstr.substr(posB, posE - posB);

				tempRecord.lastName = tempstr;
			}

			getline(fs, tempstr);
			posB = tempstr.find("Passport");
			if (posB > -1)
			{
				posB += 11;
				posE = tempstr.rfind("\"");
				tempstr = tempstr.substr(posB, posE - posB);

				tempRecord.passport = tempstr;
			}

			db.push_back(tempRecord);
		}
	}

	fs.close();
	return 0;
}

int DBClass::find(const std::string& second)
{
	for (int i = 0; i < db.size(); i++)
	{
		if (db[i].lastName.substr(0, second.size()) == second)
		{
			std::cout << "Number of \"" << second << "\" in BD: " << i << std::endl;
			return 0;
		}
	}
	
	std::cout << "-";
	return -1;
}

int DBClass::add(const std::string& name, const std::string& second_name, const std::string& passport)
{
	int error = 0;

	if (!(name[0] > 64 && name[0] < 91))
	{
		error++;
	}
	for (int i = 1; i < name.size(); i++)
	{
		if (!(name[i] > 96 && name[i] < 123))
		{
			error++;
		}
	}
	
	if (!(second_name[0] > 64 && second_name[0] < 91))
	{
		error++;
	}
	for (int i = 1; i < second_name.size(); i++)
	{
		if (!(second_name[i] > 96 && second_name[i] < 123))
		{
			error++;
		}
	}

	for (int i = 0; i < passport.size(); i++)
	{
		if (i != 4)
		{
			if (!(passport[i] > 47 && passport[i] < 58))
			{
				error++;
			}
		}
		else
		{
			if (passport[i] != ' ')
			{
				error++;
			}
		}
	}
	
	if (error == 0)
	{
		DBRecord tempRecord;
		tempRecord.name = name;
		tempRecord.lastName = second_name;
		tempRecord.passport = passport;

		db.push_back(tempRecord);

		return db.size();
	}
	else
	{
		return -1;
	}
}

int DBClass::remove(const int n)
{
	if (db[n].name.size() > 0)
	{
		db.erase(db.begin()+n);

		return n;
	}
	else
	{
		return -1;
	}
}

void DBClass::save(const std::string& filename)
{
	std::fstream fs;
	fs.open(filename, std::fstream::out);

	for (int i = 0; i < db.size(); i++)
	{
		fs << "{" << std::endl;
		fs << "\t" << "\"Name\"=\"" << db[i].name << "\"," << std::endl;
		fs << "\t" << "\"Second name\"=\"" << db[i].lastName << "\"," << std::endl;
		fs << "\t" << "\"Passport\"=\"" << db[i].passport << "\"" << std::endl;
		fs << "}" << std::endl;
	}
}

void DBClass::sort(bool is)
{
	for (int i = 0; i < db.size() - 1; i++)
	{
		for (int j = 0; j < db.size() - i - 1; j++)
		{
			if (db[j].lastName[0] > db[j + 1].lastName[0])
			{
				std::swap(db[j], db[j + 1]);
			}
		}
	}
}
