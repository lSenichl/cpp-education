/*Задача №2936. А. Гипотенуза */
#include <iostream> 
#include <cmath>

int main()
{
	
	double a, b, c;

	std::cin >> a;
	std::cin >> b;

	a = pow(a, 2);
	b = pow(b, 2);
	
	c = a + b;

	c = sqrt(c);

	std::cout << c;
}
