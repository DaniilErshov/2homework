// ConsoleApplication13.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
void swap1(int&, int&,int,int);
void swap2(int&, int&);
void swap3(int&, int&);
void swap4(int&, int&);

int _tmain(int argc, _TCHAR* argv[])
{
	int a;
	int b;
	a = 1;
    b = 10;
	swap1(a,b,a,b);
	std::cout << "a= " << a << " b= " << b << "\n"; 
	a = 1;
    b = 10;
	swap2(a,b);
	std::cout << "a= " << a << " b= " << b << "\n"; 
	a = 1;
    b = 10;
	swap3(a,b);
	std::cout << "a= " << a << " b= " << b << "\n"; 
	a = 1;
    b = 10;
	swap4(a,b);
	std::cout << "a= " << a << " b= " << b << "\n";
	return 0;
}

void swap1(int &a, int &b, int k, int m)
{
	a = m;
	b = k;
}

void swap2(int &a, int &b)
{
	int t;
	t = a;
    a = b;
	b = t;
}

void swap3(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void swap4(int &a, int &b)
{
	a = a * b;
	b = a / b;
	a = a / b;
}

