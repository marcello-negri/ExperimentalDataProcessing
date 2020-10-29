#include "particella.h"
#include "posizione.h"
//****************************************** PARTICELLA ******************************************************

//Costruttori

particella::particella(){
	m_m=0;
	m_q=0;
}

particella::particella(double m, double q){
	m_m=m;
	m_q=q;
}

//Distruttore

particella::~particella(){
}

//Metodi

void particella::stampa()const {
	cout<<"Massa = "<<m_m<<endl;
	cout<<"Carica = "<<m_q<<endl;
};

//****************************************** ELETTRONE ******************************************************

//Costruttore --> definisce massa e carica specifici di un elettrone

elettrone::elettrone() : particella(9.1093826E-31, -1.60217653E-19){

}

//Distruttore

elettrone::~elettrone(){

}

//Metodi

void elettrone::stampa() const{
	cout<<"Questo e' un elettrone!!"<<endl;
	cout<<"Massa = "<<m_m<<endl;
	cout<<"Carica = "<<m_q<<endl;
}

//****************************************** CORPO CELESTE ******************************************************

//Costruttori

CorpoCeleste::CorpoCeleste(string nome, double m, double r) : particella(m, 0){
	m_nome=nome;
	m_raggio=r;
}

CorpoCeleste::CorpoCeleste(string nome, double m, double x, double y, double z) : particella(m, 0){
	m_nome=nome;
	m_p=posizione(x,y,z);

}


//Distruttore

CorpoCeleste::~CorpoCeleste(){

}

//Metodi

void CorpoCeleste::stampa() const{
	cout<<"Nome = "<< m_nome<<endl;
	cout<<"Massa = "<<m_m<<endl;
	cout<<"Raggio = "<<m_raggio<<endl;
}

double CorpoCeleste::distanza(CorpoCeleste &c){

	double dist=sqrt(pow(m_p.getX()-c.m_p.getX(),2)+pow(m_p.getY()-c.m_p.getY(),2)+pow(m_p.getZ()-c.m_p.getZ(),2));
	return dist;
}

double CorpoCeleste::potenzialeGravitazionale(CorpoCeleste &c){
	double G = -6.67E-11;
	double dist = distanza(c);
	return G*m_m/dist;
}


puntoMateriale::puntoMateriale(double m, double q, double x, double y, double z): particella(m,q), posizione (x,y,z){

}

puntoMateriale::~puntoMateriale(){

}

CampoVettoriale puntoMateriale::CampoElettrico (const posizione &r)const{
	CampoVettoriale appo(r);
	double fx, fy,fz, k=1/(4*M_PI*8.854187817E-12), modulo;
	modulo=pow(pow(m_x-r.getX(),2)+pow(m_y-r.getY(),2)+pow(m_z-r.getZ(),2),1.5);
	fx=k*m_q*(r.getX()-m_x)/modulo;
	fy=k*m_q*(r.getY()-m_y)/modulo;
	fz=k*m_q*(r.getZ()-m_z)/modulo;
	appo.setFx(fx);
	appo.setFy(fy);
	appo.setFz(fz);
	return appo;
}

CampoVettoriale puntoMateriale::CampoGravitazionale (const posizione &r)const{
	CampoVettoriale appo(r);
	double fx, fy,fz, G=-6.67428E-11, modulo;
	modulo=pow(pow(m_x-r.getX(),2)+pow(m_y-r.getY(),2)+pow(m_z-r.getZ(),2),1.5);
	fx=G*m_m*(r.getX()-m_x)/modulo;
	fy=G*m_m*(r.getY()-m_y)/modulo;
	fz=G*m_m*(r.getZ()-m_z)/modulo;
	appo.setFx(fx);
	appo.setFy(fy);
	appo.setFz(fz);
	return appo;
}
