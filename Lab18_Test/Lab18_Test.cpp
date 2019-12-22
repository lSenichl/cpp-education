#include <iostream>
#include "DBClass.h"
#include "DBRecord.h"

int main()
{
	DBClass myBD;

	myBD.load(".txt");

	std::cout << "Entered BD: " << std::endl;
	myBD.printAll();
	std::cout << std::endl;

	myBD.find("Smith");

	std::cout << "Record was added in number: ";
	std::cout << myBD.add("Adam", "Trump", "2223 839392") << std::endl;
	std::cout << std::endl;

	std::cout << "Record on number: ";
	std::cout << myBD.remove(3) << " was deleted." << std::endl;
	std::cout << std::endl;

	std::cout << "Not sorted BD: " << std::endl;
	myBD.printAll();
	std::cout << std::endl;

	myBD.sort(true);

	std::cout << "Sorted BD:" << std::endl;
	myBD.printAll();
	std::cout << std::endl;

	myBD.save("myBD.txt");
}
