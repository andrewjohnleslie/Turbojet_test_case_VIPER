//
// Created by Andrew on 20/02/2023.
//
#include <cmath>
#include "compressor.h"

#ifndef TEST_CASES_TURBINE_H
#define TEST_CASES_TURBINE_H

double e_t = 0.85;
double mdot_a = 23.81;
double mdot_f = 0.4267;
double mdot_tot = mdot_a + mdot_f;
double LCV = 43100000;

auto m_norm_ge = (gamma_e / pow((gamma_e - 1), 0.5)) * pow(((gamma_e + 1) / 2), ((-1 * (gamma_e + 1)) / (2 * (gamma_e - 1))));

double energy_rel = mdot_f * LCV;
// double sp_energy_rel = energy_rel/mdot_a                             [per kg of air-flow]

double T_04 = ((energy_rel + (mdot_a * cp * (T_03 - 298))) / ((mdot_a + mdot_f) * cpe)) + 298;
double P_04 = P_03;                          // Pressure loss in the combustor is neglected: P_04 = (1 - delP_c) * P_03

double T_05 = T_04 - DelT_t;
double P_05 = P_04 * pow((T_05/T_04), (gamma_e / (e_t * (gamma_e-1))));

double A_nozz_t =  ((mdot_tot * pow((cpe * T_04), 0.5)) / (P_04 * m_norm_ge));

double Pcrit = P_04 / pow(((gamma_e + 1)/2), ((gamma_e)/(gamma_e - 1)));
double choke_t = P_04/Pcrit;


#endif //TEST_CASES_TURBINE_H
