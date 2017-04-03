#include "Algorithms.hpp"

#include <glpk.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void KERNEL_VC(Graph &g){

}

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
	glp_simplex(prob, NULL);
	glp_write_lp(prob, NULL, "modelisation");

	double val;
	cout << "{";
	for (int v1 = 0; v1 < g.getCardG(); ++v1) {
		val = glp_mip_col_val(prob, v1+1);
		cout << val << ",";
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
