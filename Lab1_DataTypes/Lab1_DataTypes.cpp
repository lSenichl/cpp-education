#include <iostream>
#include<locale.h> 

int main()
{
	setlocale(LC_ALL, "RUS");

	std::cout << "ФИО: Барышников Семён Сергеевич" << std::endl;
	std::cout << "Дата рождения: 04.11.2000" << std::endl;
	std::cout << "Город рождения: Златоуст" << std::endl;
	std::cout << "Хобби: Радиоэлектроника" << std::endl;
	std::cout << std::endl;

	std::cout << "Для решения уравнения вида ax + b = 0 введите аргументы a и b: " << std::endl;
	double a = 0, b = 0, x = 0;
	std::cin >> a >> b;
	std::cout << a << "x + " << b << " =0" << std::endl;
	b = b * -1;
	std::cout << a << "x = " << b << std::endl;
	std::cout << "x = " << b << " / " << a << std::endl;
	x = b / a;
	std::cout << "Ответ: " << x << "." << std::endl;

}
