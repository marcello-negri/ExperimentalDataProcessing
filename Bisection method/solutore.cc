#include "solutore.h"

using namespace std;

int sgn(double x){
	
	if (x<0)
		return -1;
	else
		return 1;
}

Solutore::Solutore(){
	m_a=0;
	m_b=0;
	m_prec=1E-6;
	m_f=NULL;
}

double Bisezione::CercaZeri (double xmin, double xmax, const FunzioneBase* f, int iterazioni, double precisione){
	
	m_prec=precisione;

	if (xmin>xmax){
		m_a = xmax;
		m_b = xmin;
	} else {
		m_a = xmin;
		m_b = xmax;
	}
	
	double a = m_a;
	double b = m_b;
	double xm;
	int conta=0;
	

	if (f->Eval(a)==0){
		return a;
	}
	if (f->Eval(b)==0){
		return b;
	}
	if (sgn(f->Eval(a))*sgn(f->Eval(b))==-1){
		xm=(a+b)/2;
			while (abs(b-a)>m_prec){
				if (conta<iterazioni){	
					if (sgn(f->Eval(xm))*sgn(f->Eval(b))==-1){
						a=xm;
					} else{
						b=xm;
					}
					xm=(a+b)/2;
					conta++;
					}
				else {
					cout << endl << "La ricerca ha effettutato il numero massimo di iterazioni permesse, la precisione richiesta e' troppo piccola" << endl;
					return -9999;			}
		}	
	}else{
		cout << endl << "L'intervallo scelto non soddisfa le ipotesi di Bolzano!!!" << endl << endl;
		return -9999;
	}

	return xm;
}
