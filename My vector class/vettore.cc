#include "vettore.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

Vettore::Vettore (){
	m_N = 0;
	m_v = NULL;
}

Vettore::Vettore (unsigned int N){
	m_N = N;
	m_v = new double [N];
	for (unsigned int i=0; i<N; i++) m_v[i]=0;
}

Vettore::~Vettore(){
	delete [] m_v;
}

void Vettore::SetComponent (unsigned int n, double a){
	if (n<m_N){
		m_v[n]=a;
	} else {
		cout << endl << "Errore: il vettore non ha la componente richiesta!!!" << endl << endl;
	}
}
double Vettore::GetComponent (unsigned int n) const{
	if (n<m_N){
		return m_v[n];
	} else {
		cout << endl << "Errore: il vettore non ha la componente richiesta!!!" << endl << endl;
		return -99999999;	
	}
}

Vettore::Vettore (const Vettore& V){
	m_N = V.m_N;
	m_v = new double [m_N];
	for (unsigned int i=0; i<m_N; i++) m_v[i]=V.m_v[i]; 
}

Vettore& Vettore::operator= (const Vettore& V){
	m_N=V.m_N;
	if (m_v) delete [] m_v;
	m_v = new double [m_N];
	for (unsigned int i=0; i<m_N; i++) m_v[i]=V.m_v[i];
	return *this;
}

VettoreDati::VettoreDati (unsigned int N, const char* filename){	
	m_N=N;
	m_v = new double [m_N];
	
	ifstream file_in;
	file_in.open(filename);
	
	if (!file_in){
		cerr << endl << "Errore apertura file!!!" << endl << endl;
	} else {
		for (unsigned int i=0; i<m_N; i++){
			file_in >> m_v[i];
			if (file_in.eof()){
				cerr << endl << "Terminato di leggere dopo " << i << " entrate " << endl << endl;
				break;
			}
		}
	}
	file_in.close();
}

VettoreDati::VettoreDati(unsigned int N) : Vettore(N){
	
}

void VettoreDati::Print (){
	int width = int(log10(m_N)+1);	
	
	for (unsigned int i=0; i<m_N; i++){
		cout << setw(width) << i << ") " << m_v[i] << endl;
	}
}

void VettoreDati::Print (const char* filename){
	int width = int(log10(m_N)+1);	
	
	ofstream file_out;
	file_out.open(filename);
	
	if (!file_out){
		cerr << endl << "Errore apertura file!!!" << endl << endl;
	} else {
		for (unsigned int i=0; i<m_N; i++){
			file_out << setw(width) << i << ") " << m_v[i] << endl; 
		}
	}
	file_out.close();
}

void VettoreDati::SelectionSort(){
  unsigned int i, j, min;
  double appo;
  for(i=0; i<m_N-1; i++){
	  min = i;
	  for(j=i+1; j<m_N; j++){
		  if(m_v[j] < m_v[min])
			  min=j;
	  }
	  appo=m_v[min];
	  m_v[min]=m_v[i];
	  m_v[i]=appo;
  }
}
void VettoreDati::Sort(){
	QuickSort(0, GetN()-1);
}
void VettoreDati::QuickSort (unsigned int primo, unsigned int ultimo){
	if (primo>ultimo || ultimo>=GetN()) return;
	if (ultimo-primo <= 1){
		if (GetComponent(primo)>GetComponent(ultimo)) Scambia (primo, ultimo);
		return;
	}
	double pivot = GetComponent((primo+ultimo)/2);
	unsigned int basso = primo, alto = ultimo;
	while(basso<alto){
		while(GetComponent(basso)<pivot) basso++;
		while (GetComponent(alto)>pivot) alto--;
		if (basso<alto){Scambia(basso, alto); basso++;}
	}
	QuickSort(primo, basso-1);
	QuickSort(basso, ultimo);
}
void VettoreDati::Scambia (unsigned int primo, unsigned int secondo){
	if (primo<GetN() || secondo<GetN()){
		double appo = GetComponent(primo);
		SetComponent(primo, GetComponent(secondo));
		SetComponent(secondo, appo);
	} else {
		cout << endl << "Errore: il vettore non ha le componenti richieste!!!" << endl << endl;
	}
}

double VettoreDati::Media (){
	double appo=0;
	for (unsigned int i=0; i<m_N; i++){
		appo+=m_v[i]/m_N;
	}
	return appo;
}

double VettoreDati::VarPop (){
	double appo=0;
	double media = this->Media();
	for (unsigned int i=0; i<m_N; i++){
		appo+=pow(media-m_v[i],2);
	}
	return appo/m_N;
}

double VettoreDati::VarCamp (){
	double appo=0;
	double media = this->Media();
	for (unsigned int i=0; i<m_N; i++){
		appo+=pow(media-m_v[i],2);
	}
	return appo/(m_N-1);
}

double VettoreDati::DevStCamp (){
	double appo = this->VarCamp();
	return sqrt(appo);
}

double VettoreDati::DevStPop (){
	double appo = this->VarPop();
	return sqrt(appo);
}

double VettoreDati::Mediana (){
	if (GetN()%2==1){
		int appo = int(GetN()/2);
		return GetComponent(appo);
	} else {
		int appo = int((GetN()-1)/2);
		return (GetComponent(appo)+GetComponent(appo+1))/2;
	}
}


























