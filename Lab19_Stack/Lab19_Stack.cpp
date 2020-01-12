#include <iostream>
#include <stack>
#include <queue>
#include <iterator>
#include <deque>
#include <set>
#include <map>

void task1()
{
	std::stack<char> myStack;
	std::string myString;

	std::cin >> myString;

	for (int i = 0; i < myString.size(); i++)
	{
		if (myString[i] == '{' ||
			myString[i] == '}' || 
			myString[i] == '[' || 
			myString[i] == ']' || 
			myString[i] == '(' || 
			myString[i] == ')' )
		{
			if(myStack.empty())
				myStack.push(myString[i]);
			else
			{
				switch (myString[i]) 
				{
				case ')':
					if (myStack.top() == '(')
						myStack.pop();
					break;
				case ']':
					if (myStack.top() == '[')
						myStack.pop();
					break;
				case '}':
					if (myStack.top() == '{')
						myStack.pop();
					break;
				default:
					myStack.push(myString[i]);
				}
			}
		}
	}

	if (myStack.empty())
		std::cout << "+" << std::endl;
	else
		std::cout << "-" << std::endl;
}

void task2()
{
	int tempClass;
	std::string tempName;
	int q;
	std::queue<std::string> class9, class10, class11;
	
	std::cout << "Enter the quantity: ";
	std::cin >> q;

	for (int i = 0; i < q; i++)
	{
		std::cin >> tempClass;

		switch (tempClass)
		{
		case 9:
			std::cin >> tempName;
			class9.push(tempName);
			break;
		case 10:
			std::cin >> tempName;
			class10.push(tempName);
			break;
		case 11:
			std::cin >> tempName;
			class11.push(tempName);
			break;
		default:
			break;
		}
	}

	std::cout << std::endl;
	std::cout << "9 class: " << std::endl;
	while (!class9.empty())
	{
		std::cout << class9.front() << std::endl;
		class9.pop();
	}
	std::cout << std::endl;

	std::cout << "10 class: " << std::endl;
	while (!class10.empty())
	{
		std::cout << class10.front() << std::endl;
		class10.pop();
	}
	std::cout << std::endl;

	std::cout << "11 class: " << std::endl;
	while (!class11.empty())
	{
		std::cout << class11.front() << std::endl;
		class11.pop();
	}
	std::cout << std::endl;
}

void task3()
{
	bool answ = true;
	std::cout << "Enter the number: ";
	std::string str;
	std::cin >> str;
	std::deque<int> d;

	for (int i = 0; i < str.size(); i++)
	{
		d.push_back(str[i]);
	}

	while (!d.empty())
	{
		if (d.front() == d.back())
		{
			d.pop_back();
			if (!d.empty())
			{
				d.pop_front();
			}
		}
		else
		{
			std::cout << "Not palindrom." << std::endl;
			answ = false;
			break;
		}
	}

	if (answ)
	{
		std::cout << "Palindrom" << std::endl;
	}
}

void task4()
{
	//Lab17_List
}

void task5()
{
	std::set<char> mySet;

	mySet.insert('a');
	mySet.insert('b');
	mySet.insert('c');
	mySet.insert('d');
	mySet.insert('e');
	mySet.insert('f');
	mySet.insert('g');
	mySet.insert('h');

	std::cout << "Inserted elements: " << std::endl;
	copy(mySet.begin(), mySet.end(), std::ostream_iterator<char>(std::cout, " "));
	std::cout << std::endl;

	mySet.erase(mySet.find('c'),mySet.find('g'));

	std::cout << "After erase c-g:" << std::endl;
	copy(mySet.begin(), mySet.end(), std::ostream_iterator<char>(std::cout, " "));
}

void task6()
{
	std::map<int, std::string> myMap = { { 0, "A" },{ 1, "B" },{ 2, "C" },{ 3, "D" } };

	std::cout << "Entered map: " << std::endl;
	for (int i = 0; i < myMap.size(); i++)
	{
		std::cout << myMap[i] << std::endl;
	}

	myMap.insert({ 4, "E" });
	
	std::cout << "Map after insert: " << std::endl;
	for (int i = 0; i < myMap.size(); i++)
	{
		std::cout << myMap[i] << std::endl;
	}

	myMap.erase(myMap.begin());
	myMap[1].erase();
	myMap.erase(3);

	std::cout << "Map after erase: " << std::endl;
	for (int i = 0; i < myMap.size(); i++)
	{
		std::cout << myMap[i] << std::endl;
	}
}

void task7()
{
	//comparison.docx
}

int main()
{
	task1();

	task2();

	task3();

	//task4();

	task5();

	task6();

	//task7();
}
