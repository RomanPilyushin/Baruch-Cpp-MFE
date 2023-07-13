// TestFibonacci.cpp
// 
// Showing the use of recursive functions by implementing 
// Fibonacci sequences.
//
// DJD
//


#include <algorithm>
#include <iostream>
using namespace std;


// Recursive function
long Fibonacci(long n)
{ 
	if (n == 0) return 0;
	if (n == 1) return 1;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765 . . .
int main()
{ 
	int N = 10; // How many Fibonacci numbers to compute

	for (int n = 0; n < N; ++n)
	{
		cout << Fibonacci(n) << ", ";
	}
	
	cout << endl;
	return 0;

	// N = 30000??
}