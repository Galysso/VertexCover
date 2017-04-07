#include "Algorithms.hpp"
#include "Functions.hpp"

#include <glpk.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void KERNEL_VC(Graph &g,int k){
	int possible = 1;
	int korigine = k;
	int *VC1 = new int [g.getCardG()];
	for (int i = 0; i < g.getCardG(); ++i) {
		VC1[i] = 0;
	}

	//Etape 1 : application de VC1 et VC2 tant que c'est possible
	while(possible){
		possible = 0;
		for(int i = 0;i<g.getCardG();i++){
			//règle 1
			if(g.getCardV(i) == 1){
				VC1[g.getVertices(i)[0]]=1;
				printf("delete : %d\n",g.getVertices(i)[0]);
				g.deleteVertex(g.getVertices(i)[0]);
				possible = 1;
				k--;
			}
			//règle 2
			if(g.getCardV(i) >= k+1){
				VC1[i]=1;
				printf("delete : %d\n",i);
				g.deleteVertex(i);
				possible = 1;
				k--;
			}
		}
		printf("k = %d\n", k);
		possible = (k>0&&possible);
	}

	//Etape 2 : brute force sur ce qui reste
	int *VC2 = new int [g.getCardG()];
	int *VC3 = new int [g.getCardG()];
	for (int i = 0; i < g.getCardG(); ++i) {
		VC2[i] = 0;
		VC3[i] = 0;
	}
	int nb = 0;
	for(int i = 0;i<g.getCardG();i++){
		if(g.getCardV(i)>0)
			nb++;
	}
	printf("\nnb de sommets >0 : %d\n", nb);
	if(nb/2<k){
		printf("%d\n", korigine);
	}
	//on prend k sommets parmi n
	int kencours = k;
	for(int i = 0;i<g.getCardG();i++){
		if(VC1[i]==0&&kencours>0){//&&g.getCardV(i)>0)
			VC2[i] = 1;
			kencours--;
		}
	}

	next(g,VC1,VC2,VC3,k);
	next(g,VC1,VC2,VC3,k);
}


int ARB_VC(Graph &g){
	
}

void ARB_VC(Graph &g, bool *solution){
	int *vertices3 = new int [g.getCardG()];
	int nVertices = g.getCardG();
	for (int i = 0; i < nVertices; ++i) {
		vertices3[i] = i;
		solution[i] = false;
	}
	//int nSol = 0;

	retirerInf3(g, vertices3, nVertices);
	int *voisins;
	int nbVois;
	int u, vois;

	if (nVertices > 0) {
		u = vertices3[0];
		if (solution[u]) {
			g.deleteVertex(u);


			nbVois = g.getCardV(u);
			voisins = g.getVertices(u);
			for (int i = 0; i < nbVois; ++i) {
				vois = voisins[i];
				solution[vois] = true;
				g.deleteVertex(vois);
			}
		}
	}
}

void IPL_VC(Graph &g) {
	int *ia, *ja;
	double *ar;
	glp_prob *prob = glp_create_prob();
	glp_set_prob_name(prob, "deux_approx");
	glp_set_obj_dir(prob, GLP_MIN);
	glp_add_rows(prob, g.getNbEdges());
	glp_add_cols(prob, g.getCardG());

	int cptMax = g.getNbEdges()*2;

	ia = new int [cptMax+1];
	ja = new int [cptMax+1];
	ar = new double [cptMax+1];

	cout << "cptMax=" << cptMax << endl;

	int *vertices;
	int cardV;
	int v2;
	int cpt = 1;
	for (int v1 = 0; v1 < g.getCardG(); ++v1) {
		glp_set_obj_coef(prob, v1+1, 1);
		glp_set_col_bnds(prob, v1+1, GLP_DB, 0.0, 1.0);
		vertices = g.getVertices(v1);
		cardV = g.getCardV(v1);
		for (int indV2 = 0; indV2 < cardV; ++indV2) {
			v2 = vertices[indV2];
			if (v2 > v1) {
				ia[cpt] = cpt/2+1;
				ja[cpt]	= v1+1;
				ar[cpt] = 1.0;
				++cpt;

				ia[cpt] = cpt/2;
				ja[cpt] = v2+1;
				ar[cpt] = 1.0;

				++cpt;

				glp_set_row_bnds(prob, cpt/2, GLP_LO, 1.0, 1.0);
			}
		}
	}

	glp_load_matrix(prob, cptMax, ia, ja, ar);
	glp_write_lp(prob, NULL, "modelisation");
	glp_simplex(prob, NULL);
	glp_intopt(prob, NULL);

	double val;
	cout << "{";
	for (int v1 = 0; v1 < g.getCardG(); ++v1) {
		val = glp_mip_col_val(prob, v1+1);
		if (val >= 0.5 - 0.00001) {
			cout << v1 << ",";
		}
	}
	cout << "} (" << glp_mip_obj_val(prob) << ")" << endl;
}

void glouton_VC(Graph &g) {
	int v1, v2;
	int cardG = g.getCardG();
	int *vertices = new int [cardG];
	int cardV, best, cpt;

	cpt = 0;

	cout << "solution gloutonne : {";
	do {
		best = 0;
		for (int i = 0; i < cardG; ++i) {
			cardV = g.getCardV(i);
			vertices = g.getVertices(i);
			for (int j = 0; j < cardV; ++j) {
				if (cardV + g.getCardV(vertices[j]) > best) {
					v1 = i;
					v2 = vertices[j];
					best = cardV + g.getCardV(vertices[j]);
				}
			}
		}

		if (best > 0) {
			cpt += 2;
			g.deleteVertex(v1);
			g.deleteVertex(v2);
			cout << v1 << "," << v2 << ",";
			//cout << "d(" << v1 << ")+d(" << v2 << ")=" << best << endl << endl << endl << endl;
			//g.showGraph();
		}
	} while (best > 0);
	cout << "} (" << cpt << ")" << endl;
}
