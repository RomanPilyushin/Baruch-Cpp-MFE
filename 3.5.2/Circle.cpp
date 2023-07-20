// Circle.cpp
//
// Implementation file for Circle.  Circle is comprised of a radius, and a centre point. 
// Includes standard constructor and destructor.
// Includes getter and setter functions for radius and centre point.
// Contains ToString function to output a string description of the circle
// The ToString() override function makes a call to the base class ToString() function.
// Also includes functions to calculate diameter, area, and circumference.




#ifndef _USE_MATH_DEFINES	//This block of code is needed for M_PI constant
#define _USE_MATH_DEFINES
#include <cmath>			//Libary cmath is used to implement circle functions
#endif // _USE_MATH_DEFINES

#include "Point.h"	//Header file that contains definition for object called Point
#include "Line.h"		//Header file that contains definition for object called Line
#include "Circle.h"	//Header file that contains definition for object called Circle

#include <sstream>	//C++ stream buffering
#include <iostream> // C++ style I/O

namespace TestNameSpace
{
	namespace CAD
	{
		//Initialize centerpointe and radius data members
		Circle::Circle() : Shape(), m_centre_point(0.0, 0.0), m_radius(0.0)	 // Default constructor
		{
			//std::cout << "New Circle created:\n";
		}

		Circle::Circle(const double& start_radius, const Point& start_cp) : Shape(), m_radius(start_radius), m_centre_point(start_cp) // Overload constructor that initializes the radius and centrepoint
		{
			//std::cout << "Circle overload constructor: " << *this << "\n";
		}

		Circle::Circle(const Circle& source) : Shape(source), m_radius(source.m_radius), m_centre_point(source.m_centre_point) //Copy constructor
		{
			//std::cout << "Circle copy constructor: " << *this << "\n";
		}

		// Assignment operator
		Circle& Circle::operator = (const Circle& source)
		{
			//check to make sure not assigning to myself
			if (this == &source) return *this;

			//std::cout << "Circle assignment operator before base call: " << *this << "\n";
			// Call base class assignment
			Shape::operator= (source);

			// Copy state
			m_radius = source.m_radius;
			m_centre_point = source.m_centre_point;

			//std::cout << "Circle assignment operator after base call: " << *this << "\n";

			return *this;
		}

		Circle::~Circle()	// Destructor
		{
			//std::cout << "Circle destroyed:\n";
		}

		// Getter member-function for radius
		// Returns data member m_radius
		double Circle::Radius() const
		{
			return m_radius;
		}

		// Setter member-function for radius
		// Modifies object state of data member m_radius
		void Circle::Radius(const double& start_radius)
		{
			m_radius = start_radius;
		}

		// Getter member-function for CentrePoint
		// Returns data member m_centre_point
		Point Circle::CentrePoint() const
		{
			return m_centre_point;
		}

		// Setter member-function for CentrePoint
		// Modifies object state of data member m_centre_point
		void Circle::CentrePoint(const Point& start_cp)
		{
			m_centre_point = start_cp;
		}

		//Calculate diameter of circle
		double Circle::Diameter() const
		{
			return 2 * m_radius;
		}

		//Calculate area of circle
		double Circle::Area() const
		{
			return M_PI * pow(m_radius, 2);
		}

		//Calculate circumference of circle
		double Circle::Circumference() const
		{
			return M_PI * m_radius * 2;
		}

		// Returns string description of the circle
		string Circle::ToString() const
		{
			std::string s = Shape::ToString();

			stringstream ss;
			ss << s << "Circle radius: " << m_radius << ", Centre Pointe: " << m_centre_point;

			return ss.str();
		}

		// Overloaded Ostream << operator
		// os is passed in by reference, as is c of type Circle
		// Returns os by reference!
		ostream& operator << (ostream& os, const Circle& c)
		{
			return os << "Circle radius: " << c.m_radius << ", Centre Pointe: " << c.m_centre_point;
		}
	}
}