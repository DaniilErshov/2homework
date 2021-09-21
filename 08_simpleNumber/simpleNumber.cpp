// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <cctype>
#include <cstdlib> 

int _tmain(int argc, _TCHAR* argv[])
{
	int i=0;
	bool fDigit=0;
	bool fSimple=0;
	int n=0;
	int k=1;
	std::string str="";
	std::cout << "vvedi chislo\n";
	std::cin >> str;
	while (i < str.length() && fDigit==0)
	{
		if (!isdigit(str[i]))
        {
			fDigit=1;
		}
		i++;
	}
	if (fDigit)
	{
		std::cout << "neverno vvedeno chislo\n";
	} else {
		n = stoi(str);
		while (k*k <= n && fSimple != 1)
		{
			if (n % k == 0 && k != n && k != 1)
			{
				fSimple = 1;
			}
			k++;
		}
	}
	if (fSimple)
	{
		std::cout << "ne prostoe";
	} else {
		std:: cout << "prostoe";
	}
	return 0;
}

"# SimpleNumbers" 
"# SimpleNumbers" 
"# SimpleNumbers" 
"# SimpleNumbers" 
"# SimpleNumbers" 
"# SimpleNumbers" 
"# SimpleNumbers" 
