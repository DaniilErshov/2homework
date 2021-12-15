#include <iostream>
#include <fstream>  
#include <math.h>
#include <string>
using namespace std;

int main()
{
    double x, y, a, b, h;
    int I;
    string title, zone, variables1, variables2;
	title = "privet";
    I = 200;
	variables1 = "x";
	variables2 = "y";
	zone = "xsinx";
    ofstream outfile("data.dat");
    outfile << "TITLE=\"" << title << "\"" << endl;
    outfile << "VARIABLES=\"" << variables1 << "\", \"" << variables2 << "\"" << endl;
    outfile << "ZONE T=\"" << zone <<"\", I="<<I<<", F=POINT" << endl;
    a = -100;
    b = 100;
    h = (b - a) / I;
    x = a;
    for (int i = 0; i <= I; i++) {
        y = x * sin(x);
        outfile << x << " "<< y << endl;
        x += h;
    }
    outfile.close();
}