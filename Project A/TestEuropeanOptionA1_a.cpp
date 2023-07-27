/* In this problem I implemented four global functions and included those inside
   pricing.h , and Normal_Boost.h header files.
   Those functions are (1) double EuropeanCall(double S, double K, double T, double r, double sig, double b)
					   (2) double EuropeanPut(double S, double K, double T, double r, double sig, double b)
				   (3) double N_BOOST(double x)
				   (4) double n_BOOST(double x)
*/

#include <iostream>
#include "EuropeanOption.h"

using namespace std;


int main()
{
	// Batch 1
	double T1 = 0.25; double K1 = 65;	double sig1 = 0.30;	double r1 = 0.08;	double S1 = 60;	double b1 = r1;
	EuropeanOption Batch1(K1, T1, r1, sig1, b1, "C");
	double C1 = Batch1.Price(S1);
	Batch1.toggle();
	double P1 = Batch1.Price(S1);

	//	Batch 2
	double T2 = 1.0; double K2 = 100;	double sig2 = 0.2;	double r2 = 0.0;	double S2 = 100;	double b2 = r2;
	EuropeanOption Batch2(K2, T2, r2, sig2, b2, "C");
	double C2 = Batch2.Price(S2);
	Batch2.toggle();
	double P2 = Batch2.Price(S2);

	//	Batch 3
	double T3 = 1.0; double K3 = 10;	double sig3 = 0.50;	double r3 = 0.12;	double S3 = 5;	double b3 = r3;
	EuropeanOption Batch3(K3, T3, r3, sig3, b3, "C");
	double C3 = Batch3.Price(S3);
	Batch3.toggle();
	double P3 = Batch3.Price(S3);

	//	Batch 4
	double T4 = 30.0; double K4 = 100;	double sig4 = 0.30;	double r4 = 0.08;	double S4 = 100;	double b4 = r4;
	EuropeanOption Batch4(K4, T4, r4, sig4, b4, "C");
	double C4 = Batch4.Price(S4);
	Batch4.toggle();
	double P4 = Batch4.Price(S4);



	cout << "\nBatch 1 Output: C1 = " << C1 << " and P1 = " << P1 << endl;
	cout << "\nBatch 2 Output: C2 = " << C2 << " and P2 = " << P2 << endl;
	cout << "\nBatch 3 Output: C3 = " << C3 << " and P3 = " << P3 << endl;
	cout << "\nBatch 4 Output: C4 = " << C4 << " and P4 = " << P4 << endl;

	system("Pause");
	return 0;
}







