#ifndef _INTEGRALE_H_
#define _INTEGRALE_H_
#include "random.h"
#include "funzione.h"

class Integral {
	public:
		Integral (double a, double b, FunzioneBase *function);
		Integral (double a, double b, double prec, FunzioneBase *function);
		Integral (Random * rand);
		~Integral ();

		double midpoint (int nstep);
		double simpson (int steps);

		double hitormiss (double a, double b, FunzioneBase *function, double fmax, unsigned int N);
		double media (double a, double b, FunzioneBase *function, unsigned int N);
		double volsfera (FunzioneScalareBase *function, unsigned int N, unsigned int dim);

	private:
		double m_a, m_b;
		double m_sum;
		double m_h;
		double m_prec;
		int m_sign;
		double m_integral;
		FunzioneBase * m_integrand;
		Random * m_rand;
};

#endif
