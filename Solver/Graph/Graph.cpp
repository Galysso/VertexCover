#include "Graph.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>

using namespace std;



Graph::Graph(string fileName) {
	ifstream f(fileName.c_str());

	if (f) {
		int i, j;
		int tmp, vi, vj, cardG, cardV;
		f >> cardG;
		f >> _nbEdges;	// On utilise pas encore le nombre d'arêtes

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
		}

		bubbleSort();

		f.close();
	} else {
		cout << "Fichier inexistant" << endl;
	}
}

Graph::Graph(const Graph &g) {
	int cardV;

	_cardG = g._cardG;
	_cardV = new int [_cardG];
	_vertices = new int * [_cardG];
	for (int i = 0; i < _cardG; ++i) {
		cardV = g._cardV[i];
		_cardV[i] = cardV;
		_vertices[i] = new int [cardV];
		for (int j = 0; j < cardV; ++j) {
			_vertices[i][j] = g._vertices[i][j];
		}
	}
}

Graph::~Graph() {}

void Graph::bubbleSort() {
	bool sorted;
	int tmp;
	int size, nextSize;

	for (int i = 0; i < _cardG; ++i) {
		size = _cardV[i];
		do {
			sorted = true;
			for (int j = 1; j < size; ++j) {
				if (_vertices[i][j-1] > _vertices[i][j]) {
					sorted = false;
					tmp = _vertices[i][j];
					_vertices[i][j] = _vertices[i][j-1];
					_vertices[i][j-1] = tmp;
					nextSize = j;
				}
			}
			size = nextSize;
		} while (!sorted);
	}
}

int Graph::dichotomySearch(int i, int j) {
	assert(i >= 0);
	assert(j >= 0);
	assert(i < _cardG);
	assert(j < _cardG);

	int ind, size, tmp;
	int *tabV;

	size = _cardV[i];
	tabV = _vertices[i];

	if ((j >= tabV[0]) && (j <= tabV[size-1])) {
		int lower, upper, indVal;
		lower = 0;
		upper = size;
		ind = upper/2;
		indVal = tabV[ind];

		while ((upper > lower+1) && (indVal != j)) {
			if (indVal > j) {
				upper = ind;
			} else {
				lower = ind;
			}
			ind = lower + (upper-lower)/2;
			indVal = tabV[ind];
		}

		if (indVal != j) {
			ind = -1;
		}
	} else {
		ind = -1;
	}

	return ind;
}

bool Graph::areLinked(int v1, int v2) {
	bool res;

	if (_cardV[v1] < _cardV[v2]) {
		res = (dichotomySearch(v2, v1) != -1);
	} else {
		res = (dichotomySearch(v1, v2) != -1);
	}

	return res;
}

int Graph::getCardG() {
	return _cardG;
}

int Graph::getNbEdges() {
	return _nbEdges;
}

int Graph::getCardV(int i) {
	return _cardV[i];
}

int *Graph::getVertices (int v) {
	return _vertices[v];
}

void Graph::deleteVertex(int v) {
	int cardV = _cardV[v];
	int v2, indV, cardV2;

	for (int i = 0; i < cardV; ++i) {
		v2 = _vertices[v][i];
		cardV2 = _cardV[v2];
		indV = dichotomySearch(v2, v);
		for (indV = indV+1; indV < cardV2; ++indV) {
			_vertices[v2][indV-1] = _vertices[v2][indV];
		}
		_cardV[v2] = cardV2-1;
	}
	_cardV[v] = 0;
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
