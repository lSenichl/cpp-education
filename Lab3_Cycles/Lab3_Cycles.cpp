#include <iostream>
#include<locale.h> 

int main()
{
	setlocale(LC_ALL, "RUS");
	
	int sumEven = 0, sumUneven = 0, sumAll = 0, b = 0, c = 0, d = 0;
	std::cin >> d;
	int temp = d;

	while (d > 0)
	{
		b = d % 10;
		d = d / 10;
		sumAll = sumAll + b;
		c = c * 10 + b;

		switch (b % 2)
		{
		case 0:
			sumEven = sumEven + b;
			break;
		case 1:
			sumUneven = sumUneven + b;
			break;
		}
	}

	if (sumEven == 0)
		std::cout << "Чётных нет" << std::endl;
	else
		std::cout << "Сумма чётных: " << sumEven << std::endl;
	
	if (sumUneven == 0)
		std::cout << "Нечётных нет" << std::endl;
	else
		std::cout << "Сумма нечётных: " << sumUneven << std::endl;

	std::cout << "Сумма всех чисел: " << sumAll << std::endl;
	
	if (c == temp)
		std::cout << "Число является палиндромом." << std::endl;
	else
		std::cout << "Число не является палиндромом." << std::endl;
}
