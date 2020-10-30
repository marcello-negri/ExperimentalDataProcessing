#include "funzione.h"
#include "solutore.h"
#include <cstdlib>

using namespace std;

int main (int argc, char ** argv){
	
	if (argc!=2){
		cerr << endl << "Utilizzo: " << argv[0] << " <precisione> " << endl << endl;
		return -1;
	}

	double prec = atof(argv[1]);
	double zeri [20];
	int cifre = -log10(prec);
	
	FunzioneBase * f = new FunzMeccQuant;
	Bisezione ** ricerca = new Bisezione * [21];
	
	for (unsigned int i=0; i<21; i++){
		ricerca [i] = new Bisezione ();
		zeri[i] = ricerca[i]->CercaZeri(i*M_PI, i*M_PI+M_PI/2, f, 500, prec);
	}
	
	cout << endl << "Di seguito sono riportate le soluzioni di x = tan(x), trovate utilizzando il metodo della bisezione." << endl;
	cout << "x0(n) sono le ascisse delle soluzioni mentre a e b sono gli estremi degli intervalli considerati:" << endl << endl;
	cout << "==================================================================================" << endl;
	cout << setw(2) << "n" << setw(20) << "x0(n)" << setw(20) << "precisione" << setw(20) << "a" << setw(20) << "b" << endl;
	cout << "==================================================================================" << endl;
		cout<<fixed;
	for (unsigned int i=0; i<21; i++){
		cout << setw (2) << i << setw(20) << setprecision(cifre) << zeri[i] << setw(20) << prec << setw(20) << i*M_PI << setw(20) << i*M_PI+M_PI/2 << endl;
		cout << "----------------------------------------------------------------------------------" << endl;
	}
	cout << endl;
	
	return 0;
}
