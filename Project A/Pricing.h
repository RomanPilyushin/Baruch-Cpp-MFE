/* This file contains four functions.
		EuropeanCall(double S, double K, double T, double r, double sig, double b) // Calculate Call Option price
		EuropeanPut(double S, double K, double T, double r, double sig, double b)  // Calculate Put Optin price
		EuropeanCall(double S, EuropeanOption::OptionData* OD) // Calculate the Call Option price using the struct.
		EuropeanPut(double S,  EuropeanOption::OptionData* OD) // Calculate the Put Option price using the struct.

*/
#ifndef PRICING_H
#define PRICING_H

#include<cmath>
#include "Normal_Boost.h"
#include "EuropeanOption.h"

double EuropeanCall(double S, EuropeanOption::OptionData* OD)
{

	double K = OD->K_s;
	double T = OD->T_s;
	double r = OD->r_s;
	double sig = OD->sig_s;
	double b = r;

	double tmp = sig * sqrt(T);

	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;


	return (S * exp((b - r) * T) * N_BOOST(d1)) - (K * exp(-r * T) * N_BOOST(d2));


}

double EuropeanPut(double S, EuropeanOption::OptionData* OD)
{

	double K = OD->K_s;
	double T = OD->T_s;
	double r = OD->r_s;
	double sig = OD->sig_s;
	double b = r;

	double tmp = sig * sqrt(T);
	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;

	return (K * exp(-r * T) * N_BOOST(-d2)) - (S * exp((b - r) * T) * N_BOOST(-d1));
}


double EuropeanCall(double S, double K, double T, double r, double sig, double b)
{

	double tmp = sig * sqrt(T);

	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;


	return (S * exp((b - r) * T) * N_BOOST(d1)) - (K * exp(-r * T) * N_BOOST(d2));


}


double EuropeanPut(double S, double K, double T, double r, double sig, double b)
{
	double tmp = sig * sqrt(T);
	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;

	return (K * exp(-r * T) * N_BOOST(-d2)) - (S * exp((b - r) * T) * N_BOOST(-d1));
}


#endif