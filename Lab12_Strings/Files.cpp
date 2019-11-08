#include "Files.h"
#include <iostream>
#include <fstream>
#include <string>

Files::Files()
{
}

Files::~Files()
{
}

void Files::in()
{
	std::cout << "Enter type of way (1 - full, 2 - only name of file): " << std::endl;
	std::cin >> typeOfWay;
	switch (typeOfWay)
	{
	case 1:
		std::cout << "Enter way to file in format: C:\\Users\\User\\Desktop\\img\\img.png." << std::endl;
		std::cin >> fullWayToFile;
		break;
	case 2:
		std::cout << "Enter name of file in format: img.png." << std::endl;
		std::cin >> onlyFile;
		break;
	}
	std::cout << std::endl;
}

void Files::way()
{
	std::string wayToFile;
	int pos;
	switch (typeOfWay)
	{
	case 1:
		wayToFile = fullWayToFile;

		pos = wayToFile.rfind('\\');
		wayToFile.resize(pos + 1);

		std::cout << "Way to file: " << wayToFile << std::endl;
		break;
	case 2:
		std::cout << "The full way to the file is unknown." << std::endl;
		break;
	}
}

void Files::folder()
{
	std::string folderOfFile;
	int pos1, pos2;
	switch (typeOfWay)
	{
	case 1:
		folderOfFile = fullWayToFile;

		pos1 = folderOfFile.rfind('\\');
		folderOfFile.resize(pos1);
		pos2 = folderOfFile.rfind('\\');
		folderOfFile = folderOfFile.substr(pos2, pos1 - pos2);

		std::cout << "Folder of file: " << folderOfFile << std::endl;
		break;
	case 2:
		std::cout << "The full way to the file is unknown." << std::endl;
		break;
	}
}

void Files::file()
{
	std::string nameOfFile;
	int pos1, pos2;
	switch (typeOfWay)
	{
	case 1:
		nameOfFile = fullWayToFile;

		pos1 = nameOfFile.rfind('.');
		nameOfFile.resize(pos1);
		pos2 = nameOfFile.rfind('\\');
		nameOfFile = nameOfFile.substr(pos2 + 1, pos1 - pos2);

		std::cout << "Name of file: " << nameOfFile << std::endl;
		break;
	case 2:
		nameOfFile = onlyFile;

		pos1 = nameOfFile.rfind('.');
		nameOfFile.resize(pos1);
		
		std::cout << "Name of file: " << nameOfFile << std::endl;
		break;
	}
}

void Files::extension()
{
	std::string extensionOfFile;
	int pos;
	switch (typeOfWay)
	{
	case 1:
		extensionOfFile = fullWayToFile;

		pos = extensionOfFile.rfind('.');
		extensionOfFile = extensionOfFile.substr(pos);

		std::cout << "Extension of file: " << extensionOfFile << std::endl;
		break;
	case 2:
		extensionOfFile = onlyFile;

		pos = extensionOfFile.rfind('.');
		extensionOfFile = extensionOfFile.substr(pos);

		std::cout << "Extension of file: " << extensionOfFile << std::endl;
		break;
	}
}

void Files::length()
{
	std::string fullNameOfFile;
	int pos, size;
	switch (typeOfWay)
	{
	case 1:
		fullNameOfFile = fullWayToFile;

		pos = fullNameOfFile.rfind('\\');
		fullNameOfFile = fullNameOfFile.substr(pos);
		size = fullNameOfFile.size() - 1;

		std::cout << "Length of file: " << size << std::endl;
		break;
	case 2:
		fullNameOfFile = onlyFile;

		size = fullNameOfFile.size();

		std::cout << "Length of file: " << size << std::endl;
		break;
	}
}

void Files::copy()
{
	std::ifstream oldFile;
	std::fstream newFile;
	std::string buffer;

	std::string nameOfFile;
	std::string extensionOfFile;

	int pos, pos1, pos2;

	switch (typeOfWay)
	{
	case 1:
		nameOfFile = fullWayToFile;

		pos1 = nameOfFile.rfind('.');
		nameOfFile.resize(pos1);
		pos2 = nameOfFile.rfind('\\');
		nameOfFile = nameOfFile.substr(pos2 + 1, pos1 - pos2);

		extensionOfFile = fullWayToFile;

		pos = extensionOfFile.rfind('.');
		extensionOfFile = extensionOfFile.substr(pos);


		oldFile.open(fullWayToFile, std::fstream::out);
		oldFile >> buffer;
		newFile.open(nameOfFile + "_copy" + extensionOfFile, std::fstream::out);
		newFile << buffer;
		oldFile.close();
		newFile.close();
		break;
	case 2:
		nameOfFile = onlyFile;
		pos = nameOfFile.rfind('.');
		nameOfFile.resize(pos);

		extensionOfFile = onlyFile;

		pos = extensionOfFile.rfind('.');
		extensionOfFile = extensionOfFile.substr(pos);


		oldFile.open(onlyFile, std::fstream::out);
		oldFile >> buffer;
		newFile.open(nameOfFile + "_copy" + extensionOfFile, std::fstream::out);
		newFile << buffer;
		oldFile.close();
		newFile.close();
		break;
	}
}

