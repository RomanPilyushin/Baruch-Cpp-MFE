// Here I implemented  following function as a global functions.
//std::vector<double> mesher(double min_val, double max_val, double h)  (Inside Mesher.h file)

//Function to print vector. (Inside Global_print.h)
//void print(const vector<double>& vec)

//Function to print matrix. (Inside Global_print.h)
//void print(const vector<vector<double>>& matrix) 

#include <iostream>
#include <fstream>
#include <vector>
#include "EuropeanOption.h"
#include "Mesher.h"
#include "Global_print.h"

using namespace std;


int main()
{

	// Batch 1

	cout << "\nOutput for Batch 1" << endl;
	double T1 = 0.25; double K1 = 65;	double sig1 = 0.30;	double r1 = 0.08;	double S1 = 60;	double b1 = r1;
	vector<double> Svector = mesher(10, 50, 1); // Vector of S values.
	int Svecsize = Svector.size();

	vector<vector<double>> resultBatch1d(Svecsize, 2);
	EuropeanOption Batch1d(K1, T1, r1, sig1);

	for (int i = 0; i < Svecsize; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
				resultBatch1d[i][j] = Batch1d.CallPrice_struct(Svector[i]);
			else
				resultBatch1d[i][j] = Batch1d.PutPrice_struct(Svector[i]);
		}
	}

	print(resultBatch1d);

	// Batch 2

	cout << "\nOutput for Batch 2" << endl;
	double T2 = 1.0; double K2 = 100;	double sig2 = 0.2;	double r2 = 0.0;	double S2 = 100;	double b2 = r2;
	vector<vector<double>> resultBatch2d(Svecsize, 2);


	EuropeanOption Batch2d(K2, T2, r2, sig2);

	for (int i = 0; i < Svecsize; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
				resultBatch2d[i][j] = Batch2d.CallPrice_struct(Svector[i]);
			else
				resultBatch2d[i][j] = Batch2d.PutPrice_struct(Svector[i]);
		}
	}

	print(resultBatch2d);



	//	Batch 3
	cout << "\nOutput for Batch 3" << endl;
	double T3 = 1.0; double K3 = 10;	double sig3 = 0.50;	double r3 = 0.12;	double S3 = 5;	double b3 = r3;
	vector<vector<double>> resultBatch3d(Svecsize, 2);


	EuropeanOption Batch3d(K3, T3, r3, sig3);

	for (int i = 0; i < Svecsize; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
				resultBatch3d[i][j] = Batch3d.CallPrice_struct(Svector[i]);
			else
				resultBatch3d[i][j] = Batch3d.PutPrice_struct(Svector[i]);
		}
	}

	print(resultBatch3d);


	//	Batch 4
	cout << "\nOutput for Batch 4" << endl;
	double T4 = 30.0; double K4 = 100;	double sig4 = 0.30;	double r4 = 0.08;	double S4 = 100;	double b4 = r4;
	vector<vector<double>> resultBatch4d(Svecsize, 2);


	EuropeanOption Batch4d(K4, T4, r4, sig4);

	for (int i = 0; i < Svecsize; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (j == 0)
				resultBatch4d[i][j] = Batch4d.CallPrice_struct(Svector[i]);
			else
				resultBatch4d[i][j] = Batch4d.PutPrice_struct(Svector[i]);
		}
	}

	print(resultBatch4d);



	system("Pause");
	return 0;
}







