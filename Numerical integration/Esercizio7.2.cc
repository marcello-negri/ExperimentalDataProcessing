#include "funzione.h"
#include "integrale.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main (int argc, char** argv){

	if (argc!=2){
		cerr << "Utilizzo " << argv[0] << " <precisione>" << endl << endl;
		return -1;
	}
	double prec = atof(argv[1]);
	double a = 0.;
	double b = M_PI;
	
	FunzioneBase* seno = new Seno();
	Integral *integrale = new Integral(a, b, prec, seno);
	
	cout << endl << "L'integrale di sin(x) da 0 a pi," << endl;
	cout << "calcolato con il metodo dei trapezi a precisione fissata a " << prec << ", " << endl;
	cout << "e' pari a: " << fixed << setprecision(10) << integrale->trapezi(prec) << endl << endl;

	return 0;
}
