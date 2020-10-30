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
}

Integral::Integral(Random * rand) {
	m_rand=rand;
}

Integral::~Integral(){
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


double Integral::hitormiss (double a, double b, FunzioneBase *function, double fmax, unsigned int N){ 	
	double x, y, fx;	
	int nhit=0;
	for (unsigned int i=0; i<N; i++){
		x = a + (b-a)*(m_rand->Rand());
		y = fmax*(m_rand->Rand());
		fx=function->Eval(x);
		if (y<fx) nhit++;
	}
	return (b-a)*fmax*nhit/N;
}
double Integral::media (double a, double b, FunzioneBase *function, unsigned int N){
	double x, fx, appo=0;	
	for (unsigned int i=0; i<N; i++){
		x = a + (b-a)*m_rand->Rand();
		fx=function->Eval(x);
		appo+=fx;
	}
	return appo*(b-a)/N;
}


double Integral::volsfera (FunzioneScalareBase *function, unsigned int N, unsigned int dim){
	VettoreDati * appo = new VettoreDati (dim);
	double fx;
	int nhit=0;
	
	for (unsigned int j=0; j<N; j++){
		for (unsigned int i=0; i<dim; i++){
			appo->SetComponent(i, m_rand->Rand());
		}
		fx=function->Eval(appo);
		if (fx==1) nhit++;
	}
	return pow(2, dim)*nhit/N;	
}

