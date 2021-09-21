// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

void fak(int n, int k);
int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0;
	int n = 0;
	std::string str;
	std::cout << "vvedite chislo\n";
	std::cin >> str;
	while (i < str.length())
	{
		if (!isdigit(str[i]))
        {
			if (str[0] == '-')
            {
			std::cout << "otric chislo\n";
		    }

			if (str[i] == '.')
			{
				std::cout << " ne celoe chislo\n";
			}

			if (isalpha(str[i]))
			{
				std::cout << "bukva founded\n";
			}

			if ((!isalpha(str[i])) && (str[i] != '.') && (str[0] != '-'))
			{
				std::cout << "other problem\n";
			}
			str = "";
			std::cout << "vvedite chislo\n";
	        std::cin >> str;
			i = 0;
         } else {
			i++;
			if (i == str.length())
			{
				n = stoi(str);
				if (n > 19)	
	            {
                  std::cout << "mnogo\n";
	              std::cout << "vvedite chislo\n";
	              std::cin >> str;
                  n = 0;
	              i = 0;
	            }
			}
		}
	}
	fak(n,1);
	return 0;
}

void fak (int n, int k) {  // ôóíêöèÿ
	if (n == 0)
	{
		std::cout << "fak = " << k << "\n";
		return;
	}
	if (n == 1)
	{
		std::cout <<"fak = " << k << "\n";
		return;
	} else {
		k *= n;
		fak(n-1,k);
	}
}"# 2homework" 
"# 2homework" 
