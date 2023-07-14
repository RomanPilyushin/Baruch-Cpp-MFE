// Point.cpp
//
// Header file for Points in two dimensions. A given Point has 3 coordinates
// for compatibility with other systems. However, it is not possible to
// influence the third coordinate and furthermore, the delivered functionality
// is typically two-dimensional.


#include "Point.h"
#include <cmath>

Point::Point() : x(0), y(0) // Colon syntax!!!!!!!!!!!!!!!!!
{// Default constructor

	x = y = 0.0;
}

Point::Point(double newx, double newy) : x(newx), y(newy)
{// Initialize using newx and newy

	x = newx;
	y = newy;
}

Point::~Point()
{

	cout << "bye my point..\n";
}

double Point::X() const
{
	return x;
}

void Point::X(double newX)
{
	x = newX;
}


double Point::Y() const
{
	return y;
}

void Point::Y(double newY)
{
	y = newY;
}