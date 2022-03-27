#ifndef SCALE_TESTS_H
#define SCALE_TESTS_H


#include "includes.h"

void commun_cost(const int &network_size, const int &num_trans, std::ofstream &out);

void commun_cost_helper();


void stest(int num_nodes, int num_trans);


std::chrono::microseconds sev_memb(unsigned long num_trans);

std::chrono::microseconds eight_memb(int num_trans);

std::chrono::microseconds nine_memb(int num_trans);

void stest_3000();


void stest_helper();



#endif // !SCALE_TESTS_H

