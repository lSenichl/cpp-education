#include <iostream>

void quadro(int n)
{
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
