// In this problem I included greeks.h header here and implemented following four global fucntions there.
//double CallDelta(double S, double K, double T, double r, double sig, double b) 
//double PutDelta(double S, double K, double T, double r, double sig, double b) 
//double CallGamma(double S, double K, double T, double r, double sig, double b) 
// double PutGamma(double S, double K, double T, double r, double sig, double b) 

// Then I created 4 public EuropeanOption member fucntions to access above 4.
/* To call global sensitivities in the greeks.h file
	double Call_CallDelta (double U) const ;
	double Call_PutDelta (double U) const ;
	double Call_CallGamma(double U) const ;
	double Call_PutGamma(double U) const ; */



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
	EuropeanOption ObjA2_a(K, T, r, sig, b, "c");

	cout << "For values K =100, S=105, T=0.5, r=0.1, b=0 and sig=0.36" << endl;
	cout << " \nGamma Call : " << ObjA2_a.Call_CallGamma(S) << endl;
	cout << " \nGamma Put : " << ObjA2_a.Call_PutGamma(S) << endl;
	cout << " \nDelta Call : " << ObjA2_a.Call_CallDelta(S) << endl;
	cout << " \nDelta Put : " << ObjA2_a.Call_PutDelta(S) << endl;




	system("Pause");
	return 0;
}







