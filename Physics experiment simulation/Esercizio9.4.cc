#include <iostream>
#include <iomanip>
#include <cmath>

#include "vettore.h"
#include "esperimento.h"

#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TApplication.h"

using namespace std;

int main (){
	
	TApplication app ("app", 0, 0);

	VettoreDati eta (1000);
	VettoreDati R (1000);
	VettoreDati t (1000);
	VettoreDati d (1000);

	VettoreDati eta2 (1000);
	VettoreDati R2 (1000);
	VettoreDati t2 (1000);
	VettoreDati d2 (1000);

	
	EsperimentoAttritoViscoso glicerina(0.005);
	EsperimentoAttritoViscoso glicerina2(0.01);

	for (unsigned int i=0; i<1000; i++){
		glicerina.Esegui();
		glicerina.Analizza();
		eta.SetComponent(i, glicerina.GetEtamisurato());
		R.SetComponent(i, glicerina.GetRmisurato());
		t.SetComponent(i, glicerina.GetTmisurato());
		d.SetComponent(i, glicerina.GetPos1misurato()-glicerina.GetPos0misurato());
	}

	for (unsigned int i=0; i<1000; i++){
		glicerina2.Esegui();
		glicerina2.Analizza();
		eta2.SetComponent(i, glicerina2.GetEtamisurato());
		R2.SetComponent(i, glicerina2.GetRmisurato());
		t2.SetComponent(i, glicerina2.GetTmisurato());
		d2.SetComponent(i, glicerina2.GetPos1misurato()-glicerina2.GetPos0misurato());
	}

	TCanvas * c1 = new TCanvas ("c1", "c1");
	c1->Divide(3,1);
	TH1F h_R("isto1", "Raggio della sfera (R = 0.005 m)", 100, R.Min(), R.Max());
	TH1F h_t("isto2", "Tempo di caduta (R = 0.005 m)", 100, t.Min(), t.Max());
	TH1F h_d("isto3", "Distanza percorsa (R = 0.005 m)", 100, d.Min(), d.Max());
	for (unsigned int i=0; i<1000; i++){
		double n_1 = R.GetComponent(i);
		double n_2 = t.GetComponent(i);
		double n_3 = d.GetComponent(i);
		h_R.Fill(n_1);
		h_t.Fill(n_2);
		h_d.Fill(n_3);
	}
	
	c1->cd(1);
	h_R.Draw();
	c1->cd(2);
	h_t.Draw();
	c1->cd(3);
	h_d.Draw();


	TCanvas * c2 = new TCanvas ("c2", "c2");
	c2->Divide(3,1);
	TH1F h_R2("isto4", "Raggio della sfera (R = 0.01 m)", 100, R2.Min(), R2.Max());
	TH1F h_t2("isto5", "Tempo di caduta (R = 0.01 m)", 100, t2.Min(), t2.Max());
	TH1F h_d2("isto6", "Distanza percorsa (R = 0.01 m)", 100, d2.Min(), d2.Max());
	for (unsigned int i=0; i<1000; i++){
		double n_1 = R2.GetComponent(i);
		double n_2 = t2.GetComponent(i);
		double n_3 = d2.GetComponent(i);
		h_R2.Fill(n_1);
		h_t2.Fill(n_2);
		h_d2.Fill(n_3);
	}
	
	c2->cd(1);
	h_R2.Draw();
	c2->cd(2);
	h_t2.Draw();
	c2->cd(3);
	h_d2.Draw();

	
	TCanvas * c3 = new TCanvas ("c3", "c3");
	TH1F h_eta("isto7", "Coefficiente di viscosita' (R = 0.005 m)", 100, eta.Min(), eta.Max());
	for (unsigned int i=0; i<1000; i++){
		double n_1 = eta.GetComponent(i);
		h_eta.Fill(n_1);
	}
	
	c3->cd();
	h_eta.Draw();


	TCanvas * c4 = new TCanvas ("c4", "c4");
	TH1F h_eta2("isto8", "Coefficiente di viscosita' (R = 0.01 m)", 100, eta2.Min(), eta2.Max());
	for (unsigned int i=0; i<1000; i++){
		double n_1 = eta2.GetComponent(i);
		h_eta2.Fill(n_1);
	}
	
	c4->cd();
	h_eta2.Draw();
	

	cout << endl << "Primo caso: R = 0.005 m" << endl;
	cout << "Coefficiente di viscosita': " << endl;
	cout << "L'errore relativo sul raggio e': " << R.Media()/R.DevStPop() << endl;
	cout << "L'errore relativo sul tempo e': " << t.Media()/t.DevStPop() << endl;
	cout << "L'errore relativo sulla distanza e': " << d.Media()/d.DevStPop() << endl;

	cout << endl <<"L'errore che influisce maggiormente sull'incertezza totale e'";
	if (R.Media()/R.DevStPop() > t.Media()/t.DevStPop() && R.Media()/R.DevStPop() > d.Media()/d.DevStPop())
		cout << " quello sul raggio: " << R.Media()/R.DevStPop();
	if (t.Media()/t.DevStPop() > R.Media()/R.DevStPop() && t.Media()/t.DevStPop() > d.Media()/d.DevStPop())
		cout << " quello sul tempo: " << t.Media()/t.DevStPop();
	if (d.Media()/d.DevStPop() > R.Media()/R.DevStPop() && d.Media()/d.DevStPop() > t.Media()/t.DevStPop())
		cout << " quello sulla distanza: " << d.Media()/d.DevStPop();

	cout << endl << endl << "Secondo caso: R = 0.01 m" << endl;
	cout << "L'errore relativo sul raggio e': " << R2.Media()/R2.DevStPop() << endl;
	cout << "L'errore relativo sul tempo e': " << t2.Media()/t2.DevStPop() << endl;
	cout << "L'errore relativo sulla distanza e': " << d2.Media()/d2.DevStPop() << endl;	
	
	cout << endl <<"L'errore che influisce maggiormente sull'incertezza totale e'";
	if (R2.Media()/R2.DevStPop() > t2.Media()/t2.DevStPop() && R2.Media()/R2.DevStPop() > d2.Media()/d2.DevStPop())
		cout << " quello sul raggio: " << R2.Media()/R2.DevStPop();
	if (t2.Media()/t2.DevStPop() > R2.Media()/R2.DevStPop() && t2.Media()/t2.DevStPop() > d2.Media()/d2.DevStPop())
		cout << " quello sul tempo: " << t2.Media()/t2.DevStPop();
	if (d2.Media()/d2.DevStPop() > R2.Media()/R2.DevStPop() && d2.Media()/d2.DevStPop() > t2.Media()/t2.DevStPop())
		cout << " quello sulla distanza: " << d2.Media()/d2.DevStPop();
	
	app.Run();

	return 0;
}
