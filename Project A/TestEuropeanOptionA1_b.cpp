/*Here I implemented the following function.
  double EuropeanOption::put_call_parity(double assetP, double val, string str) const

  Usage ex : Passing asset value, call option value with string "C". It will return put option value.
  Usage ex : passing asset value, put option value with stirng "P". It will return call option value.
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
	double P1 = Batch1.put_call_parity(S1, C1, "C");
	cout << "For Batch 1" << endl;
	cout << "Put value using put_call_parity function : " << P1 << endl;
	cout << "Call value using put_call_parity function : " << Batch1.put_call_parity(S1, P1, "P") << endl;


	//	Batch 2
	double T2 = 1.0; double K2 = 100;	double sig2 = 0.2;	double r2 = 0.0;	double S2 = 100;	double b2 = r2;
	EuropeanOption Batch2(K2, T2, r2, sig2, b2, "C");
	double C2 = Batch2.Price(S2);
	double P2 = Batch2.put_call_parity(S2, C2, "C");
	cout << "\nFor Batch 2" << endl;
	cout << "Put value using put_call_parity function : " << P2 << endl;
	cout << "Call value using put_call_parity function : " << Batch2.put_call_parity(S2, P2, "P") << endl;


	//	Batch 3
	double T3 = 1.0; double K3 = 10;	double sig3 = 0.50;	double r3 = 0.12;	double S3 = 5;	double b3 = r3;
	EuropeanOption Batch3(K3, T3, r3, sig3, b3, "C");
	double C3 = Batch3.Price(S3);
	double P3 = Batch3.put_call_parity(S3, C3, "C");
	cout << "\nFor Batch 3" << endl;
	cout << "Put value using put_call_parity function : " << P3 << endl;
	cout << "Call value using put_call_parity function : " << Batch3.put_call_parity(S3, P3, "P") << endl;



	//	Batch 4
	double T4 = 30.0; double K4 = 100;	double sig4 = 0.30;	double r4 = 0.08;	double S4 = 100;	double b4 = r4;
	EuropeanOption Batch4(K4, T4, r4, sig4, b4, "C");
	double C4 = Batch4.Price(S4);
	double P4 = Batch4.put_call_parity(S4, C4, "C");
	cout << "\nFor Batch 4" << endl;
	cout << "Put value using put_call_parity function : " << P4 << endl;
	cout << "Call value using put_call_parity function : " << Batch4.put_call_parity(S4, P4, "P") << endl;


	system("Pause");
	return 0;
}







