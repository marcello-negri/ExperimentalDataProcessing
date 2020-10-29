#ifndef _PARTICELLA_H_
#define _PARTICELLA_H_

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "posizione.h"

//****************************************** PARTICELLA ******************************************************

class particella{

	public:
		particella();
		particella(double m, double q);
		~particella();

		double getMassa()const {return m_m;};
		double getCarica()const {return m_q;};
		virtual void stampa()const;

	protected:
		double m_m, m_q;
};

//****************************************** ELETTRONE ******************************************************

class elettrone :public particella{

	public:
		elettrone();
		~elettrone();

		void stampa()const;
};


//****************************************** CORPO CELESTE ******************************************************

class CorpoCeleste :public particella {

	public:
		CorpoCeleste(string, double, double);
		CorpoCeleste(string nome, double m, double x, double y, double z);
		~CorpoCeleste();

		void setRaggio(double raggio){m_raggio=raggio;};
		void setNome(string nome){m_nome=nome;};
		void setMassa(double m){m_m=m;};

		double getRaggio(){return m_raggio;};
		string getNome(){return m_nome;};

		void setPosizione(double x, double y, double z){m_p = posizione(x,y,z);};
		posizione getPosizione(){return m_p;};

		double distanza(CorpoCeleste &c);
		double potenzialeGravitazionale(CorpoCeleste &c);

		virtual void stampa()const;

	protected:
		double m_raggio;
		string m_nome;
		posizione m_p;
};


class puntoMateriale : public particella, posizione {
	public:
	puntoMateriale(double m, double q, double x, double y, double z);
	~puntoMateriale();
	CampoVettoriale CampoElettrico (const posizione &r)const;
	CampoVettoriale CampoGravitazionale (const posizione &r) const;

};

#endif
