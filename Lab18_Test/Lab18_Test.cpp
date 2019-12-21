#include <iostream>
#include "DBClass.h"
#include "DBRecord.h"

int main()
{
	DBClass myBD;

	myBD.load(".txt");

	myBD.printAll();
}
