// In this problem I calculated call delta and put delta according to S = [10,50]; 
// Out put matrix : first column will display call delta and second column will display put delta price.
#include <iostream>
#include <fstream>
#include <vector>
#include "EuropeanOption.h"
#include "Mesher.h"
#include "Global_print.h"

using namespace std;


int main()
{

	vector<double> Svector = mesher(10, 50, 1); // Vector of S values.
	int Svecsize = Svector.size();

	double T = 0.5; double K = 100;	double sig = 0.36;	double r = 0.1;	double S = 105;	double b = 0;
	EuropeanOption ObjA2_b(K, T, r, sig, b, "c");

	vector<vector<double>> resultA2_b(Svecsize, 2);

	for (int i = 0; i < Svecsize; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
				resultA2_b[i][j] = ObjA2_b.Call_CallDelta(Svector[i]);
			else
				resultA2_b[i][j] = ObjA2_b.Call_PutDelta(Svector[i]);
		}
	}

	print(resultA2_b);





	system("Pause");
	return 0;
}







