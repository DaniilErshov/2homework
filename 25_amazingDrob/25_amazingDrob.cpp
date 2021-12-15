// ConsoleApplication41.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <ctime>
#include <exception>

bool isNumber(std::string s){
    for (int a = 0; a < s.length(); a++){
        if (s[a] != 45){
            if ((s[a] < 48) || (s[a] > 57))  return false;
        }   
    }
    return true;
}

int sign(int k){
	if (k > 0) return 1;
	if (k < 0) return -1;
	if (k == 0) return 0;
}

class Drob
{
private:
    int chisl;
    int znam;
 
public:
    Drob() 
    {
         chisl = 0;
         znam = 1;
    }
    Drob(int chisl1, int znam1)
	{
		try{
		  if (znam1 == 0) throw std::invalid_argument("the argument must be != 0");
		  if (sign(znam1) * sign(chisl1) > 0)
		  {
		    chisl = abs(chisl1);
		    znam = abs(znam1);
		  } else {
		    chisl = -abs(chisl1);
		    znam = abs(znam1);
		  }
		  sokrachDrob();
		}
        catch (std::invalid_argument const & e)
        {
          std::cout << "Error: " << e.what() << "\n";
		  std::cout << "chisl = 1, znam = 1\n";
		  chisl = 1;
		  znam =1;
        }
	}

	void sumDrob(Drob const & tmpDrob) 
	{ 
		try{
			if ((double) INT_MAX / znam < tmpDrob.chisl || (double) INT_MAX / tmpDrob.znam < chisl)  throw std::range_error("WOOOW soo big");
			chisl = tmpDrob.chisl*znam + chisl*tmpDrob.znam; 
			znam = tmpDrob.znam*znam;
			sokrachDrob();
		}
		catch (std::range_error const & e)
        {
          std::cout << "Error: " << e.what() << "\n";
        }
	}

	void umnDrob(Drob const & tmpDrob) 
	{ 
		try
		{
			if ((double) INT_MAX / chisl < tmpDrob.chisl || (double) INT_MAX / tmpDrob.znam < znam)  throw std::range_error("WOOOW soo big");
			chisl *= tmpDrob.chisl; 
			znam *= tmpDrob.znam;
			sokrachDrob();
		}
		catch (std::range_error const & e)
        {
          std::cout << "Error: " << e.what() << "\n";
        }

	}

	void printDrob()
	{
		if (chisl == 0) std::cout << "drob ravna 0";
		  if (abs(chisl) < znam)
		  {
			std::cout << "drob ravna " << chisl << "/" << znam;
		  }
		  if (abs(chisl) >= znam)
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
		std::cout << "\n";
	}

	void sokrachDrob()
	{
		 if(znam != 0 && chisl != 0)
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
	std::string chisl;
	std::string znam;
	int chislInt;
	int znamInt;
	try
	{
	  std::cout << "vvedite chislitel\n";
	  std::cin >> chisl;
	  if ((chisl.length() == 10 && chisl >= "2147483647") || chisl.length() > 10) throw std::length_error("WOOOW soo big");
	  std::cout << "vvedite znaminatel\n";
	  std::cin >> znam;
	  if ((znam.length() == 10 && znam >= "2147483647") || znam.length() > 10) throw std::length_error("WOOOW soo big");
	  if (!isNumber(chisl) || !isNumber(znam)) throw std::runtime_error("not digit");
	  chislInt = stoi(chisl);
	  znamInt = stoi(znam);
	}
    catch (std::runtime_error const & e)
    {
          std::cout << "Error: " << e.what() << "\n";
		  std::cout << "chisl = 1, znam = 1\n";
		  chislInt = 1;
		  znamInt =1;
    }
    catch (std::length_error const & e)
    {
          std::cout << "Error: " << e.what() << "\n";
		  std::cout << "chisl = 1, znam = 1\n";
		  chislInt = 1;
		  znamInt =1;
    }

	Drob drob(chislInt,znamInt);
	drob.printDrob();
	std::cout << "summa\n";
	try
	{
	  std::cout << "vvedite chislitel\n";
	  std::cin >> chisl;
	  std::cout << chisl.length();
	  if ((chisl.length() >= 10)) throw std::length_error("WOOOW soo big");
	  std::cout << "vvedite znaminatel\n";
	  std::cin >> znam;
	  if ((znam.length() >= 10)) throw std::length_error("WOOOW soo big");
	  if (!isNumber(chisl) || !isNumber(znam)) throw std::runtime_error("not digit");
	  chislInt = stoi(chisl);
	  znamInt = stoi(znam);
	}
    catch (std::runtime_error const & e)
    {
          std::cout << "Error: " << e.what() << "\n";
		  std::cout << "chisl = 1, znam = 1\n";
		  chislInt = 1;
		  znamInt =1;
    }
	Drob drob2(chislInt,znamInt);
	drob.sumDrob(drob2);
	drob.printDrob();
	std::cout << "umnozhenie\n";
	try
	{
	  std::cout << "vvedite chislitel\n";
	  std::cin >> chisl;
	  std::cout << "vvedite znaminatel\n";
	  std::cin >> znam;
	  if (!isNumber(chisl) || !isNumber(znam)) throw std::runtime_error("not digit");
	  chislInt = stoi(chisl);
	  znamInt = stoi(znam);
	}
    catch (std::runtime_error const & e)
    {
          std::cout << "Error: " << e.what() << "\n";
		  std::cout << "chisl = 1, znam = 1\n";
		  chislInt = 1;
		  znamInt =1;
    }
	Drob drob3(chislInt,znamInt);
	drob.umnDrob(drob3);
	drob.printDrob();
	return 0;
}