#include <iostream>
#include "Game.h"

int main()
{
	Game game1;

	std::cout << "Game's starts." << std::endl;
	std::cout << "First player - X, second player - O." << std::endl;
	std::cout << "To restart game enter - r, to cancel move - c." << std::endl;
	game1.print();
	
	bool end = true;
	char yn;

	while (end)
	{
		game1.queue();
		game1.move();
		game1.print();

		if (game1.checkEnd() == false)
		{
			std::cout << "Do you want to restart the game? y -yes, n - no" << std::endl;
			std::cin >> yn;
			if (yn == 'y')
			{
				game1.again();
				game1.print();
			}
			else
			{
				end = false;
			}
		}
	}
}