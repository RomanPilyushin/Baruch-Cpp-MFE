// Testpoint.cpp
//
// Simple examples of using Point class. NOT all functionality in there yet.


#include "Point.h"
#include "Linesegment.h"

#include <iostream>
using namespace std;

void print(const Point& pt)
{
	cout << "(" << pt.X() << "," << pt.Y() << ")" << endl;

}

int main()
{

	// Create a point
	Point p1;

	double d = p1.X();

	cout << d << endl;

	Point p2(1.0, 2.0);
	cout << "(" << p2.X() << "," << p2.Y() << ")" << endl;

	cout << "(" << p2.X() << "," << p2.Y() << ")" << endl;
	print(p2);

	// Linesegment
//	LineSegment L1(p1, p2);

	return 0;
}