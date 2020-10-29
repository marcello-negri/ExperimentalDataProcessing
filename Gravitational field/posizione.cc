#include "posizione.h"
#include "particella.h"

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

CampoVettoriale::CampoVettoriale(const posizione& p): posizione(p.getX(), p.getY(), p.getZ()){
	m_Fx=0;
	m_Fy=0;
	m_Fz=0;
}

CampoVettoriale::~CampoVettoriale(){
}

double CampoVettoriale::Modulo () const{
	double modulo=sqrt(pow(m_Fx, 2)+pow(m_Fy, 2)+pow(m_Fz, 2));
	return modulo;
}

void CampoVettoriale::Somma (const CampoVettoriale& c){
	m_Fx=m_Fx+c.getFx();
	m_Fy=m_Fy+c.getFy();
	m_Fz=m_Fz+c.getFz();
}
