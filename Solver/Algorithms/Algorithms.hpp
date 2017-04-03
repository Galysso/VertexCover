#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "../Graph/Graph.hpp"

void retirerInf3(Graph &g,bool *vertices);

void glouton_VC(Graph &g);

void IPL_VC(Graph &g);

void ARB_VC(Graph &g, int *solution, int &nSol);

void KERNEL_VC(Graph &g);

#endif
