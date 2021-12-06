#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <ctime>
#include "classLIFOFIFO.cpp"




int _tmain(int argc, _TCHAR* argv[])
{
	int a;
	int b;
	LIFO stack;
	FIFO qu;
	std::cout << "papa";
	stack.push(5);
	stack.push(4);
	stack.push(3);

	a = stack.pop();
	std::cout <<  a << "\n";
	a = stack.pop();
	std::cout <<  a << "\n";
	a = stack.pop();
	std::cout <<  a << "\n";
	a = stack.pop();
	a = stack.pop();
	stack.push(15);
	a = stack.pop();
    std::cout <<  a << "\n";
	a = stack.pop(); 

	std::cout << "\nqueue\n";

	qu.push(1);
	qu.push(2);
	qu.push(3);
	
	b = qu.pop();
	std::cout <<  b << "\n";
	b = qu.pop();
	std::cout <<  b << "\n";
	b = qu.pop();
	std::cout <<  b << "\n";
	b = qu.pop();
	b = qu.pop();

	qu.push(15);
	b = qu.pop();
	std::cout <<  b << "\n";
	b = qu.pop();
	b = qu.pop();
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	return 0;
}