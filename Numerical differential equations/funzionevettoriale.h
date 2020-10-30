#ifndef _FUNZIONE_VETTORIALE_H
#define _FUNZIONE_VETTORIALE_H

#include "vettore.h"
#include <cmath>

class FunzioneVettorialeBase {
	public: 
		virtual VettoreLineare Eval(double t, const VettoreLineare& x) const = 0;
};

class OscillatoreArmonico : public FunzioneVettorialeBase {
	public:
		OscillatoreArmonico(double omega_0);
		~OscillatoreArmonico(); 
		
		virtual VettoreLineare Eval(double t, const VettoreLineare& x) const;

	private: 
		double m_omega_0;
};

class Pendolo : public FunzioneVettorialeBase {
	public:
		Pendolo(double l, double g);
		~Pendolo ();
	
		virtual VettoreLineare Eval (double t, const VettoreLineare& x) const;
	
	private:
		double m_l;
		double m_g;
};

class OscillatoreArmonicoSmorzatoForzato : public FunzioneVettorialeBase {
	public:
		OscillatoreArmonicoSmorzatoForzato(double omega_0, double omega, double alfa);
		~OscillatoreArmonicoSmorzatoForzato();
	
		virtual VettoreLineare Eval(double t, const VettoreLineare& x) const;
	
	private:
		double m_omega_0;
		double m_omega;
		double m_alfa;
};

#endif
