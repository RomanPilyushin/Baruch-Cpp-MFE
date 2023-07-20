// Array.cpp
//
// Implementation file for class Array, ArrayException, and OutOfBoundsException.


#include "Array.h"	// Header file that contains definition for object called Array
#include "Point.h"	// Header file that contains definition for object called Point

#include <iostream> // C++ style I/O

namespace TestNameSpace
{
	namespace Containers
	{
		// Implementation code for class Array
		// Let the class Array manage memory for the user
		// Contains standard constructor, overload constructor, copy constructor, destructor
		// assignment operator, two [] operators (one that is CONST, the other non-CONST.
		// Also contains accessing functions for both member data pointers, and a setter function for the m_data member point
		// Note: The full class name including namespace for the Point class is used below
		// 2017-05-04: Added exception handling in the GetElement(), SetElement(), and index operator functions if index is too small/big

		Array::Array()	 // Default constructor
		{
			m_size = 10;  // Defaulted to 10 elements
			m_data = new CAD::Point[m_size]; // Instantiate the array of static Point objects

			if (m_data == nullptr)  // Check what new returns to see if its NULL
				std::cout << "Error: memory could not be allocated";
			else
				std::cout << "Default constructor called" << endl;
		}

		// Overload constructor that initializes the array size and allocates number of elements specified by size argument
		Array::Array(const int& size_array)
		{
			m_size = size_array; // Set size based on input argument
			m_data = new CAD::Point[m_size];  // Instantiate the array of static Point objects

			if (m_data == nullptr)   // Check what new returns to see if its NULL
				std::cout << "Error: memory could not be allocated";
			else
				std::cout << "Overloaded constructor called with size of: " << m_size << endl;
		}

		Array::Array(const Array& source)	// Copy constructor
		{
			// Check to make sure not assigning to myself
			if (this != &source)
			{
				m_size = source.m_size; // Get size from the object being copied from
				m_data = new CAD::Point[source.m_size];  // Allocate a new C array with the same size

				if (m_data == nullptr)  // Check what new returns to see if its NULL
					std::cout << "Error: memory could not be allocated";
				else
				{
					for (int i = 0; i < source.m_size; i++)
					{
						m_data[i] = source.m_data[i];  // Copy each element separately
					}
				}
				std::cout << "Copy constructor called with size of: " << m_size << endl;
			}
		}

		// Overloaded Assignment operator
		// Returns array by reference
		Array& Array::operator = (const Array& source)
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;
			else
			{
				delete[] m_data;  // Delete the internal C array before it is copied

				m_size = source.m_size; // Get size from the object being copied from
				m_data = new CAD::Point[source.m_size];  // Allocate new memory before copying the elements

				if (m_data == nullptr)  // Check what new returns to see if its NULL
					std::cout << "Error: memory could not be allocated";
				else
				{
					for (int i = 0; i < source.m_size; i++)
					{
						m_data[i] = source.m_data[i];  // Now copy the elements over
					}
				}
			}
			return *this;  // Return reference, NOT a copy of the object
		}

		// Overloaded [] operator
		// Return reference so the [] operator can be used for both reading and writing elements
		CAD::Point& Array::operator [] (int index)
		{
			if ((index <= m_size - 1) && (index >= 0))  // Check to make sure index number isn't out of bounds
			{
				return m_data[index];  // Returns by reference
			}
			else
			{
				throw OutOfBoundsException(index); // Index is out of bounds, throw an OutOfBoundsException exception
			}
		}

		// Overloaded [] operator
		// Since we have a CONST object, we also want the function to be CONST, such that this function cannot change the object
		// This will tell the compiler it's SAFE to return the Point object as a reference
		// We pass in index element number
		// Returns a reference of the Point object, but as a CONST
		const CAD::Point& Array::operator [] (int index) const
		{
			if ((index <= m_size - 1) && (index >= 0))   // Check to make sure index number isn't out of bounds
			{
				std::cout << "[] bracket operator CONST" << endl;
				return m_data[index];  // Returns by reference
			}
			else
			{
				throw OutOfBoundsException(index); // Index is out of bounds, throw an OutOfBoundsException exception
			}
		}

		Array::~Array()  // Destructor
		{
			delete[] m_data; // Now delete the array itself
			std::cout << "Destructor called" << endl;
		}

		// Accessing member-function for obtaining size of the array	
		// Returns data member m_size
		int Array::Size() const { return m_size; }	// The size of the array

		// Accessing member-function for obtaining element of the Point array
		// We pass in the index element number
		// Get Point element by reference
		CAD::Point& Array::GetElement(int pt_index) const
		{
			if ((pt_index <= m_size - 1) && (pt_index >= 0))
			{
				return m_data[pt_index];  // Returns by reference
			}
			else
			{
				throw OutOfBoundsException(pt_index); // Index is out of bounds, throw an OutOfBoundsException exception
			}
		}

		// Setter function for setting an element within the Point array
		// We pass in the const Point object by reference, and the index element number
		void Array::SetElement(const CAD::Point& pt, int pt_index)
		{
			if ((pt_index <= m_size - 1) && (pt_index >= 0))  // Check to make sure index number isn't out of bounds
			{
				this->m_data[pt_index] = pt;
			}
			else
			{
				throw OutOfBoundsException(pt_index); // Index is out of bounds, throw an OutOfBoundsException exception
			}
		}

		// Implementation code for class ArrayException
		// This class is an abstarct base class that contains a pure virtual function - GetMessage().
		// Also contains standard constructor, copy constructor, destructor, and assignment operator.
		// They don't do anything at this point since there are no data members, but for best practice, I implemented them anyways.

		ArrayException::ArrayException() {} // Constructor.  This class has no specific data members

		ArrayException::ArrayException(const ArrayException& source) {} // Copy constructor

		ArrayException& ArrayException::operator = (const ArrayException& source) { return *this; }  // Assignment operator

		ArrayException::~ArrayException() {}	// Destructor

		// Implementation for code class OutOfBoundsException
		// Derived class of class ArrayException
		// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
		// Implements function GetMessage(), which is an abstract function in the base class. 

		OutOfBoundsException::OutOfBoundsException() : ArrayException() // Default constructor
		{
			m_index = 0; //Default it to zero
		}

		OutOfBoundsException::OutOfBoundsException(int index_num) : ArrayException(), m_index(index_num) {}  // Overload constructor that initializes data member m_index with function argument 

		OutOfBoundsException::OutOfBoundsException(const OutOfBoundsException& source) : ArrayException(source), m_index(source.m_index) {}	// Copy constructor

		OutOfBoundsException& OutOfBoundsException::operator = (const OutOfBoundsException& source) // Assignment operator
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Call base class assignment
			ArrayException::operator= (source);

			// Copy state
			m_index = source.m_index;

			return *this;
		}

		OutOfBoundsException::~OutOfBoundsException() {}  // Destructor

		std::string OutOfBoundsException::GetMessage() const  // Return a message string saying the given index is out of bounds
		{
			return "Given index is out of bounds.";
		}
	}
}