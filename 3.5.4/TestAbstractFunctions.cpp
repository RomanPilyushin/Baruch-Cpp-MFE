// TestAbstractFunctions.cpp
//
// Objective is to test working with an abstract function, and by its very nature, an abstract class of Shape now that 
// Shape base class declared function Draw() as a pure virtual function.

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
	//Shape s; // Can't do this now that Shape is an abstract class!

	// Let's create some Shape* pointers and assign them to Line, Point, and Circle objects.
	Shape* shapes[5];
	
	shapes[0] = new Point;
	shapes[1] = new Line;
	//shapes[2] = new Point(3.4, 5.6);
	//shapes[3] = new Circle;
	//shapes[4] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));
	
	for (int i = 0; i != 2; i++)
	{
		shapes[i]->Draw();  // Call the Draw() functions implemented in each of the derived classes
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