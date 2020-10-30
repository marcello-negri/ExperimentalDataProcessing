#ifndef _EQUAZIONE_DIFFERENZIALE_H
#define _EQUAZIONE_DIFFERENZIALE_H

#include "vettore.h"
#include "funzionevettoriale.h" 

class EquazioneDifferenzialeBase{
	public: 
		virtual VettoreLineare Passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase *f) const= 0;
};

class Eulero : public EquazioneDifferenzialeBase {
	public:
		Eulero();
		~Eulero();
		virtual VettoreLineare Passo(double t, const VettoreLineare& x, double h, FunzioneVettorialeBase *f) const;	
};

class RK : public EquazioneDifferenzialeBase {
	public:
		RK();
		~RK();
		virtual VettoreLineare Passo(double t, const VettoreLineare& x, double h, FunzioneVettorialeBase *f) const;	
};

#endif
