#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "../Graph/Graph.hpp"

void glouton_VC(Graph &g);

void IPL_VC(Graph &g);

void ARB_VC(Graph &g);

void ARB_VC(Graph &g, bool *solution, bool &fini);

void KERNEL_VC(Graph &g, int k);

#endif
