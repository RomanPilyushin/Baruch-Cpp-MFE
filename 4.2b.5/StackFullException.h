// StackFullException.hpp
//
// Header file for class StackFullException
// Derived class of class StackException
// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
// Implements function GetMessage(), which is an abstract function in the base class.



#ifndef StackFullException_HPP
#define StackFullException_HPP

#include "StackException.h"  // Header file that contains definition for object called StackException

#include <iostream> // C++ style I/O
using namespace std;

namespace TestNameSpace
{
	namespace Containers
	{
		class StackFullException : public StackException
		{
		private:
			// Member data for class StackFullException...

		public:
			// Constructors
			StackFullException();  // Default constructor
			StackFullException(const StackFullException& source);	// Copy constructor
			virtual ~StackFullException();	// Destructor
			StackFullException& operator = (const StackFullException& source);	// Assignment operator

			virtual std::string GetMessage() const;  // Return a message string 
		};
	}
}
#endif // StackFullException_HPP