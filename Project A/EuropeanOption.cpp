// EuropeanOption class implementaion.

#include <iostream>

#include "EuropeanOption.h"
#include "Normal_Boost.h"
#include "Pricing.h"
#include "Greeks.h"
#include <math.h> 

//using namespace boost::math;


// Default constructor , 
EuropeanOption::EuropeanOption()
{
	r = 0.08;
	sig = 0.3;
	K = 65;
	T = 0.25;
	b = r;				// Black and Scholes stock option model (1973)
	optType = "C";		// Default call option
}

//	Overloaded constructor
EuropeanOption::EuropeanOption(double K_c, double T_c, double r_c, double sig_c, double b_c, string str)  // overloaded constructor 
{


	K = K_c;
	T = T_c;
	r = r_c;
	sig = sig_c;
	b = b_c;
	optType = str;
}

// overloaded constructor to creat a the sturct
EuropeanOption::EuropeanOption(double K_c, double T_c, double r_c, double sig_c)
{
	Optionstruct = new OptionData;
	Optionstruct->K_s = K_c;
	Optionstruct->T_s = T_c;
	Optionstruct->r_s = r_c;
	Optionstruct->sig_s = sig_c;

	///double b = r_c;
	//optType = "C";

}

// Copy constructor
EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{

	r = o2.r;
	sig = o2.sig;
	K = o2.K;
	T = o2.T;
	b = o2.b;
	optType = o2.optType;
}


EuropeanOption::~EuropeanOption()
{

}


//Assignment operator
EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{
	if (this == &option2) return *this;

	EuropeanOption::EuropeanOption(option2);
	return *this;
}

// Calling global gaussian functions using private functions
double EuropeanOption::n(double x) const
{
	return n_BOOST(x);
}

double EuropeanOption::N(double x) const
{
	return N_BOOST(x);
}


// Calling global Call and Put option functions using private functions
double EuropeanOption::CallPrice(double S) const
{
	return EuropeanCall(S, K, T, r, sig, b);
}


// Calling global Call and Put option functions using OptionData sturct.
double EuropeanOption::PutPrice(double S) const
{

	return EuropeanPut(S, K, T, r, sig, b);
}
// Call global CallDelta fucntion
double EuropeanOption::Call_CallDelta(double S) const
{
	return CallDelta(S, K, T, r, sig, b);
}

double EuropeanOption::Call_PutDelta(double S) const
{
	return PutDelta(S, K, T, r, sig, b);
}

double EuropeanOption::Call_CallGamma(double S) const
{
	return CallGamma(S, K, T, r, sig, b);
}

double EuropeanOption::Call_PutGamma(double S) const
{
	return PutGamma(S, K, T, r, sig, b);
}

///////////////////////////////////////////////////////////////////////////////
// CallPrice_sturct() to pass struct
double EuropeanOption::CallPrice_struct(double S) const
{
	return EuropeanCall(S, (*this).Optionstruct);
}

// CallPrice_sturct() to pass struct
double EuropeanOption::PutPrice_struct(double S) const
{
	return EuropeanPut(S, (*this).Optionstruct);
}
////////////////////////////////////////////////////////////////////////////////

// Function to decide which Optin price function to use.
double EuropeanOption::Price(double U) const
{


	if (optType == "C")
	{
		return CallPrice(U);
	}
	else
	{
		return PutPrice(U);
	}
}


// Change option type (C/P, P/C)
void EuropeanOption::toggle()
{

	if (optType == "C")
		optType = "P";
	else
		optType = "C";
}

double EuropeanOption::put_call_parity(double assetP, double val, string str) const
{

	double tmp = K * exp(-r * T);


	if (str == "C")
	{
		double C = val;
		return (C - assetP + tmp);

	}
	else
	{
		double P = val;
		return (P + assetP - tmp);
	}
}