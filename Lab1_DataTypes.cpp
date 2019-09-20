#include <iostream>
#include<locale.h> 

int main()
{
	/*Установка русского языка.*/
	setlocale(LC_ALL, "RUS");

	/*Вывод информации.*/
	std::cout << "ФИО: Барышников Семён Сергеевич" << std::endl;
	std::cout << "Дата рождения: 04.11.2000" << std::endl;
	std::cout << "Город рождения: Златоуст" << std::endl;
	std::cout << "Хобби: Радиоэлектроника" << std::endl;
	std::cout << std::endl;

	/*Решение уравнения.*/
	std::cout << "Для решения уравнения вида ax+b=0 введите аргументы a и b: " << std::endl;
	double a, b, x;
	std::cin >> a >> b;
	std::cout << a << "x + " << b << " =0" << std::endl;
	b = b * -1;
	std::cout << a << "x = " << b << std::endl;
	std::cout << "x = " << b << " / " << a << std::endl;
	x = b / a;
	std::cout << "Ответ: " << x << "." << std::endl;

	system("pause");
	return 0;
}
