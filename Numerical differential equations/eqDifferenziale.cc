#include "eqDifferenziale.h"

 
Eulero::Eulero(){
}

Eulero::~Eulero(){
}

VettoreLineare Eulero::Passo(double t, const VettoreLineare& x, double h, FunzioneVettorialeBase *f) const {
	VettoreLineare appo(2);
	VettoreLineare der(2);
	der = f->Eval(t, x);
	appo.SetComponent(0, x.GetComponent(0) + h*der.GetComponent(0));
	appo.SetComponent(1, x.GetComponent(1) + h*der.GetComponent(1));

	return appo;
}

RK::RK(){
}

RK::~RK(){
}

VettoreLineare RK::Passo(double t, const VettoreLineare& x, double h, FunzioneVettorialeBase *f) const{
	VettoreLineare  k1(2), k2(2), k3(2), k4(2);
	VettoreLineare appo(2);
	VettoreLineare appo1(2);
	k1 = f->Eval(t, x);
	k2 = f->Eval(t + h*0.5, x + k1*h*0.5);
	k3 = f->Eval(t + h*0.5, x + k2*h*0.5);
	k4 = f->Eval(t + h, x + k3*h);
	appo.SetComponent(0, x.GetComponent(0) + (k1.GetComponent(0) + 2*k2.GetComponent(0) + 2*k3.GetComponent(0) + k4.GetComponent(0))*(h/6));
	appo.SetComponent(1, x.GetComponent(1) + (k1.GetComponent(1) + 2*k2.GetComponent(1) + 2*k3.GetComponent(1) + k4.GetComponent(1))*(h/6));

	return appo;
}
