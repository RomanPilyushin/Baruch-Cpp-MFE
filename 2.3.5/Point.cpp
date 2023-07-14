// Point.cpp
// Implementation file for Points in two dimensions - x and y.
// Contains the getter and setter functions, as well as a ToString function to output decription of the point created.
// Also includes functions to calculate distinace


#include "Point.h"	//Header file that contains definition for object called Point

#include <sstream>	//C++ stream buffering
#include <cmath>	//Needed to implement distance functions

#include <iostream> // C++ style I/O
using namespace std;

Point::Point() : m_x(0), m_y(0) // Default constructor
{
	cout << "New Point created: " << ToString() << "\n";
}

Point::Point(double x_value, double y_value) : m_x(x_value), m_y(y_value)	// Overload constructor that initialize with x and y value
{
	cout << "Point created in constructor:" << ToString() << "\n";
}

Point::Point(const Point& p)	//Copy constructor
{
	m_x = p.m_x;
	m_y = p.m_y;

	cout << "Point created in copy constructor:" << ToString() << "\n";
}

Point::~Point()	// Destructor
{
	cout << "Point destroyed:" << ToString() << "\n";
}

// Getter member-function for x-coordinate
// Returns data member m_x
double Point::X() const
{
	return m_x;
}

// Setter member-function for x-coordinate
// Modifies object state of data member m_x
void Point::X(double new_X)
{
	m_x = new_X;
}

// Getter member-function for y-coordinate
// Returns data member m_y
double Point::Y() const
{
	return m_y;
}

// Setter member-function for y-coordinate
// Modifies object state of data member m_y
void Point::Y(double new_Y)
{
	m_y = new_Y;
}

// Returns string description of the point
string Point::ToString() const
{
	stringstream ss;
	ss << "Point(" << m_x << ", " << m_y << ")\n";

	return ss.str();
}

//Calculate distance to the origin(0,0)
double Point::Distance() const
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

//Calculate distance between two points
//Point pt passes in x and y coordinates for first point
//Data members m_x and m_y are the second point's x and y coordinates
double Point::Distance(const Point& pt) const
{
	return sqrt(pow((m_x - pt.m_x), 2) + pow((m_y - pt.m_y), 2));
}