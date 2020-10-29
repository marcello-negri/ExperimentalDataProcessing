#include "particella.h"

int main(){
	
	CorpoCeleste Terra = CorpoCeleste("Terra", 5.9742E24, 0,0,0);
	CorpoCeleste Sole =  CorpoCeleste("Sole", 1.989E30, 149.6E9,0,0);
	CorpoCeleste Luna =  CorpoCeleste("Luna", 7.342E22, 384.4E6,0,0);

	double PT = Terra.potenzialeGravitazionale(Luna);	
	double PS = Sole.potenzialeGravitazionale(Luna);
	
	cout<<endl<< "Potenziale gravitazionale della Terra sulla Luna = "<<PT<< endl;
	cout<< "Potenziale gravitazionale del Sole sulla Luna = "<<PS<<endl;
	cout<<endl;

	if (PS>PT) cout<<"E' maggiore il potenziale esercitato dal Sole"<<endl;
	else {
		if (PS<PT) cout<<"E' maggiore il potenziale esercitato dalla Terra"<<endl;
		else cout<<"Il potenziale esercitato dal Sole è uguale a quello esercitato dalla Terra"<<endl;
	}

	cout<<endl;

	return 0;
}
	
