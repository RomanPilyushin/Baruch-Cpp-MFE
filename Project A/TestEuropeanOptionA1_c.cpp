//Here I newly implemented the following functions .

/*
1. First I created Optiondata struct as a public member of EuropeanOption class.
		   struct OptionData {
			double K_s;
			double T_s;
			double r_s;
			double sig_s;
							 };
2. Then I created a new orverloaded constructor for the class EuropeanOption(passing four variables) to create a new instance of
   struct Optiondata .

	EuropeanOption::EuropeanOption(double K_c, double T_c, double r_c, double sig_c)
{
	Optionstruct = new OptionData;
	Optionstruct->K_s = K_c;
	Optionstruct->T_s = T_c;
	Optionstruct->r_s = r_c;
	Optionstruct->sig_s = sig_c;


}
 3. Then I created two overloaded global functions for EuropeanCall and EuropeanPut functions inside pricing.h
 (Here I pass the asset value and the struct.)

		 double EuropeanCall(double S, EuropeanOption::OptionData* OD)
		 double EuropeanPut(double S,  EuropeanOption::OptionData* OD)


 4. Finally I created two member functions for EuropeanOption class to call above mentioned(mentioned in 3) functions.

		double EuropeanOption::CallPrice_struct(double S) const;
		double EuropeanOption::PutPrice_struct(double S ) const;

*/

#include <iostream>
#include "EuropeanOption.h"

using namespace std;


int main()
{
	// Batch 1
	double T1 = 0.25; double K1 = 65;	double sig1 = 0.30;	double r1 = 0.08;	double S1 = 60;	double b1 = r1;


	EuropeanOption Batch1(K1, T1, r1, sig1);
	double C1 = Batch1.CallPrice_struct(S1);
	double P1 = Batch1.PutPrice_struct(S1);

	cout << "Batch1 out put using structs " << endl;
	cout << " Call Price : " << C1 << endl;
	cout << " Put Price :  " << P1 << endl;

	//	Batch 2
	double T2 = 1.0; double K2 = 100;	double sig2 = 0.2;	double r2 = 0.0;	double S2 = 100;	double b2 = r2;

	EuropeanOption Batch2(K2, T2, r2, sig2);
	double C2 = Batch2.CallPrice_struct(S2);
	double P2 = Batch2.PutPrice_struct(S2);

	cout << "\nBatch2 out put using structs " << endl;
	cout << " Call Price : " << C2 << endl;
	cout << " Put Price :  " << P2 << endl;


	//	Batch 3
	double T3 = 1.0; double K3 = 10;	double sig3 = 0.50;	double r3 = 0.12;	double S3 = 5;	double b3 = r3;


	EuropeanOption Batch3(K3, T3, r3, sig3);
	double C3 = Batch3.CallPrice_struct(S3);
	double P3 = Batch3.PutPrice_struct(S3);

	cout << "\nBatch3 out put using structs " << endl;
	cout << " Call Price : " << C3 << endl;
	cout << " Put Price :  " << P3 << endl;


	//	Batch 4
	double T4 = 30.0; double K4 = 100;	double sig4 = 0.30;	double r4 = 0.08;	double S4 = 100;	double b4 = r4;
	EuropeanOption Batch4(K4, T4, r4, sig4);
	double C4 = Batch4.CallPrice_struct(S4);
	double P4 = Batch4.PutPrice_struct(S4);

	cout << "\nBatch3 out put using structs " << endl;
	cout << " Call Price : " << C4 << endl;
	cout << " Put Price :  " << P4 << endl;



	system("Pause");
	return 0;
}







