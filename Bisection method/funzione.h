#ifndef _FUNZIONE_H_
#define _FUNZIONE_H_

#include <cmath>

class FunzioneBase {
	public:
		virtual double Eval (double x) const =0;
};

class Parabola: public FunzioneBase {
	public:
		Parabola();
		Parabola (double a, double b, double c);
		~Parabola();

		virtual double Eval (double x) const;
		void SetA(double a){m_a=a;};
		void SetB(double b){m_b=b;};		
		void SetC(double c){m_c=c;};
		double GetA() const {return m_a;};				
		double GetB() const {return m_b;};			
		double GetC() const {return m_c;};				

	private:
		double m_a, m_b, m_c;
}; 

class FunzMeccQuant: public FunzioneBase {
	public:
		virtual double Eval (double x) const;
};

#endif
