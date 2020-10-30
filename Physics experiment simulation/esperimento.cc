#include "esperimento.h"
#include <cmath>

EsperimentoAttritoViscoso::EsperimentoAttritoViscoso(double R):
	m_rho_0(1250),
	m_generatore(1),
	m_rho(2700),
	m_g(9.81),
	m_eta_input(0.83),
	m_sigma_t(0.01),
	m_sigma_R(0.0001),
	m_sigma_pos0(0.001),
	m_pos0_input(0.2),
	m_pos1_input(0.8)
{
	m_R_input = R;
	m_t_input = ((m_pos1_input - m_pos0_input)*9*m_eta_input)/(2*m_R_input*m_R_input*m_g*(m_rho-m_rho_0));
}

EsperimentoAttritoViscoso::~EsperimentoAttritoViscoso(){

}

void EsperimentoAttritoViscoso::Esegui(){
	m_t_misurato = m_generatore.Gauss(m_t_input, m_sigma_t);
	m_R_misurato = m_generatore.Gauss(m_R_input, m_sigma_R);
	m_pos0_misurato = m_generatore.Gauss(m_pos0_input, m_sigma_pos0);
	m_pos1_misurato = m_generatore.Gauss(m_pos1_input, m_sigma_pos0);
}

void EsperimentoAttritoViscoso::Analizza (){
	double d, v;
	d = m_pos1_misurato-m_pos0_misurato;
	v = d/(m_t_misurato);
	m_eta_misurato = (2*m_R_misurato*m_R_misurato*m_g*(m_rho-m_rho_0))/(9*v);
}
