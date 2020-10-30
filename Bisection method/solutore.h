#ifndef _SOLUTORE_H_
#define _SOLUTORE_H_

#include "funzione.h"
#include <cmath>
#include <iostream>
#include <iomanip>


class Solutore{
	public:
		Solutore ();
		~Solutore (){};
		virtual double CercaZeri (double xmin, double xmax, const FunzioneBase* f, int iterazioni, double precisione)=0;
		void SetPrecisione (double epsilon) {m_prec=epsilon;};
		double GetPrecisione () {return m_prec;};

	protected:
		double m_a, m_b;
		double m_prec;
		const FunzioneBase * m_f;
};

int sgn(double x);

class Bisezione: public Solutore{
	public:
		double CercaZeri (double xmin, double xmax, const FunzioneBase* f, int iterazioni, double precisione);
};

#endif
