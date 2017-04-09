#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "../Graph/Graph.hpp"

void glouton_VC(Graph &g);

void IPL_VC(Graph &g);

void ARB_VC(Graph &g, int k_max);

void ARB_VC_REC(Graph &g, bool *solution, bool &fini, int &k_max, int k);

void KERNEL_VC(Graph &g, int k);

#endif
