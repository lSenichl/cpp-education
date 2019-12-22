#include <iostream>
#include <stack>

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

int main()
{
	task1();
}

//(7834[2423](234{423}24))