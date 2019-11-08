#pragma once
#include <string>

class Files
{
private:
	std::string fullWayToFile;
	std::string onlyFile;
	int typeOfWay;

public:
	Files();
	~Files();

	void in();
	void way();
	void folder();
	void file();
	void extension();
	void length();
	void copy();

};

