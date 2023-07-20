// TestVirtualDestructors.cpp
//
// Objective is to test how virtual destructors are called, and whether objects are properly being removed from memory.



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
	Shape* shapes[3];  // Create some Shape* pointers and assign them to a Shape, Point, and Line objects
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;
	for (int i = 0; i != 3; i++)
	{
		delete shapes[i];  // Now delete each of them
		cout << endl;
	}

	/*
	The proper destructors (including destructor of the Shape base class) will NOT be called
	unless the virtual keyword is declared in the header file of the base class - Shape.

	Upon declaring the base class destructor as virtual, the proper destructors for the derived classes are now called correctly.
	The virtual keyword tells the compiler that the pointer should use the functionality of the derived object that is pointing to the Shape* pointer.
	*/

	return 0;
}