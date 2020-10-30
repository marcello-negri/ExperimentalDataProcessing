#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

#include "funzionevettoriale.h"
#include "eqDifferenziale.h" 

#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TApplication.h"

using namespace std;

int main (){

	double h = 0.01;
	double t = 0., alfa = 1./30, omega0 = 10., omega1 = 5., omega2 = 10., omega3 = 15.;
	int nstep = int (1/(alfa*h) + 0.5);
	TApplication app ("app", 0, 0);
	RK myRK;
	OscillatoreArmonicoSmorzatoForzato *smorzo1 = new OscillatoreArmonicoSmorzatoForzato(omega0, omega1, alfa);
	OscillatoreArmonicoSmorzatoForzato *smorzo2 = new OscillatoreArmonicoSmorzatoForzato(omega0, omega2, alfa);
	OscillatoreArmonicoSmorzatoForzato *smorzo3 = new OscillatoreArmonicoSmorzatoForzato(omega0, omega3, alfa);
	
	TGraph *posizione1 = new TGraph();
	TGraph *posizione2 = new TGraph();
	TGraph *posizione3 = new TGraph();
	TGraph *lorentz = new TGraph();
	VettoreLineare x(2);
	x.SetComponent(0, 0.);
	x.SetComponent(1, 0.);
	

	for (int step = 0; step<nstep; step++){
		posizione1->SetPoint(step, t, x.GetComponent(0));
		x = myRK.Passo(t,x, h, smorzo1);
		t = t + h;
	}

	x.SetComponent(0, 0.);
	x.SetComponent(1, 0.);
	
	t=0;
	for (int step = 0; step<nstep; step++){
		posizione2->SetPoint(step, t, x.GetComponent(0));
		x = myRK.Passo(t,x, h, smorzo2);
		t = t + h;
	}

	x.SetComponent(0, 0.);
	x.SetComponent(1, 0.);
	
	t=0;
	for (int step = 0; step<nstep; step++){
		posizione3->SetPoint(step, t, x.GetComponent(0));
		x = myRK.Passo(t,x, h, smorzo3);
		t = t + h;
	}
	
	TCanvas myCanvas("c1", "c1");
	myCanvas.Divide(1, 3);
	
	myCanvas.cd(1);
	posizione1->SetTitle("Pulsazione = 5 rad/s");
	posizione1->Draw("AL");
	posizione1->GetXaxis()->SetTitle("t (s)");
	posizione1->GetYaxis()->SetTitle("x (m)");
	
	myCanvas.cd(2);
	posizione2->SetTitle("Pulsazione = 10 rad/s");
	posizione2->Draw("AL");
	posizione2->GetXaxis()->SetTitle("t (s)");
	posizione2->GetYaxis()->SetTitle("x (m)");
	
	myCanvas.cd(3);
	posizione3->SetTitle("Pulsazione = 15 rad/s");
	posizione3->Draw("AL");
	posizione3->GetXaxis()->SetTitle("t (s)");
	posizione3->GetYaxis()->SetTitle("x (m)");
	
	nstep = int (10/(alfa*h) + 0.5);
	x.SetComponent(0, 0.);
	x.SetComponent(1, 0.);
	int signum, i=0;
	
	for (double n = 9; n<=11; n = n + 0.05){
		t=0;
		OscillatoreArmonicoSmorzatoForzato *smorzo = new OscillatoreArmonicoSmorzatoForzato(omega0, n, alfa);
		
		for (int step = 0; step<nstep; step++){
			x = myRK.Passo(t,x, h, smorzo);
			t = t + h;
		}
		
		if (x.GetComponent(1)>0)
			signum = 1;
		else
			signum = -1;
		
		while (x.GetComponent(1)*signum>0){
			x = myRK.Passo(t,x, h, smorzo);
			t = t + h;
		}
		
		lorentz->SetPoint(i, n, abs(x.GetComponent(0)));
		i++;
	}
	
	TCanvas myCanvas2("c2", "c2");
	myCanvas2.cd();
	lorentz->SetTitle("Lorentziana");
	lorentz->Draw("AL*");
	lorentz->GetXaxis()->SetTitle("Pulsazione (rad/s)");
	lorentz->GetYaxis()->SetTitle("Ampiezza (m)");
	
	app.Run();
	
	

	return 0;
}
