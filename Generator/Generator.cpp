#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
#include <cstdlib>
#include <time.h>
#include "Generator.hpp"

using namespace std;

bool stringIsInt(char *str) {
	while(*str != 0) {
		if(isdigit(*str)) {
			++str;
		} else {
			return false;
		}
	}
	return true;
}

void checkParameters(int argc, char *argv[]) {
	assert(argc == 5);
	for (int i = 1; i < 4; ++i) {
		assert(stringIsInt(argv[i]));
	}
	assert(atoi(argv[1]) > 1);
	assert(atoi(argv[2]) > 0);
	assert(atoi(argv[2]) < atoi(argv[1]));
	assert(atoi(argv[3]) > (atoi(argv[2])-1));
	assert(atoi(argv[3]) < atoi(argv[1]));
}

void deleteTwoElements(int ind1, int ind2, int *size, int *table) {
	int i, j, ind;
	*size = *size - 2;
	if (ind1 < ind2) {
		i = ind1;
		j = ind2 - 1;
	} else {
		i = ind2;
		j = ind1 - 1;
	}
	for (ind = i; ind < j; ++ind) {
		table[ind] = table[ind+1];
	}
	for (ind = j; ind < *size; ++ind) {
		table[ind] = table[ind+2];
	}
}

void deleteElement(int ind, int *size, int *table) {
	*size = *size - 1;
	for (int i = ind; i < *size; ++i) {
		table[i] = table[i+1];
	}
}

void connect(int V1, int V2, int **graph) {
	int cardV;
	
	cardV = graph[V1][0];
	graph[V1][cardV+1] = V2;
	graph[V1][0] = cardV + 1;
	
	cardV = graph[V2][0];
	graph[V2][cardV+1] = V1;
	graph[V2][0] = cardV + 1;
}

bool areConnected(int V1, int V2, int **graph) {
	bool res;
	if (V1 != V2) {
		res = false;
		int Vi, Vj, card, ind;
		
		if (graph[V2][0] < graph[V1][0]) {
			card = graph[V2][0];
			Vi = V2;
			Vj = V1;
		} else {
			card = graph[V1][0];
			Vi = V1;
			Vj = V2;
		}
		
		ind = 1;
		while (!res && (ind <= card)) {
			res = (graph[Vi][ind] == Vj);
			++ind;
		}
	} else {
		res = true;
	}
	return res;
}

void generate(int card, int min, int max, char *fileName) {
	ofstream file(fileName, ios::out | ios::trunc);
	assert(file);
	//~ srand(5);
	srand(time(NULL));
	
	int ind, i, j, Vi, Vj, cpt, cardE;

	cardE = 0;
	/** The number of edges to add to a covering tree of the graph */
	int nbEdges = min + ((max-min)/4)*card;
	/** The table of the unconnected vertices */
	int *unconnected = new int [card];
	/** The number of unconnected vertices */
	int nbUnconnected = card;
	/** The table of the connected vertices */
	int *vertices = new int [card];
	/** The number of connected vertices */
	int nbVertices = 0;
	/** The graph
	 * let i be the vertex considered
	 * graph[i][0], the number of vertices connected to i
	 * graph[i][j], j > 0 a vertex connected to i
	 */
	int **graph = new int *[card];
	
	// We initialize the first table and the graph
	for (i = 0; i < card; ++i) {
		unconnected[i] = i;
		graph[i] = new int[card];
		graph[i][0] = 0;
	}
	
	// We create a first random covering tree
	i = rand() % (nbUnconnected-1);
	j = i + rand() % (nbUnconnected-i);
	if (i == j) {
		++j;
	}
	Vi = unconnected[i];
	Vj = unconnected[j];
	connect(Vi, Vj, graph);
	++cardE;
	deleteTwoElements(i, j, &nbUnconnected, unconnected);
	vertices[0] = Vi;
	vertices[1] = Vj;
	nbVertices = nbVertices + 2;
	
	while (nbUnconnected > 1) {
		i = rand() % nbUnconnected;
		j = rand() % nbVertices;
		Vi = unconnected[i];
		Vj = vertices[j];
		connect(Vi, Vj, graph);
		++cardE;
		deleteElement(i, &nbUnconnected, unconnected);
		if (graph[Vj][0] >= max) {
			deleteElement(j, &nbVertices, vertices);
		}
		vertices[nbVertices] = Vi;
		++nbVertices;
	}
	
	// If there is one vertex unconnected
	if (nbUnconnected == 1) {
		j = rand() % nbVertices;
		Vi = unconnected[0];
		Vj = vertices[j];
		connect(Vi, Vj, graph);
		++cardE;
		deleteElement(0, &nbUnconnected, unconnected);
		vertices[nbVertices] = Vi;
		++nbVertices;
		if (graph[Vj][0] >= max) {
			deleteElement(j, &nbVertices, vertices);
		}
	}
	
	// We connect vertices to reach the minimal cardinality on each
	i = 0;
	while (i < nbVertices) {
		Vi = vertices[i];
		while (graph[Vi][0] < min) {
			j = rand() % nbVertices;
			Vj = vertices[j];
			cpt = 0;
			while ((cpt < nbVertices) && areConnected(Vi, Vj, graph)) {
				++cpt;
				j = (j+1) % nbVertices;
				Vj = vertices[j];
			}
			if (cpt == nbVertices) {
				deleteElement(i, &nbVertices, vertices);
				Vi = vertices[i];
			} else {
				connect(Vi, Vj, graph);
				++cardE;
				--nbEdges;
				if (graph[Vj][0] >= max) {
					deleteElement(j, &nbVertices, vertices);
					if (i > j) {
						--i;
					}
				}
			}
		}
		++i;
	}
		
	// We add random vertices
	while ((nbVertices > 1) && (nbEdges > 0)) {
		i = rand() % nbVertices;
		j = rand() % nbVertices;
		Vi = vertices[i];
		Vj = vertices[j];
		cpt = 0;
		while (areConnected(Vi, Vj, graph) && (cpt < nbVertices)) {
			++cpt;
			j = (j+1) % nbVertices;
			Vj = vertices[j];
		}
		if (cpt == nbVertices) {
			deleteElement(i, &nbVertices, vertices);
		} else {
			connect(Vi, Vj, graph);
			++cardE;
			--nbEdges;
			if (graph[Vi][0] >= max) {
				deleteElement(i, &nbVertices, vertices);
			}
			if (graph[Vj][0] >= max) {
				deleteElement(j, &nbVertices, vertices);
			}
		}
	}
	
	int moy = 0;
	int minCard = max;
	int maxCard = 0;
	// We write in the file
	file << card << " " << cardE << endl;
	for (i = 0; i < card; ++i) {
		file << i << " ";
		moy = moy + graph[i][0];
		if (graph[i][0] < minCard) {
			minCard = graph[i][0];
		}
		if (graph[i][0] > maxCard) {
			maxCard = graph[i][0];
		}
		for (j = 0; j <= graph[i][0]; ++j) {
			file << graph[i][j] << " ";
		}
		file << endl;
	}
	
	cout << "moy=" << (double)moy/(double)card << endl;
	cout << "min=" << minCard << endl;
	cout << "max=" << maxCard << endl;
	file.close();
}

/* pour un grand écart de cardinalités, les cardinalités
 * min et max sont proches du min et du max réellement possibles
 */
int main(int argc, char *argv[]) {
	checkParameters(argc, argv);
	generate(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), argv[4]);
	cout << "done" << endl;	
	return 0;
}
