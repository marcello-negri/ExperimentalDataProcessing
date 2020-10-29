#include "vettore.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <cmath>

using namespace std;

int main (){

	VettoreDati vector (30, "random_data.txt");
	double appo = vector.Mediana();
	double appo1 = vector.Media();
	double appo2 = vector.VarCamp();
	double appo3 = vector.VarPop();
	double appo4 = vector.DevStCamp();
	double appo5 = vector.DevStPop();
	cout << fixed << setprecision(8) << endl << "La mediana vale " << appo << endl << endl;
	cout << fixed << setprecision(8) << endl << "La media vale " << appo1 << endl << endl;
	cout << fixed << setprecision(8) << endl << "La varianza camp vale " << appo2 << endl << endl;
	cout << fixed << setprecision(8) << endl << "La varianza pop vale " << appo3 << endl << endl;
	cout << fixed << setprecision(8) << endl << "La deviazione standard camp vale " << appo4 << endl << endl;
	cout << fixed << setprecision(8) << endl << "La deviazione standard pop vale " << appo5 << endl << endl;
	return 0;
}
