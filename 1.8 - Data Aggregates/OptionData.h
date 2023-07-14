#pragma once
#include <iostream>
using namespace std;


struct OptionData
{ // Option data + behaviour

	double K;
	double T;
	double r;
	double sig;

	// Extra data 
	double D;		// dividend
	double beta;	// elasticity factor (CEV model)

	int type;		// 1 == call, -1 == put

};

void print(OptionData data) // Call by value
{
	cout << "Strike: " << data.K << endl;
	cout << "Expiry: " << data.T << endl;
	cout << "Interest: " << data.r << endl;
	cout << "Volatility: " << data.sig << endl;
	cout << "Dividend: " << data.D << endl;
	cout << "Elasticity factor (beta): " << data.beta << endl;
	cout << "Call +1 or Put -1: " << data.type << endl;
}

void print2(struct OptionData* data) // Call by value
{
	cout << "Strike: " << data->K << endl;
	cout << "Expiry: " << data->T << endl;
	/*	cout << "Interest: " << data.r << endl;
		cout << "Volatility: " << data.sig << endl;
		cout << "Dividend: " << data.D << endl;
		cout << "Elasticity factor (beta): " << data.beta << endl;
		cout << "Call +1 or Put -1: " << data.type << endl;*/
}