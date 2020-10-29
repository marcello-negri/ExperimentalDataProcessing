#ifndef _POSIZIONE_SFERICHE_H_
#define _POSIZIONE_SFERICHE_H_

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class posizione{
	
	public:
		posizione();
		posizione(double x, double y, double z);
		~posizione();

		double distanza(const posizione&)const;
		
		double getR()const {return m_R;};
		double getTheta()const {return m_Theta;};
		double getPhi()const {return m_Phi;};
		double getX()const;
		double getY()const;
		double getZ()const;
		double getRho()const;
		
	private:
		double m_R, m_Theta, m_Phi;
};

#endif 
