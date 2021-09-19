#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

void fib(int n, int k, int max);
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
			if (str[i] == '.')
			{
				std::cout << " ne celoe chislo\n";
				if (i > 0)
				{
					if (str[0] == '0')
					{
						std::cout << " < 1\n";
					}
				}
			}

			if (isalpha(str[i]))
			{
				std::cout << "bukva founded\n";
			}

			if ((!isalpha(str[i])) && (str[i] != '.'))
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
				if (n > 100)	
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
	fib(0,1,n);
	return 0;
}

void fib (int n, int k, int max) {  // функция
	int t;
	if (k + n <= max)
	{
		std::cout << n << " ";
		t = k;
	    k += n;
		n = t;
		fib(n,k,max);
	} else {
		std::cout << n << " " << k << "\n";
		return;
	} 
}