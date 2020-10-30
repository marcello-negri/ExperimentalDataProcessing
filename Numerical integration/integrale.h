#ifndef _INTEGRALE_H_
#define _INTEGRALE_H_

#include "funzione.h"

class Integral {
	public:
		Integral (double a, double b, FunzioneBase *function);
		Integral (double a, double b, double prec, FunzioneBase *function);
		double midpoint (int nstep);
		double simpson (int steps);
		double trapezi (double precisione);
		void SetIntegral(double I) {m_integral=I;};

	private:
		double m_a, m_b;
		double m_sum;
		double m_h;
		double m_prec;
		int m_sign;
		double m_integral;
		FunzioneBase * m_integrand;
};

#endif
