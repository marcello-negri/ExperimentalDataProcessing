#include "funzione.h"

Parabola::Parabola (){
	m_a=0;	
	m_b=0;	
	m_c=0;
}

Parabola::Parabola (double a, double b, double c){
	m_a=a;	
	m_b=b;	
	m_c=c;
}

Parabola::~Parabola(){

}


double Parabola::Eval (double x) const{
	return m_a*pow(x, 2) + m_b*x + m_c;
}


Seno::Seno(double A, double omega){
	m_A=A;
	m_omega=omega;
}
Seno::Seno(){
	m_A=1.;
	m_omega=1.;
}

Seno::~Seno(){

}

double Seno::Eval(double x)const{
	return m_A*sin(m_omega*x);
}
