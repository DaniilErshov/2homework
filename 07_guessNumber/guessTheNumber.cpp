#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

int _tmain(int argc, _TCHAR* argv[])
{
  bool f=1;
  int k=0;
  int i=1;
  int n=50;
  while (f)
  {
    std::cout << ">" << n << "? (1 - yes, 2 - no, 3 - equal\n";
    std::cin >> k;
    if (k==1)
    {
      if (50/(pow(2,i)) < 1)
      {
        n++;
      } else {
		  n += 50/(pow(2,i));
	  }
    }
    if (k==2)
    {
      if (50/(pow(2,i)) < 1)
      {
        n--;
      } else {
		  n-= 50/((pow(2,i)));
	  }
    }
    if (k==3)
    {
      std::cout << " you are right\n";
      f = 0;
    }
    i++;
  }
return 0;
}
