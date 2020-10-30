#include "random.h"
#include "vettore.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "TCanvas.h"
#include "TH1F.h"
#include "TApplication.h"

using namespace std;

int main (int argc, char** argv){
	
	if (argc!=3){
		cerr << "Utilizzo: " << argv[0] << " <ntot> <n>" << endl;
		return -1;
	}	
	
	TApplication app ("app", 0, 0);
	Random rand(3);
	
	unsigned int ntot = atoi(argv[1]);
	unsigned int n = atoi(argv[2]);
	
	VettoreDati vett(ntot);
	
	for (unsigned int i=0; i<ntot; i++){
		vett.SetComponent(i, rand.Rand());
	}
	
	unsigned int quanti = int(ntot/n);
	
	VettoreDati somme (quanti);
	
	for (unsigned int i = 0; i<quanti; i++){
		double appo=0;
		for (unsigned int j = i*n; j<(i+1)*n; j++){
			appo+=vett.GetComponent(j);
		}		
		somme.SetComponent(i, appo);
	}
	
	cout << endl << "La varianza dei numeri casuali e': " << vett.VarPop() << endl;
	cout << "La varianza delle somme e': " << somme.VarPop() << endl << endl;
	
	TH1F h("isto", "Vettore numeri casuali", 100, 0, 1);

	for (unsigned int i=0; i<ntot; i++){
		double n = vett.GetComponent(i);
		h.Fill(n);
	}
	
	
	TCanvas * c1 = new TCanvas ("c1", "c1");	
	c1->cd();
	h.Draw();

	TH1F h2("isto", "Vettore somme", 100, 0, n);

	for (unsigned int i=0; i<quanti; i++){
		double n = somme.GetComponent(i);
		h2.Fill(n);
	}
	
	
	TCanvas * c2 = new TCanvas ("c2", "c2");	
	c2->cd();
	h2.Draw();
	app.Run();

	return 0;
}
