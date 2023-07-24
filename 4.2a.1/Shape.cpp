// Shape.cpp
//
// Implementation file for abstract class Shape.  Shape is comprised of an ID.
// Includes standard constructor, copy constructor, assignment operator overload, and destructor
// Includes getter function for retrieving the id of the shape.
// Also includes virtual function ToString() that returns the id of the Shape as a string
// Note that Draw() is not defined in this class because it is a pure virtual function, and is therefore an abstract function.
// Includes Print() function that prints shape information to the cout object



#include "Shape.h"	// Header file that contains definition for object called Shape

#include <sstream>	// C++ stream buffering
#include <iostream> // C++ style I/O

#include "stdlib.h" // Header file that contains rand(), which generates random numbers

namespace TestNameSpace
{
	namespace CAD
	{
		Shape::Shape()  // Default constructor
		{
			m_id = rand();  //Generate random number and assign to member m_id

			//std::cout << "New Shape created: " << m_id << endl;
		}

		Shape::Shape(const Shape& source) : m_id(source.m_id)	// Copy constructor
		{
			//std::cout << "Shape copy constructor: " << m_id << endl;
		}

		// Assignment operator
		Shape& Shape::operator = (const Shape& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Copy state
			m_id = source.m_id;

			//std::cout << "Shape assignment operator: " << m_id << endl;

			return *this;
		}

		Shape::~Shape()	// Destructor
		{
			//std::cout << "Shape destroyed." << endl;
		}

		// Getter member-function for m_id, which is the ID of the shape
		// Returns data member m_id
		int Shape::ID() const
		{
			return m_id;
		}

		// Returns string description of the shape
		string Shape::ToString() const
		{
			stringstream ss;
			ss << "ID: " << m_id << ", ";

			return ss.str();
		}

		void Shape::Print() const	// Prints shape information to the cout object
		{
			std::cout << ToString();
		}
	}
}