#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <iterator>

int main()
{
	std::list<std::string> myList;

	//empty
	std::cout << "myList.empty(): ";
	std::cout << myList.empty() << std::endl;
	std::cout << std::endl;
	
	//size
	std::cout << "myList.size(): ";
	std::cout << myList.size() << std::endl;
	std::cout << std::endl;

	//push_back
	std::fstream fs;
	std::string filename = "block.txt";
	std::string tempstr;

	fs.open(filename, std::fstream::in);
	
	while (!fs.eof())
	{
		getline(fs, tempstr);
		myList.push_back(tempstr);
	}

	fs.close();

	std::cout << "Entered text:" << std::endl;
	std::copy(myList.begin(), myList.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;

	//empty
	std::cout << "myList.empty(): ";
	std::cout << myList.empty() << std::endl;
	std::cout << std::endl;

	//size
	std::cout << "myList.size(): ";
	std::cout << myList.size() << std::endl;
	std::cout << std::endl;

	//front
	std::cout << "myList.front(): " << std::endl;
	std::cout << myList.front() << std::endl;
	std::cout << std::endl;

	//back
	std::cout << "myList.back(): " << std::endl;
	std::cout << myList.back() << std::endl;
	std::cout << std::endl;

	//clear
	std::cout << "myList.clear() " << std::endl;
	myList.clear();

	//empty
	std::cout << "myList.empty(): ";
	std::cout << myList.empty() << std::endl;
	std::cout << std::endl;

	//push_front
	fs.open(filename, std::fstream::in);

	while (!fs.eof())
	{
		getline(fs, tempstr);
		myList.push_front(tempstr);
	}

	fs.close();

	std::cout << "Entered text:" << std::endl;
	std::copy(myList.begin(), myList.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;

	//pop_back, pop_front
	std::cout << "pop_back(), pop_front() X 2: " << std::endl;
	for (int i = 0; i < 2; i++)
	{
		myList.pop_back();
		myList.pop_front();
	}
	std::copy(myList.begin(), myList.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;
	
	//clear
	std::cout << "myList.clear() " << std::endl;
	myList.clear();
	std::cout << std::endl;

	//insert
	std::cout << "myList.insert():" << std::endl;
	fs.open(filename, std::fstream::in);

	while (!fs.eof())
	{
		getline(fs, tempstr);
		myList.insert(myList.end(), tempstr);
	}

	fs.close();

	std::cout << "Entered text:" << std::endl;
	std::copy(myList.begin(), myList.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;

	//erase
	std::cout << "myList.erase()" << std::endl;
	myList.erase(myList.begin(), myList.end());
	std::cout << std::endl;

	std::cout << "Entered text:" << std::endl;
	std::copy(myList.begin(), myList.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;

	//sort
	fs.open(filename, std::fstream::in);

	while (!fs.eof())
	{
		getline(fs, tempstr);
		myList.insert(myList.end(), tempstr);
	}

	fs.close();

	std::cout << "Entered text:" << std::endl;
	std::copy(myList.begin(), myList.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;

	std::cout << "myList.sort()" << std::endl;
	myList.sort();
	std::cout << std::endl;

	std::cout << "Sorted text:" << std::endl;
	std::copy(myList.begin(), myList.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;

	//merge
	std::cout << "myList.merge()" << std::endl;
	myList.sort();
	std::cout << std::endl;

	std::list<std::string> myList2;
	std::string filename2 = "block2.txt";
	fs.open(filename2, std::fstream::in);

	while (!fs.eof())
	{
		getline(fs, tempstr);
		myList2.push_back(tempstr);
	}

	fs.close();

	std::cout << "Entered text 2:" << std::endl;
	std::copy(myList2.begin(), myList2.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;

	myList2.sort();

	myList.merge(myList2);

	std::cout << "Merged texts:" << std::endl;
	std::copy(myList.begin(), myList.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;

	//unique
	std::cout << "myList.unique()" << std::endl;
	myList.unique();
	std::cout << std::endl;

	std::cout << "Unique text:" << std::endl;
	std::copy(myList.begin(), myList.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;

	//remove, remove if
	myList.remove("To find law in the lawless swirling feeling -"); 
	myList.remove_if([](std::string n) { return n[0] == 'A'; }); 

	std::cout << "Removed text:" << std::endl;
	std::copy(myList.begin(), myList.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;

	//swap
	myList.clear();
	myList2.clear();

	fs.open(filename2, std::fstream::in);

	while (!fs.eof())
	{
		getline(fs, tempstr);
		myList2.push_back(tempstr);
	}

	fs.close();

	fs.open(filename, std::fstream::in);

	while (!fs.eof())
	{
		getline(fs, tempstr);
		myList.push_back(tempstr);
	}

	fs.close();

	std::cout << "myList.swap()" << std::endl;
	std::cout << std::endl;

	std::cout << "Entered text 1:" << std::endl;
	std::copy(myList.begin(), myList.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;

	std::cout << "Entered text 2:" << std::endl;
	std::copy(myList2.begin(), myList2.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;

	myList.swap(myList2);

	std::cout << "Swaped text 1:" << std::endl;
	std::copy(myList.begin(), myList.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;

	std::cout << "Swaped text 2:" << std::endl;
	std::copy(myList2.begin(), myList2.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
	std::cout << std::endl;
}
