#ifndef _RANDOM_H_
#define _RANDOM_H_

class Random {
	public:
		Random(int seed);
		void SetA (int A){m_a=A;};
		void SetC (int C){m_c=C;};
		void SetM (int M){m_m=M;};
		void SetSeed (int seed) {m_seed=seed;};
	
		double Rand();
		double RandGauss(double mean, double sigma);
		double Gauss(double mean, double sigma);
		double Exp(double rate);

	private:
		unsigned int m_a;
		unsigned int m_c;
		unsigned int m_m;
		unsigned int m_seed; 
};

#endif
