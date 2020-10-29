#ifndef _POSIZIONE_H_
#define _POSIZIONE_H_

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class posizione{
	
	public:
		posizione();
		posizione(double x, double y, double z);
		~posizione();

		double distanza(const posizione/*&*/)const;
		
		double getX()const {return m_x;};
		double getY()const {return m_y;};
		double getZ()const {return m_z;};
		double getR()const;
		double getRho()const;
		double getPhi()const;
		double getTheta()const;
		
		void setX(double x) {m_x=x;};
		void setY(double y) {m_y=y;};
		void setZ(double z) {m_z=z;};
		
	protected:
		double m_x, m_y, m_z;
};

class CampoVettoriale: public posizione{
	
	public:
		CampoVettoriale(const posizione& p);
		~CampoVettoriale();
		double getFx()const {return m_Fx;};
		double getFy()const {return m_Fy;};
		double getFz()const {return m_Fz;};	
		void setFx(double fx) {m_Fx=fx;};
		void setFy(double fy) {m_Fy=fy;};
		void setFz(double fz) {m_Fz=fz;};
		double Modulo () const;
		void Somma (const CampoVettoriale&);


	protected:
		double m_Fx, m_Fy, m_Fz;

};
#endif
