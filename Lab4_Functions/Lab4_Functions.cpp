#include <iostream>

void quadro(int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << " ^ 2 = " << i * i + 2 * i + 1 << std::endl;
	}
}

int main()
{
	int n;
	std::cin >> n;
	quadro(n);
}
