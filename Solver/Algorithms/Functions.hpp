#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "../Graph/Graph.hpp"

void addVertexCoverFromPaths(Graph &g, bool *sol);

bool *copierSol(bool *s, int n);

void retirerInf3(Graph &g, int *vertices, int &size);

int isSolution(Graph &g, int* T);

int* next(int* VC1, int* VC3, int k,int n);

void afficher(int L[],int n);

int testnext(int L[],int VC1[],int n);

#endif
