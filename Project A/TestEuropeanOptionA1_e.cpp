//Here I am claculating Call option prices and Put option prices as function of expiry time T and function of volatility.
// Output Matrix : First colum-Call price, Second colum-Put price.

#include <iostream>
#include <fstream>
#include <vector>
#include "EuropeanOption.h"
#include "Mesher.h"
#include "Global_print.h"

using namespace std;


int main()
{
	// Maturity time varies from 0.25 to 1.0 with stepsize 0.25
	// Batch 1
	cout << "Range for maturity 0.25 to 1. Step size 0.25" << endl;
	cout << "\nOutput for Batch 1 (Function of Maturity)" << endl;
	double T1 = 0.25; double K1 = 65;	double sig1 = 0.30;	double r1 = 0.08;	double S1 = 60;	double b1 = r1;

	vector<double> ETvector = mesher(0.25, 1, 0.25); // Range for maturity 0.25 to 1. Step size 0.25
	int ETvecsize = ETvector.size();
	vector<vector<double>> resultBatch1e1(ETvecsize, 2);



	for (int i = 0; i < ETvecsize; ++i)
	{
		EuropeanOption Batch1e1(K1, ETvector[i], r1, sig1, b1, "c");
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
			{
				resultBatch1e1[i][j] = Batch1e1.CallPrice(S1);

			}
			else
				resultBatch1e1[i][j] = Batch1e1.PutPrice(S1);

		}
	}

	print(resultBatch1e1);


	// Batch 2

	cout << "\nOutput for Batch 2 (Function of Maturity)" << endl;
	double T2 = 1.0; double K2 = 100;	double sig2 = 0.2;	double r2 = 0.0;	double S2 = 100;	double b2 = r2;
	vector<vector<double>> resultBatch2e1(ETvecsize, 2);


	for (int i = 0; i < ETvecsize; ++i)
	{
		EuropeanOption Batch2e1(K2, ETvector[i], r2, sig2, b2, "c");
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
			{
				resultBatch2e1[i][j] = Batch2e1.CallPrice(S2);

			}
			else
				resultBatch2e1[i][j] = Batch2e1.PutPrice(S2);

		}
	}

	print(resultBatch2e1);


	// Batch 3

	cout << "\nOutput for Batch 3 (Function of Maturity)" << endl;
	double T3 = 1.0; double K3 = 10;	double sig3 = 0.50;	double r3 = 0.12;	double S3 = 5;	double b3 = r3;
	vector<vector<double>> resultBatch3e1(ETvecsize, 2);


	for (int i = 0; i < ETvecsize; ++i)
	{
		EuropeanOption Batch3e1(K3, ETvector[i], r3, sig3, b3, "c");
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
			{
				resultBatch3e1[i][j] = Batch3e1.CallPrice(S3);

			}
			else
				resultBatch3e1[i][j] = Batch3e1.PutPrice(S3);

		}
	}

	print(resultBatch3e1);

	// Batch 4

	cout << "\nOutput for Batch 4 (Function of Maturity)" << endl;
	double T4 = 30.0; double K4 = 100;	double sig4 = 0.30;	double r4 = 0.08;	double S4 = 100;	double b4 = r4;
	vector<vector<double>> resultBatch4e1(ETvecsize, 2);


	for (int i = 0; i < ETvecsize; ++i)
	{
		EuropeanOption Batch4e1(K4, ETvector[i], r4, sig4, b4, "c");
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
			{
				resultBatch4e1[i][j] = Batch4e1.CallPrice(S4);

			}
			else
				resultBatch4e1[i][j] = Batch4e1.PutPrice(S4);

		}
	}

	print(resultBatch4e1);



	// Volatility varies from 0.1 to 0.5 with stepsize 0.1
	// Batch 1

	cout << "Volatility varies from 0.1 to 0.5 with stepsize 0.1" << endl;
	cout << "\nOutput for Batch 1 (Function of volatility)" << endl;
	vector<double> Vvector = mesher(0.1, 0.5, 0.1);   // Range for volatility 0.1 to 0.5. Step size 0.1.
	int Vvecsize = Vvector.size();
	vector<vector<double>> resultBatch1e2(Vvecsize, 2);



	for (int i = 0; i < Vvecsize; ++i)
	{
		EuropeanOption Batch1e2(K1, T1, r1, Vvector[i], b1, "c");
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
			{
				resultBatch1e2[i][j] = Batch1e2.CallPrice(S1);

			}
			else
				resultBatch1e2[i][j] = Batch1e2.PutPrice(S1);

		}
	}

	print(resultBatch1e2);



	// Batch 2

	cout << "\nOutput for Batch 2 (Function of volatility)" << endl;
	vector<vector<double>> resultBatch2e2(Vvecsize, 2);



	for (int i = 0; i < Vvecsize; ++i)
	{
		EuropeanOption Batch2e2(K2, T2, r2, Vvector[i], b2, "c");
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
			{
				resultBatch2e2[i][j] = Batch2e2.CallPrice(S2);

			}
			else
				resultBatch2e2[i][j] = Batch2e2.PutPrice(S2);

		}
	}

	print(resultBatch2e2);

	// Batch 3
	cout << "\nOutput for Batch 3 (Function of volatility)" << endl;
	vector<vector<double>> resultBatch3e2(Vvecsize, 2);



	for (int i = 0; i < Vvecsize; ++i)
	{
		EuropeanOption Batch3e2(K3, T3, r3, Vvector[i], b3, "c");
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
			{
				resultBatch3e2[i][j] = Batch3e2.CallPrice(S3);

			}
			else
				resultBatch3e2[i][j] = Batch3e2.PutPrice(S3);

		}
	}

	print(resultBatch3e2);


	// Batch 4
	cout << "\nOutput for Batch 4 (Function of volatility)" << endl;
	vector<vector<double>> resultBatch4e2(Vvecsize, 2);



	for (int i = 0; i < Vvecsize; ++i)
	{
		EuropeanOption Batch4e2(K4, T4, r4, Vvector[i], b4, "c");
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
			{
				resultBatch4e2[i][j] = Batch4e2.CallPrice(S4);

			}
			else
				resultBatch4e2[i][j] = Batch4e2.PutPrice(S4);

		}
	}

	print(resultBatch4e2);


	system("Pause");
	return 0;
}








