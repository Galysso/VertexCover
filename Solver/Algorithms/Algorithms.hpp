#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "../Graph/Graph.hpp"

int optimal(Graph &g);

int glouton_VC(Graph &g);

int IPL_VC(Graph &g);

int ARB_VC(Graph &g, int k_max);

int ARB_VC_REC(Graph &g, bool *solution, bool &fini, int &k_max, int k, int &nSol);

int KERNEL_VC(Graph &g, int k);

#endif
