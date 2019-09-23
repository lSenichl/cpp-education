#include <iostream>
#include<locale.h> 

int main()
{
	setlocale(LC_ALL, "RUS");
	
	int schet = 0, snechet = 0, sall = 0, b = 0, a= 0, c = 0, d = 0;
	std::cin >> a;
	d = a;

	while (d > 0)
	{
		b = d % 10;
		d = d / 10;
		sall = sall + b;
		c = c * 10 + b;

		switch (b % 2)
		{
		case 0:
			schet = schet + b;
			break;
		case 1:
			snechet = snechet + b;
			break;
		}
	}

	if (schet == 0)
		std::cout << "Чётных нет" << std::endl;
	else
		std::cout << "Сумма чётных: " << schet << std::endl;
	
	if (snechet == 0)
		std::cout << "Нечётных нет" << std::endl;
	else
		std::cout << "Сумма нечётных: " << snechet << std::endl;

	std::cout << "Сумма всех чисел: " << sall << std::endl;
	
	if (c = a)
		std::cout << "Число является палиндромом." << std::endl;
	else
		std::cout << "Число не является палиндромом." << std::endl;
}
