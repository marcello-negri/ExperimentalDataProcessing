#include "posizione.h"

posizione::posizione(){
	m_R=0;
	m_Theta=0;
	m_Phi=0;
}

posizione::posizione(double x, double y, double z){
	m_R=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
	m_Theta=acos(z/m_R);
	m_Phi=atan2(y,z);
}

posizione::~posizione(){
}

/*double posizione::distanza(const posizione& P) const{
	double dist=sqrt(pow(m_x-P.getX(),2)+pow(m_y-P.getY(),2)+pow(m_z-P.getZ(),2));
	return dist;
}*/



//Coordinate sferiche
double posizione::getX()const {
return m_R*sin(m_Theta)*cos(m_Phi);
}

double posizione::getY()const {
return m_R*sin(m_Theta)*sin(m_Phi);
}

double posizione::getZ()const {
return m_R*cos(m_Theta);
}

//Coordinate cilindriche
double posizione::getRho()const {
return m_R*cos(m_Theta);
}

