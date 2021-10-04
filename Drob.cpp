// ConsoleApplication11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <ctime>

class Drob
{
private:
    int chisl;
    int znam;
 
public:
    Drob() // конструктор по умолчанию 
    {
         chisl = 0;
         znam = 1;
    }
    Drob(int chisl1, int znam1)
	{
		if (znam1 > 0 && chisl1 > 0)
		{
		  chisl = chisl1;
		  znam = znam1;
		} else {
		  chisl = -abs(chisl1);
		  znam = abs(znam1);
		}
		sokrachDrob();
	}

	int sumDrob(int chisl1, int znam1) 
	{ 
		if (znam1 > 0 && znam > 0) 
		{
			chisl = chisl1*znam + chisl*znam1; 
			znam = znam1*znam;
			sokrachDrob();
		} else {
			return 0;
		} 
	}

	int umnDrob(int chisl1, int znam1) 
	{ 
		if (znam1 > 0 && znam > 0) 
		{
			chisl *= chisl1; 
			znam *= znam1;
			sokrachDrob();
		} else {
			return 0;
		} 
	}

	void printDrob()
	{
		if(znam > 0)
		{
		  if (abs(chisl) < znam)
		  {
			std::cout << "drob ravna " << chisl << "/" << znam;
		  }
		  if (abs(chisl) > znam)
		  {
            if ((chisl - (chisl / znam)*znam) == 0)
		    {
			  std::cout << "drob ravna " << chisl/znam;
		    } 
			if (chisl - (chisl / znam)*znam != 0)
		    {
			  std::cout << "drob ravna "  << (chisl/znam) << " " << chisl - (chisl / znam)*znam  << "/" << znam;
		    } 
		  }
		}
		std::cout << "\n";
	}

	void sokrachDrob()
	{
		 if(znam != 0)
         {
              int m = chisl, n = znam, ost = m%n;
              while(ost != 0)
              {
                   m = n; n = ost;
                   ost = m % n;
              }
              int nod = n;
              if(nod != 1)
              {
                   chisl /= nod; znam /= nod;
              }
         }

	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	int flag = 1;
	int chisl;
	int znam;
	std::cout << "vvedite chislitel\n";
	std::cin >> chisl;
	std::cout << "vvedite znaminatel\n";
	std::cin >> znam;
	Drob drob(chisl,znam);
	drob.printDrob();
	std::cout << "summa\n";
	std::cout << "vvedite chislitel\n";
	std::cin >> chisl;
	std::cout << "vvedite znaminatel\n";
	std::cin >> znam;
	drob.sumDrob(chisl,znam);
	drob.printDrob();
	std::cout << "umnozhenie\n";
	std::cout << "vvedite chislitel\n";
	std::cin >> chisl;
	std::cout << "vvedite znaminatel\n";
	std::cin >> znam;
	drob.umnDrob(chisl,znam);
	drob.printDrob();
	return 0;
}

