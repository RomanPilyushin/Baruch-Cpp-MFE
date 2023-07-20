// Circle.hpp
//
// Header file for Circle.  Circle is comprised of a radius, and a centre point. 
// Includes standard constructor, overload constructor, copy constructor, assignment operator overload, and destructor
// Includes getter and setter functions for radius and centre point.
// Also includes functions to calculate diameter, area, and circumference, and ToString() output.



#ifndef Circle_HPP
#define Circle_HPP

#include "Shape.h" //Header file that contains definition for object called Shape
#include "Point.h" //Header file that contains definition for object called Point
#include "Line.h" //Header file that contains definition for object called Line

#include <iostream> // C++ style I/O
using namespace std;

namespace TestNameSpace
{
	namespace CAD
	{
		class Circle : public Shape
		{
		private:
			//member data for class circle that contains the Radius and CentrePoint
			double m_radius;			// The radius
			Point m_centre_point;		// The centrepoint

		public:
			// Constructors
			Circle();														// Default constructor
			Circle(const double& start_radius, const Point& start_cp);		// Overload constructor that initializes the radius and centrepoint
			Circle(const Circle& source);									// Copy constructor
			Circle& operator = (const Circle& source);						// Assignment operator
			~Circle();														// Destructor

			// Accessing functions for radius and centrepoint				
			double Radius() const;									// The radius
			Point CentrePoint() const;								// The centrepoint

			// Setter functions for radius and centrepoint	
			void Radius(const double& start_radius);				// The radius
			void CentrePoint(const Point& start_cp);				// The centrepoint

			double Diameter() const;								//Calculates the diameter of the circle
			double Area() const;									//Calculates the area of the circle
			double Circumference() const;							//Calculates the circumference of the circle

			string ToString() const;								//Returns a string description of the circle

			// Overloaded Ostream << operator
			friend ostream& operator << (ostream& os, const Circle& c);		// Send to ostream
		};
	}
}
#endif // Circle_HPP