// PointArray.hpp
//
// Header file for class PointArray.
// Inherits (concrete inheritance) from base class Array, of which the template argument is fixed to Point.
// Header file contains standard constructor, overload constructor, copy constructor, destructor
// assignment operator, and a function, GetLength, that returns total length between two points in an arrayy.


#ifndef PointArray_HPP
#define PointArray_HPP

#include "Array.h"	// Header file that contains definition for object called Array

#include "Point.h"	// Header file that contains definition for object called Point
using TestNameSpace::CAD::Point;  //Using declaration for using a single class (Point)

#include <iostream> // C++ style I/O
using namespace std;

namespace TestNameSpace
{
	namespace Containers
	{
		class PointArray : public Array<Point>  //Template argument for Array is fixed to type Point (concrete inheritance)
		{
		private:
			// No member data for class PointArray

		public:
			// Constructors
			PointArray();  // Default constructor
			PointArray(const int& size_array);  // Overload constructor that initializes the array size and allocates number of elements specified by size argument
			PointArray(const PointArray& source);  // Copy constructor
			PointArray& operator = (const PointArray& source);  // Assignment operator
			virtual ~PointArray();  // Destructor

			double Length() const;  // Get total length between the points in the array
		};
	}
}
#endif // PointArray_HPP