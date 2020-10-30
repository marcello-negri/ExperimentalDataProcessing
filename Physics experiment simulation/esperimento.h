#ifndef _ESPERIMENTO_H_
#define _ESPERIMENTO_H_
#include "random.h"

class EsperimentoAttritoViscoso{
	public:
		EsperimentoAttritoViscoso(double R);
		~EsperimentoAttritoViscoso();
		void Esegui();
		void Analizza ();
		double GetRho (){return m_rho;};
		double GetRho_0 (){return m_rho_0;};
		double GetRinput (){return m_R_input;};
		double GetRmisurato (){return m_R_misurato;};
		double Getg (){return m_g;};
		double GetTinput (){return m_t_input;};
		double GetTmisurato (){return m_t_misurato;};
		double GetEtainput (){return m_eta_input;};
		double GetEtamisurato (){return m_eta_misurato;};
		double GetPos0input (){return m_pos0_input;};
		double GetPos0misurato (){return m_pos0_misurato;};
		double GetPos1input (){return m_pos1_input;};
		double GetPos1misurato (){return m_pos1_misurato;};

	private:
		Random m_generatore;
		double m_rho, m_rho_0, m_g, m_sigma_t, m_sigma_R, m_sigma_pos0;
		double m_t_input, m_t_misurato;
		double m_eta_input, m_eta_misurato;
		double m_pos0_input, m_pos0_misurato;
		double m_pos1_input, m_pos1_misurato;
		double m_R_input, m_R_misurato;
};
#endif
