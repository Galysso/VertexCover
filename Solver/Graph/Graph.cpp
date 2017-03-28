#include "Graph.hpp"

#include "../Functions/Functions.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

Graph::Graph(string fileName) {
	srand(5);
	ifstream f(fileName.c_str());

	if (f) {
		int i, j;
		int tmp, vi, vj, cardG, cardV;
		f >> cardG;
		f >> tmp;	// On utilise pas encore le nombre d'arêtes

		_cardG = cardG;
		_cardV = new int [cardG];
		_vertices = new int * [cardG];

		for (i = 0; i < cardG; ++i) {
			f >> vi;					// the first column corresponds to vi and corresponds to i
			f >> cardV;
			_cardV[i] = cardV;
			_vertices[i] = new int [cardV];

			for (j = 0; j < cardV; ++j) {
				f >> vj;
				_vertices[i][j] = vj;
			}
			bubbleSortVertices(_vertices[i], cardV);
		}

		f.close();
	} else {
		cout << "Fichier inexistant" << endl;
	}
}

Graph::~Graph() {}

bool Graph::areLinked(int v1, int v2) {
	bool res;

	if (_cardV[v1] < _cardV[v2]) {
		res = (dichotomySearch(_vertices[v1], _cardV[v1], v2) != -1);
	} else {
		res = (dichotomySearch(_vertices[v2], _cardV[v2], v1) != -1);
	}

	return res;
}

void Graph::showGraph() {
	cout << "|G|=" << _cardG << endl << endl;

	for (int i = 0; i < _cardG; ++i) {
		cout << i << " (" << _cardV[i] << "): ";
		for (int j = 0; j < _cardV[i]; ++j) {
			cout << _vertices[i][j] << " ";
		}
		cout << endl << endl;
	}
}