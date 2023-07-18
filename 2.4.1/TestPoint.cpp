// TestPoint.cpp
//
// Objective is to test operator overloading
// Includes operator overloads for negating coordinates, scaling, adding, comparing, assigning, and scale + assign



#include "Point.h"	//Header file that contains definition for object called Point
#include "Line.h"	//Header file that contains definition for object called Line
#include "Circle.h"	//Header file that contains definition for object called Circle

#include <iostream>  // C++ style I/O
using namespace std;

int main()
{

	// Create a point
	Point p1(10.0, -20.0);
	Point p2(5.0, 10.0);

	// Let's test negating coordinates
	Point p3 = -p1;
	cout << "Testing negating of " << p1.ToString() << " which is: " << p3.ToString() << endl;

	// Let's test the add operator overloading
	Point p4 = p1 + p2;
	cout << p1.ToString() << " + " << p2.ToString() << " = " << p4.ToString() << endl;

	// Let's test scaling the coordinates
	Point p6 = p1 * 3;
	cout << p1.ToString() << " multiplied by 3 = " << p6.ToString() << endl;

	Point p7(10.0, 11.0);
	Point p8(10.0, 11.0);

	// Let's test self-assignment check
	p7 = p7;
	cout << p7.ToString() << endl;

	// Let's test equality overloading
	cout << "Does " << p7.ToString() << " == " << p8.ToString() << " ?" << endl;
	cout << "Answer is: " << ((p7 == p8) ? "Yes" : "No") << endl;
	// Negate p7 and test again for equality
	p7 = -p8;
	cout << "Does " << p7.ToString() << " == " << p8.ToString() << " ?" << endl;
	cout << "Answer is: " << ((p7 == p8) ? "Yes" : "No") << endl;

	// Let's test assignment operator
	Point p9(101.0, 201.0);
	p8 = p6 = p9;  //Testing = overload operator.  These should be a deep copy
	cout << "Testing overloaded assignment operator for class point: " << p9.ToString() << ", " << p8.ToString() << ", " << p6.ToString();
	cout << "\n";

	// Let's test *= opeator
	Point p10(20.0, 21.0);
	p10 *= 3;
	cout << "p10(20.0, 21.0)  *= 3 equals: " << p10.ToString(); cout << "\n\n";

	//Now let's test the overloaded assignment operator for class line
	Point p11(10.0, 11.0);
	Point p12(12.0, 13.0);
	Point p13(14.0, 15.0);
	Point p14(16.0, 17.0);

	Line l_1(p11, p12);
	Line l_2(p13, p14);

	l_2 = l_1;		//l_2 must make a deep copy of the l_1 members into current object l_1

	// Output the results
	// l_2 and l_1 should both display Point(10, 11) and Point(12, 13)
	cout << "Testing overloaded assignment operator for class line: " << "\n";
	cout << l_1.ToString() << ", " << l_2.ToString();
	cout << "\n\n";

	//Now let's test the overloaded assignment operator for class circle
	Circle c_1(5.0, p11);
	Circle c_2(99.0, p12);

	c_2 = c_1;		//c_2 must make a deep copy of the c_1 members into current object c_1

	// Output the results
	// c_1 and c_2 should show the same values
	cout << "Testing overloaded assignment operator for class circle: " << "\n";
	cout << c_1.ToString() << ", " << c_2.ToString();
	cout << "\n\n";

	return 0;
}