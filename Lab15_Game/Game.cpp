#include "Game.h"
#include <iostream>

Game::Game()
{
	std::cout << "New game." << std::endl;
	for (int i = 0; i < 9; i++)
	{
		field[i] = i + 49;
	}
	player = 1;
}

Game::~Game()
{
}

void Game::again()
{
	std::cout << "New game." << std::endl;
	for (int i = 0; i < 9; i++)
	{
		field[i] = i + 49;
	}
	player = 1;
}

void Game::move()
{
	std::cout << "Player " << player << " please make your move. " << std::endl;

	char tempMove;
	bool rightMove = true;
	
	while (rightMove)
	{
		std::cin >> tempMove;

		switch (tempMove)
		{
		case 'r':
			again();
			rightMove = false;
			break;
		case 'c':
			cancel();
			rightMove = false;
			break;
		default:
			if (checkMove(tempMove))
			{
				if (player == 1)
				{
					field[tempMove - 49] = 'X';
					rightMove = false;

					lastMove = tempMove - 49;

					if (player == 1)
					{
						player = 2;
					}
					else
					{
						player = 1;
					}
				}
				else
				{
					field[tempMove - 49] = 'O';
					rightMove = false;

					lastMove = tempMove - 49;

					if (player == 1)
					{
						player = 2;
					}
					else
					{
						player = 1;
					}
				}
			}
			else
			{
				std::cout << "Wrong move." << std::endl;
			}
			break;
		}
	}
}

void Game::cancel()
{
	field[lastMove] = lastMove + 49;

	if (player == 1)
	{
		player = 2;
	}
	else
	{
		player = 1;
	}
}

bool Game::checkEnd()
{
	int temp = 0;
	for (int i = 0; i < 9; i++)
	{
		if (field[i] != i + 49)
		{
			temp += 1;
		}
	}
	
	if (temp == 9)
	{
		std::cout << "End of game." << std::endl;
		std::cout << "Player" << player << "win." << std::endl;
		return false;
	}
	else
	{
		if (((field[0] == 'X') && (field[1] == 'X') && (field[2] == 'X')) ||
			((field[3] == 'X') && (field[4] == 'X') && (field[5] == 'X')) ||
			((field[6] == 'X') && (field[7] == 'X') && (field[8] == 'X')) ||
			((field[0] == 'X') && (field[4] == 'X') && (field[8] == 'X')) ||
			((field[2] == 'X') && (field[4] == 'X') && (field[6] == 'X')) ||
			((field[0] == 'X') && (field[3] == 'X') && (field[6] == 'X')) ||
			((field[1] == 'X') && (field[4] == 'X') && (field[7] == 'X')) ||
			((field[2] == 'X') && (field[5] == 'X') && (field[8] == 'X')))
		{
			std::cout << "Player 1 win." << std::endl;
			return false;
		}
		else
		{
			if (((field[0] == 'O') && (field[1] == 'O') && (field[2] == 'O')) ||
				((field[3] == 'O') && (field[4] == 'O') && (field[5] == 'O')) ||
				((field[6] == 'O') && (field[7] == 'O') && (field[8] == 'O')) ||
				((field[0] == 'O') && (field[4] == 'O') && (field[8] == 'O')) ||
				((field[2] == 'O') && (field[4] == 'O') && (field[6] == 'O')) ||
				((field[0] == 'O') && (field[3] == 'O') && (field[6] == 'O')) ||
				((field[1] == 'O') && (field[4] == 'O') && (field[7] == 'O')) ||
				((field[2] == 'O') && (field[5] == 'O') && (field[8] == 'O')))
			{
				std::cout << "Player 2 win." << std::endl;
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}

void Game::print()
{
	for (int i = 0; i < 9; i++)
	{
		std::cout << field[i] << " ";
		if ((i == 2) || (i == 5))
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

bool Game::checkMove(bool tempMove)
{
	if (field[tempMove - 49] != tempMove)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::queue()
{
	std::cout << "Queue of " << player << " player.";
}