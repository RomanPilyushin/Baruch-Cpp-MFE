// TestTemplateMethodPattern.cpp
//
// Objective is to test the inner workings of the template method pattern.
// Print() has been added to the base class Shape.  This function is inherited in all derived classes, which in turn,
// will polymorphically (if that's even a word) call their own respective ToString() function.



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
	// Let's create some Shape* pointers and assign them to Line, Point, and Circle objects.
	Shape* shapes[4];
	shapes[0] = new Point;
	shapes[1] = new Line;

	//shapes[2] = new Circle;
	//shapes[3] = new Point(3.4, 5.6);
	//shapes[4] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));


	for (int i = 0; i != 2; i++)
	{
		shapes[i]->Print();  // Call the Print() function implemented in base class Shape
		cout << endl;
	}

	cout << endl;
	cout << endl;

	for (int i = 0; i != 2; i++)
	{
		delete shapes[i];  // Now delete all of the objects
		cout << endl;
	}

	return 0;
}