#include <iostream>

int task1()
{
	int size;
	std::cin >> size;
	int *arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	int numb;
	std::cin >> numb;
	bool temp = true;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == numb)
		{
			temp = false;
			return i;
		}
	}
	if (temp)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > numb)
			{
				return i;
			}
		}
	}

}

int main()
{

	std::cout << task1() << std::endl;
}