#ifndef _VETTORE_H_
#define _VETTORE_H_


class Vettore {
	public:
		Vettore ();
		Vettore (unsigned int N);
		~Vettore();
	
		Vettore (const Vettore& V);		
		Vettore& operator= (const Vettore&);		
		
		unsigned int GetN() const {return m_N;};
		void SetComponent (unsigned int, double);
		double GetComponent (unsigned int) const;
		
	protected:
		unsigned int m_N;
		double* m_v;
};


class VettoreDati: public Vettore {
	public:
		VettoreDati (unsigned int N);
		VettoreDati (unsigned int N, const char* filename);
		void Print ();
		void Print (const char* filename);
		void SelectionSort();
		void Sort();
		double Media ();
		double VarPop ();
		double VarCamp ();
		double DevStPop ();
		double DevStCamp ();
		double Mediana ();
	private:
		void Scambia (unsigned int primo, unsigned int secondo);
		void QuickSort (unsigned int primo, unsigned int secondo);
};


#endif
