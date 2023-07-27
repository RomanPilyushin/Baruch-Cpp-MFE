//EuropeanOption class header file.

# ifndef EuropeanOption_hpp
# define EuropeanOption_hpp


#include <string>
using namespace std;

class EuropeanOption
{
private:



	double r;		// Interest rate
	double sig;		// Volatility
	double K;		// Strike price
	double T;		// Expiry date
	double b;		// Cost of carry
	string optType;	// Option name (call, put)


	// Calling Gaussian functions
	double n(double x) const;
	double N(double x) const;



public:
	struct OptionData {
		double K_s;
		double T_s;
		double r_s;
		double sig_s;
	};

	OptionData* Optionstruct; //OptionData struct.

	//  Default constructor
	EuropeanOption();

	//	Overloaded constructor
	EuropeanOption::EuropeanOption(double K, double T, double r, double sig, double b, string str);

	// Overloaded constructor to create  OptionData sturct instance.
	EuropeanOption::EuropeanOption(double K_c, double T_c, double r_c, double sig_c);

	// Copy constructor
	EuropeanOption(const EuropeanOption& option2);

	//	Destructor
	virtual ~EuropeanOption();

	//	Assignment operator
	EuropeanOption& operator = (const EuropeanOption& option2);

	// Functions that calculate option price 
	double Price(double U) const;

	// Modifier functions
	void toggle();		// Change option type (C/P, P/C)

	// To call global Pricing functions in pricing.h
	double CallPrice(double U) const;
	double PutPrice(double U) const;

	//To call global sensitivities in the greeks.h file
	double Call_CallDelta(double U) const;
	double Call_PutDelta(double U) const;
	double Call_CallGamma(double U) const;
	double Call_PutGamma(double U) const;

	//
	double put_call_parity(double assetP, double val, string str) const;


	double EuropeanOption::CallPrice_struct(double S) const;
	double EuropeanOption::PutPrice_struct(double S) const;
};

# endif