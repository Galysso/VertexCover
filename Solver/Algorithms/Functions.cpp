#include "Functions.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void retirerInf3(Graph &g, int *vertices, int &size) {
	int decal = 0;
	int v;
	for (int i = 0; i < size; ++i) {
		v = vertices[i+decal];
		vertices[i] = v;
		if (g.getCardV(vertices[i]) < 3) {
			++decal;
			vertices[i] = vertices[i+decal];
			--i;
			--size;
		}
	}
}

int isSolution(Graph &g, int* T){
	//pour chaque sommet, si deg>0 ou il est dans le VC, ou tous ses voisins y sont
	for(int i = 0;i<g.getCardG();i++){
		if(T[i]!=1){
			for(int j=0;j<g.getCardV(i);j++){
				if(T[g.getVertices(i)[j]]!=1){
					printf("\npas bon\n");
					return 0;
				}
			}
		}
	}
	return 1;
}

void next(Graph &g, int* VC1, int* VC2, int* VC3, int k){
	//on calcule le next
	//CA MENERVEUHHH

	//on vérifie la solution trouvée
	for(int i = 0;i<g.getCardG();i++){
		VC3[i] = VC1[i]||VC2[i];
		printf("%4d",VC3[i]);
	}

	printf("\n%d\n", isSolution(g,VC3));
}
