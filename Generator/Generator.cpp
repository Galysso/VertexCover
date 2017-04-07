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
	assert(argc == 4);
	assert(stringIsInt(argv[1]));
	assert(atoi(argv[1]) > 1);
	assert(atoi(argv[2]) > -1);
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

void generate(int card, double prob, char *fileName) {
	ofstream file(fileName, ios::out | ios::trunc);
	assert(file);
	//~ srand(5);
	srand(time(NULL));
	
	int ind, i, j, Vi, Vj, cpt, cardE;
	double probTmp;

	cardE = 0;

	int **graph = new int * [card];

	for (i = 0; i < card; ++i) {
		graph[i] = new int [card+1];
		graph[i][0] = 0;
	}

	for (i = 0; i < card; ++i) {
		for (j = i+1; j < card; ++j) {
			probTmp = (((double)(rand()%1000))/1000.0);
			if (probTmp <= prob) {
				connect(i, j, graph);
				++cardE;
			}
		}
	}
	
	int moy = 0;
	int minCard = card;
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
	generate(atoi(argv[1]), atof(argv[2]), argv[3]);
	cout << "done" << endl;	
	return 0;
}
