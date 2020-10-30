#include "random.h"
#include <cmath>

using namespace std;

Random::Random(int seed){
	m_seed = seed;
	m_a = 1664525;
	m_c = 1013904223;
	m_m = pow(2, 31);
}

double Random::Rand(){
	m_seed = (m_a*m_seed + m_c)%m_m; 
	return (double(m_seed))/(m_m-1);
}

double Random::Exp(double rate){
	double z = this->Rand();
	return (-log(1-z)/rate);
}

double Random::Gauss(double mean, double sigma){
	double s = this->Rand();
	double t = this->Rand();
	double g = sqrt(-2.*log(s))*cos(2*M_PI*t);
	
	return mean + sigma*g;
}

double Random::RandGauss(double mean, double sigma){
	double a = mean-5*sigma;
	double b = mean+5*sigma;	
	double max = 1/(sigma*sqrt(2*M_PI));
	double x, y, fx, s ,t, appo;	
	do {
		s = this->Rand();
		t = this->Rand();	
		x = a + (b-a)*s;
		y = max*t;
		appo = -pow(x-mean,2)/(2*pow(sigma, 2));
		fx = exp(appo)/(sigma*sqrt(2*M_PI));		
	} while (y>fx);
	return x;
}
