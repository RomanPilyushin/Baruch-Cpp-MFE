// Line.hpp
//
// Header file for Line with two points - start and end. 
// Includes standard constructor, overload constructor, copy constructor, assignment operator overload, and destructor
// Includes getter and setter functions as well as a ToString() function.
// Also includes functions to calculate length



#ifndef Line_HPP
#define Line_HPP

#include "Point.h" //Header file that contains definition for object called Point

#include <iostream> // C++ style I/O
using namespace std;

class Line
{
private:
	//member data for class line that contains a start-point and end-point
	Point m_startpoint;		// The start-point
	Point m_endpoint;		// The end-point

public:
	// Constructors
	Line();													// Default constructor
	Line(const Point& start_point, const Point& end_point);	// Overload constructor that initializes with start- and end-point
	Line(const Line& l);									// Copy constructor
	Line& operator = (const Line& source);					// Assignment operator
	~Line();												//Destructor

	// Accessing functions for start- and end-point
	Point Start() const;									// The start-point
	Point End() const;										// The end-point

	// Setter functions for start- and end-point
	void Start(const Point& start_point);					// The start-point
	void End(const Point& end_point);						// The end-point

	string ToString() const;								//Returns a string description of the point

	double Length() const;									//Calculate distance between two points
};

// Overloaded Ostream << operator
ostream& operator << (ostream& os, const Line& l);			// Send to ostream

#endif // Line_HPP