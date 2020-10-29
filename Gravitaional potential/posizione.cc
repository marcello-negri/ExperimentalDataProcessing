#include "posizione.h"

//Costruttori 

posizione::posizione(){
	m_x=0;
	m_y=0;
	m_z=0;
}

posizione::posizione(double x, double y, double z){
	m_x=x;
	m_y=y;
	m_z=z;
}

//Distruttore

posizione::~posizione(){
}

//Distanza

double posizione::distanza(const posizione/*&*/ P) const{
	double dist=sqrt(pow(m_x-P.getX(),2)+pow(m_y-P.getY(),2)+pow(m_z-P.getZ(),2));
	return dist;
}


//Coordinate sferiche
double posizione::getR()const {
return sqrt(pow(m_x,2)+pow(m_y,2)+pow(m_z,2));
}

double posizione::getPhi()const {
return atan2(m_y,m_z); 			//atan2(y,x) restituisce artg(y/x)
} 

double posizione::getTheta()const {
return acos(m_z/getR());
}

//Coordinate cilindriche
double posizione::getRho()const {
return sqrt(pow(m_x,2)+pow(m_y,2));
}

