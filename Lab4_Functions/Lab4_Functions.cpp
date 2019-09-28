#include <iostream>

void quadro(int n)
{
	/*
	for (int i = 0; i*i < n; i++)
	{
		std::cout << i + 1 << " ^ 2 = " << i * i + 2 * i + 1 << std::endl;
	}
	*/

	int a = 0, i = 0;
	while (a <= n)
	{
		std::cout << i << " ^ 2 = " << a << std::endl;
		a = a + i + i + 1;
		i++;
	}
}

int main()
{
	int n;
	std::cin >> n;
	quadro(n);
}
