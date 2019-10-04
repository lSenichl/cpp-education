#include <iostream>
#include <locale.h> 

//Ввод массива Задание 1.
void arrcin1(int* mas)
{
	char symbol = 0;

	while (true)
	{
		std::cin.get(symbol);

		if (symbol == 32)
			break;
		
		mas[symbol - 97]++;
	}
}

void arrprint1(int* mas)
{
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < mas[i]; j++)
			std::cout << (char) (i + 97) << std::endl;
}

//Ввод массива Задание 2.
void arrcin2(int* mas, int size)
{
	for (int i = 0; i < size; i++)
		std::cin >> mas[i];

	std::cout << std::endl;
}

//Вывод массива Задание 2.
void arrprint2(int* mas, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << mas[i] << std::endl;
	std::cout << std::endl;
}

//Сумма чисел для Задания 2.
int sum2(int numb)
{
	int temp = 0, sall = 0;
	while (numb > 0)
	{
		temp = numb % 10;
		numb = numb / 10;
		sall += temp;
	}
	return sall;
}

//Сортировка для Задания 2.
void arrsort2(int* mas, int size)
{
	int a;
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (sum2(mas[j]) > sum2(mas[j + 1]))
			{
				a = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = a;
			}
}

//ЗАДАНИЕ 1.
void task1()
{
	int mas[26] = { 0 };

	std::cout << "Введите последовательность букв, каждая с новой строки. (введите пробел для завершения ввода) " << std::endl;
	
	arrcin1(mas);

	std::cout << "Отсортированный массив: " << std::endl;

	arrprint1(mas);
}

//ЗАДАНИЕ 2.
void task2()
{
	int size = 5;
	int mas[5];

	std::cout << "Введите 5 чисел: " << std::endl;
	
	arrcin2(mas, size);

	std::cout << "Отсортированный массив: " <<std::endl;
	
	arrsort2(mas, size);
	arrprint2(mas, size);
}

//Выбор задания.
void choice1()
{
	bool flag = true;
	int tsknumb = 0;

	while (flag)
	{
		std::cout << "Введите номер задания (1, 2): " << std::endl;
		std::cin >> tsknumb;

		switch (tsknumb)
		{
		case 1:
			task1();
			flag = false;
			break;
		case 2:
			task2();
			flag = false;
			break;
		default:
			std::cout << "Введён неверный номер задания. " << std::endl;
			break;
		}
	}
}

//Повторный выбор задания.
void choice2()
{
	bool flag = true;
	char yn = 0;
	std::cout << "Запустить другое задание? (y, n)" << std::endl;

	while (flag)
	{
		std::cin >> yn;

		switch (yn)
		{
		case 'y':
			choice1();
			flag = false;
			break;
		case 'n':
			flag = false;
			break;
		default:
			std::cout << "Введите y или n. " << std::endl;
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	choice1();

	choice2();
}
