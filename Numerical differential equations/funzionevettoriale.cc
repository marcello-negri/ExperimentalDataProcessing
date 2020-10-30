#include "funzionevettoriale.h"

OscillatoreArmonico::OscillatoreArmonico(double omega_0){
	m_omega_0 = omega_0;
}

OscillatoreArmonico::~OscillatoreArmonico(){
}

VettoreLineare OscillatoreArmonico::Eval(double t, const VettoreLineare& x) const{
	VettoreLineare appo(2);
	appo.SetComponent(0, x.GetComponent(1));
	appo.SetComponent(1, -m_omega_0*m_omega_0*x.GetComponent(0));
	
	return appo;
}

Pendolo::Pendolo(double l, double g){
	m_l = l;
	m_g = g;
}

Pendolo::~Pendolo (){
	
}

VettoreLineare Pendolo::Eval (double t, const VettoreLineare& x) const{
	VettoreLineare appo (2);
	appo.SetComponent(0, x.GetComponent(1));
	appo.SetComponent(1, -(m_g/m_l)*sin(x.GetComponent(0)));
	
	return appo;
}

OscillatoreArmonicoSmorzatoForzato::OscillatoreArmonicoSmorzatoForzato(double omega_0, double omega, double alfa){
	m_omega_0 = omega_0;
	m_omega = omega;
	m_alfa = alfa;
}

OscillatoreArmonicoSmorzatoForzato::~OscillatoreArmonicoSmorzatoForzato(){
	
}

VettoreLineare OscillatoreArmonicoSmorzatoForzato::Eval(double t, const VettoreLineare& x) const{
	VettoreLineare appo(2);
	appo.SetComponent(0, x.GetComponent(1));
	appo.SetComponent(1, -m_omega_0*m_omega_0*x.GetComponent(0)-m_alfa*x.GetComponent(1)+sin(m_omega*t));

	return appo;
}





