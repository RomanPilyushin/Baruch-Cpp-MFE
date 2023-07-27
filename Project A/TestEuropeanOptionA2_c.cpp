// Calculating call delta and call gamma values using numerical differentiation methods.
#include <iostream>
#include <fstream>
#include <vector>
#include "EuropeanOption.h"
#include "Mesher.h"
#include "Global_print.h"

using namespace std;


int main()
{
	double T = 0.5; double K = 100;	double sig = 0.36;	double r = 0.1;	double S = 105;	double b = 0;
	EuropeanOption ObjA2_c(K, T, r, sig, b, "c");

	cout << "For values K =100, S=105, T=0.5, r=0.1, b=0 and sig=0.36" << endl;


	cout << "\n" << endl;
	// Using divided diferences method.

	// Create a h vector.
	vector<double> h_vector = mesher(0.1, 1, 0.1); //h = [0.1,1]; step size - 0.1
	vector<double> calldelta_numerical(h_vector.size());
	vector<double> callgamma_numerical(h_vector.size());


	for (int i = 0; i < h_vector.size(); ++i)

	{
		calldelta_numerical[i] = (ObjA2_c.CallPrice(S + h_vector[i]) - ObjA2_c.CallPrice(S - h_vector[i])) / (2 * h_vector[i]);
		callgamma_numerical[i] = (ObjA2_c.CallPrice(S + h_vector[i]) - (2 * ObjA2_c.CallPrice(S))
			+ ObjA2_c.CallPrice(S - h_vector[i])) / (h_vector[i] * h_vector[i]);
		//cout << calldelta_numerical[i] << endl;
	}

	cout << " \nDelta Call using sensitivity equation : " << ObjA2_c.Call_CallDelta(S) << endl;
	cout << "Calldelta_numerical values for h = 0.1 to 1.0" << endl;
	for (int i = 0; i < h_vector.size(); ++i)
	{
		cout << calldelta_numerical[i] << endl;
	}
	cout << "Output shows that the smaller values of h gives better approximations" << endl;

	cout << " \nGamma Call using sensitivity equation :  " << ObjA2_c.Call_CallGamma(S) << endl;
	cout << "Callgamma_numerical values for h = 0.1 to 1.0" << endl;
	for (int i = 0; i < h_vector.size(); ++i)
	{
		cout << callgamma_numerical[i] << endl;
	}
	cout << "Output shows that smaller values of h gives better approximations" << endl;



	//cout << " \nGamma Put : "<< ObjA2_a.Call_PutGamma(S)<<endl;

	//cout << " \nDelta Put : "<< ObjA2_a.Call_PutDelta(S)<<endl;






	/*vector<double> Svector = mesher(10,50,1); // Vector of S values.
	int Svecsize = Svector.size();

	double T = 0.5; double K = 100;	double sig = 0.36;	double r = 0.1;	double S = 105;	double b = 0;
	EuropeanOption ObjA2_b(K, T, r, sig, b, "c");

	vector<vector<double>> resultA2_b(Svecsize, 2);

		for (int i = 0; i < Svecsize; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				if(j ==0)
			  resultA2_b[i][j] =	ObjA2_b.Call_CallDelta(Svector[i]);
				else
			  resultA2_b[i][j] =	ObjA2_b.CallPrice(Svector[i]);
			}
		}

	 print( resultA2_b) ;
	 */




	system("Pause");
	return 0;
}







