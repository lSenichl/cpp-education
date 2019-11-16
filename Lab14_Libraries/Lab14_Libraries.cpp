#include <iostream>
#include <Windows.h>

extern int fnc1(double pq1, char p2);
//extern "C" __declspec(dllimport) int fnc2(double p1, char p2);
//typedef int (CALLBACK* FUNC2)(double, char);

//extern - прототип функции
//extern "C" __declspec(dllimport) - поиск ф в таблице адресов
//typedef int(CALLBACK* FUNC2)... - прототип или объявление 
//__stdcall (CALLBACK) - прямой порядок
//__cdecl - обратный порядок

int main()
{
	std::cout << fnc1(10, 5) << std::endl;
	/*std::cout << fnc2(10, 5) << std::endl;

	HINSTANCE hDLL;
	hDLL = LoadLibrary(L"Lab8 Dll.dll");
	std::cout << hDLL << std::endl;

	FUNC2 fnc2explicit = (FUNC2)GetProcAddress(hDLL, "fnc2");
	std::cout << fnc2explicit << std::endl;

	std::cout << fnc2explicit(10.0, 5) << std::endl;
*/
}