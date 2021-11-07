// ConsoleApplication22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <ctime>

struct Nabor
{
	int *a;
	int length;
};
struct Check
{
	bool ch;
	int value;
	int znak;
};

class Massiv
{
    private:
	  int n;
	  Nabor nab;
	  Check start;
	  Check stop;
	  Check step;

	  void strCheck(std::string str)
      {
	       int i = 0;
	       std::string tmpString ="";

		   if (str[i] == '{')
		   {
		    	i++;
		    	if(str[i] == '-')
		    	{
			    	start.znak = -1;
				    i++;
			    } 
			    while (isdigit(str[i]))
		    	{
			    	tmpString += str[i];
				    i++;
				    if (str[i] == ':' || str[i] == '}')
				    {
					  start.value = stoi(tmpString);
				    }
				    start.ch = true;
			    }
			    tmpString = "";
		    }


		    if (str[i] == ':')
		    {
			  i++;
			  if(str[i] == '-')
			  {
			     stop.znak = -1;
			  	 i++;
			  }
			  while (isdigit(str[i]))
			  {
			    	tmpString += str[i];
				    i++;
				    if (str[i] == ':' || str[i] == '}')
				    {
					  stop.value = stoi(tmpString);
				    }
				    stop.ch = true;
		      }
			  tmpString = "";
		  }
		
		  if (str[i] == ':' && str[i] != '}')
		  {
			  i++;
			  if(str[i] == '-')
			  {
				 step.znak = -1;
				 i++;
			  } 
			  while (isdigit(str[i]))
			  {
			    	tmpString += str[i];
			    	i++;
			    	if (str[i] == '}')
			    	{
			     		step.value = stoi(tmpString);
			     	}
				    step.ch = true;
			  }
			  tmpString = "";
		   }
	  }

    public:

		Massiv()
		{
			int i;
		    start.ch = false; stop.ch = false; step.ch = false;
	        start.znak = 1; stop.znak = 1; step.znak = 1;
			std::cout << "vvedite kolvo\n";
			std::cin >> n;
			nab.a = new int[n];
			for(i=0; i<n; i++)
			{
				std::cout << "vvedite " << i << " element\n";
				std::cin >> nab.a[i];
			} 
			for(i=0; i<n; i++)
			{
				std::cout << nab.a[i] << " ";
			} 
			std::cout << "\n";
		}


	int* slice(std::string str, int &ptrLength)
	{
		int i;
		int j = 0;
		strCheck(str);
		int *arrayTmp;
		int k;

		if (step.ch == false) step.value = 1;
	    if (stop.ch == false) stop.value = n;
	    if (start.ch == false) start.value = 0;

	    if (stop.znak == -1) stop.value = n - stop.value;
	    if (start.znak == -1) start.value = n - start.value;

	    k = (stop.value - start.value + 1)/step.value;
		ptrLength = k - 1;
		arrayTmp = new int[k];

		if (step.znak == 1)
		{
		  for (i = start.value; i < stop.value; i += step.value, j++)
	      {
		      arrayTmp[j] = nab.a[i];
		   }
		} else {
			for (i = stop.value - 1; i >= start.value; i -= step.value, j++)
	      {
		      arrayTmp[j] = nab.a[i];
		   }
		}

		start.ch = false; stop.ch = false; step.ch = false;
	    start.znak = 1; stop.znak = 1; step.znak = 1;
		return arrayTmp;
	}
};






int _tmain(int argc, _TCHAR* argv[])
{
	Massiv ms;
	int i;
	Nabor nab;
	nab.a = ms.slice("{::-1}", nab.length);

	for(i=0; i< nab.length; i++)
	{
		std::cout << nab.a[i] << " ";
	}
	std::cout << "\n";
	return 0;
}
