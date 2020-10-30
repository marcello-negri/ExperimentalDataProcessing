#include "integrale.h"
#include <algorithm>
#include <cmath>

using namespace std;


Integral::Integral (double a, double b, FunzioneBase *function){
	m_integrand = function;
	m_a = min(a,b);
	m_b = max(a,b);
	if (a > b) m_sign = -1;
	else m_sign = 1;
}

Integral::Integral (double a, double b, double prec, FunzioneBase *function){
	m_integrand = function;
	m_a = min(a,b);
	m_b = max(a,b);
	m_prec = prec;
	if (a > b) m_sign = -1;
	else m_sign = 1;
	m_sum=(m_integrand->Eval(m_a)+m_integrand->Eval(m_b))/2;
	m_integral=m_sum*(m_b-m_a);
}

double Integral::midpoint (int nstep){
	m_sum = 0.;
	m_h = (m_b-m_a)/nstep;

	for (int i=0; i<nstep; i++){
		double x = m_a + (i+0.5)*m_h;
		m_sum += m_integrand->Eval(x);
	}

	m_integral = m_sign*m_sum*m_h;

	return m_integral;
}

double Integral::simpson (int nstep){
	m_sum = 0.;
	m_h = (m_b-m_a)/nstep;
	
	for (int i=1; i<nstep; i++){
		double x = m_a + i*m_h;
		if (i%2==0){		
			m_sum += 2*(m_integrand->Eval(x));
		} else if (i%2==1){		
			m_sum += 4*(m_integrand->Eval(x));
		}
	}
	
	m_sum+=(m_integrand->Eval(m_a)+m_integrand->Eval(m_b));
	m_integral = m_sign*m_sum*m_h/3.;
	return m_integral;
}

double Integral::trapezi(double precisione){
	double somma = 0;
	double integral = m_integral;
	int quanti=2;
	double h = 0;
	do{
		SetIntegral(integral);
		h=(m_b-m_a)/quanti;
		for(int j=1; j<quanti; j++){
			if( j%2!=0 ) {
				somma = m_sum + m_integrand->Eval(m_a + j*h);
				m_sum = somma;
			}
		}
		integral = m_sum*h;
		quanti = quanti*2;
	}
	while (fabs(m_integral-integral)>precisione);
	SetIntegral(integral);
	return m_integral;
}

