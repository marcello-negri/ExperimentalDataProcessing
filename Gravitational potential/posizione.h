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

	private:
		double m_x, m_y, m_z;
};

#endif
