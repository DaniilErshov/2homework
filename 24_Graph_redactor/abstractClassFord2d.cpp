// ConsoleApplication38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <ctime>

struct Point
{
   double x;
   double y;
};

class Ob2d
{
public:
	virtual void move(const Point) = 0;
	virtual void rotate(const double) = 0;
	virtual void scale(const double) = 0;
	virtual void show() const = 0;
};

class Circle: public Ob2d
{
private:
	Point centre;
	double radius;
public:
	Circle(Point c, double r): centre(c), radius(r) {}

	virtual void move(const Point vect)
	{
		centre.x += vect.x;
		centre.y += vect.y;
	}
	virtual void scale(const double koeff)
	{
		radius *= koeff;
	}
	virtual void rotate(const double angel) {};

	virtual void show() const 
	{
		std::cout << "centre:" << std::endl 
			<< "X: " << centre.x << std::endl
			<< "Y: " << centre.y << std::endl;
		std::cout << "radius: " << radius << std::endl;

	}
};

class Square: public Ob2d
{
private:
	Point firstPoint;
	Point secondPoint;
public:
	Square(Point first, Point second): firstPoint(first), secondPoint(second) {}

	virtual void move(const Point vect)
	{
		firstPoint.x += vect.x;
		firstPoint.y += vect.y;
		secondPoint.x += vect.x;
		secondPoint.y += vect.y;
	}
	virtual void rotate(const double angle)
	{
		firstPoint.x = firstPoint.x * cos(angle) - firstPoint.y * sin(angle);
		firstPoint.x = firstPoint.x * sin(angle) + firstPoint.y * cos(angle);
	}
	virtual void scale(const double koeff)
	{
		firstPoint.x = (firstPoint.x + secondPoint.x)/2 - (secondPoint.x - firstPoint.x)/2;
		firstPoint.y = (firstPoint.y + secondPoint.y)/2 - (secondPoint.y - firstPoint.y)/2;
		secondPoint.x = (firstPoint.x + secondPoint.x)/2 + (secondPoint.x - firstPoint.x)/2;
		secondPoint.y = (firstPoint.y + secondPoint.y)/2 - (secondPoint.y - firstPoint.y)/2;
	}
	virtual void show() const 
	{
		std::cout << "firstPoint: " << std::endl
			      << "X: " << firstPoint.x << std::endl
				  << "Y: " << firstPoint.y << std::endl;
		std::cout << "secondPoint: " << std::endl
			      << "X: " << secondPoint.x << std::endl
				  << "Y: " << secondPoint.y << std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Point M,P;
	double r = 5;
    M.x = 0;
	M.y = 0;
	P.x = 5;
	P.y = 5;
	Circle circleEx(M, r);
	Square squareEx(M,P);
    Ob2d *rParent[2]; 
	rParent[0] = &circleEx;
	rParent[1] =  &squareEx;
	rParent[0]->show();
	std::cout << "......" << std::endl;
	rParent[1]->show();
	rParent[0]->move(P);
	rParent[1]->move(P);
	std::cout << "......" << std::endl;
	std::cout << "......" << std::endl;
	std::cout << "......" << std::endl;
	rParent[0]->show();
	std::cout << "......" << std::endl;
	rParent[1]->show();
	return 0;
}

