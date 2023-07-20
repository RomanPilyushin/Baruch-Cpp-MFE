// TestCallingBaseClass.cpp
//
// Objective is to test the new shape base class, and whether calling base class functionality really works.
// Now, Circle, Line, Point all inherit from class Shape. 
// Also, changed function ToString() in base class Shape to be virtual.
// All derived class ToString() override functions make a call to the base class ToString() function, which prints the ID: in front of the object description.


#include "Point.h"	//Header file that contains definition for object called Point
using TestNameSpace::CAD::Point;  //Using declaration for using a single class (Point)

#include "Circle.h"	//Header file that contains definition for object called Circle
using TestNameSpace::CAD::Circle;  //Using declaration for using a single class (Circle)

#include "Line.h"		//Header file that contains definition for object called Line
using TestNameSpace::CAD::Line;  //Using declaration for using a single class (Line)

#include "Shape.h"	//Header file that contains definition for object called Shape
using TestNameSpace::CAD::Shape;  //Using declaration for using a single class (Shape)

#include <iostream>  // C++ style I/O

int main()
{
	// Let's create some Point objects 
	Point p_1(100, 101);
	Point p_2(200, 201);

	// Let's create some circle objects 
	Circle c_1(5.0, p_1);

	cout << c_1.ToString() << endl; // Print ID and then Circle
	cout << "Circle ID: " << c_1.ID() << endl; // ID of the Circle.

	Shape s; // Create shape.
	Point p(10, 20); // Create point.
	Line l(Point(1, 2), Point(3, 4)); // Create line.n
	cout << s.ToString() << endl; // Print ID and then shape.
	cout << p.ToString() << endl; // Print ID and then point.
	cout << l.ToString() << endl; // Print ID and then line
	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work?
	cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work?

	Shape* sp; // Create pointer to a shape variable.
	sp = &p;
	cout << sp->ToString() << endl; // Print Shape*; Now it correctly calls the ToString() member function of Point, 
	// as well as the ToSTring() of base class

	cout << sp->ID() << endl;  // Prints the m_ID of the point object
	cout << p.ID() << endl; // Prints the m_ID of the point object also 

	return 0;
}