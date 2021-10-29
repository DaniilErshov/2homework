#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

struct Koord
{
   double x;
   double y;
};

class Rectangle
{
    private:
        Koord M;
        Koord P;
    public:
        Rectangle(Koord mTmp, Koord pTmp)
        {
           M.x = std::min(mTmp.x, pTmp.x);
           P.x = std::max(mTmp.x, pTmp.x);
           M.y = std::min(mTmp.y, pTmp.y);
           P.y = std::max(mTmp.y, pTmp.y);
        }
        
        void checkRectangle(Rectangle &recTmp)
		{
        int flag = 0;
            if (M.x < recTmp.M.x && recTmp.M.x < P.x)
            {
                if (M.y < recTmp.M.y && recTmp.M.y < P.y)
                {
                  flag = 1;
				}
            }  
            if (M.x < recTmp.P.x && recTmp.P.x < P.x)
            { 
                if (M.y < recTmp.P.y && recTmp.P.y <  P.y)
                {
                  flag = 1;
                }
            } 
            
            if (M.x >  recTmp.M.x && recTmp.M.y < M.y)
            { 
                if (P.x < recTmp.P.x && recTmp.P.y >  P.y)
                {
                  flag = 1;;
                }
            } 
            recTmp.M.x = 100;
			recTmp.M.y = 100;
			recTmp.P.x = 110;
			recTmp.P.y = 110; // change the values of the object that I passed by reference
			if (flag > 0)
			{
                std::cout << "yes\n";
            } else {
                std::cout << "no\n";
            }
        }
		void printRectangle()
		{
			std::cout << M.x << " " << M.y << "\n";
			std::cout << P.x << " " << P.y << "\n";
		}
};



int _tmain(int argc, _TCHAR* argv[])
{
    Koord M,P,mTmp,pTmp;
    M.x = 0;
	M.y = 0;
	P.x = 5;
	P.y = 5;
	mTmp.x = -10;
	mTmp.y = -10;
	pTmp.x = 1;
	pTmp.y = 1;
    Rectangle rec1(M,P);
    Rectangle rec2(mTmp,pTmp);
    rec1.checkRectangle(rec2);
	rec1.printRectangle();
	rec2.printRectangle(); // i see changed values of rec2S
    return 0;
}
© 2021 GitHub, Inc.
