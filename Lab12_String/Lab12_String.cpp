//#_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <fstream>

int main()
{
	char cstr1[] = "C-string 1";
	char cstr2[] = { 'C','-','s','t','r','i','n','g', '2' };
	char cstr3[256] = { '\67','-','s','t','r','i','n','g', ' ','3' };
	

	int a = 4;
	printf("C-string int =%d, double = %2.2f, char = %c \n", a, 13.4, 't');
	printf(cstr1);

	strcpy_s(cstr3, cstr1);
	printf(cstr3);
	strcat_s(cstr3, cstr1);
	printf(cstr3);

	std::cout << std::endl;
	std::string str1 = "String 1 ";
	std::cout << str1 << std::endl;
	std::string str2 = "String 2 ";
	std::cout << str1 << std::endl;
	std::cout << str1 + str2 << std::endl;
	std::cout << str1.length() << std::endl;

	std::fstream fs;
	fs.open("a.txt", std::fstream::out);
	fs << "dfghjkl";
	fs.close();
}