#include "particella.h"
#include "posizione.h"
#include <iomanip>

int main(){
	const double mt = 5.9726E24; //kg
	const double rt = 6.372797E6; //m
	const double ds = 2.5E5; //m
	const double rm = 1.0E3; //m
	const double mm = 3.0E3*4*M_PI*pow(rm,3)/3; //kg
	double deltag;
	puntoMateriale Terra(mt, 0., 0., 0., 0.);

	posizione r (0., 0., ds+rt);
	CampoVettoriale G(r);
	posizione s (0., 0., rt);

	G.Somma(Terra.CampoGravitazionale(r));

	cout<<endl<<"L'accelerazione di gravita' sul satellite in ("<<r.getX()<<", "<<r.getY()<<", "<<r.getZ()<<") e':"<<endl;
	cout<<"G=("<<setprecision(4)<<G.getFx()<<", "<<G.getFy()<<", "<<setprecision(11)<<G.getFz()<<") m/s^2"<<endl<<endl;


	CampoVettoriale M(r);

	puntoMateriale** montagna=new puntoMateriale* [500];
	for(unsigned int i=0; i<500; i++){
	double phi = i*2.*rm/rt;
	montagna [i]= new puntoMateriale (mm, 0., rt*cos(phi), rt*sin(phi), 0.);
	}
	
	for(unsigned int i=0; i<500; i++){
		M.Somma(montagna[i]->CampoGravitazionale(r));
	}
	
	M.Somma(Terra.CampoGravitazionale(r));
	cout<<"L'accelerazione di gravita' in presenza della catena montuosa sul satellite in ("<<r.getX()<<", "<<r.getY()<<", "<<r.getZ()<<") e':"<<endl;
	cout<<"G=("<<setprecision(4)<<M.getFx()<<", "<<M.getFy()<<", "<<setprecision(11)<<M.getFz()<<") m/s^2"<<endl<<endl;
	
	deltag=(M.getFz()-G.getFz())/G.getFz();
	cout<<"La variazione percentuale di accelerazione di gravita' e':"<<endl;
	cout<<setprecision(4)<<deltag<<"\%"<<endl<<endl;
	
	return 0;

}
