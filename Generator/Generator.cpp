#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
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

void generate(int card, double prob, const char *fileName) {
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
			cout<<probTmp<<"   "<<prob<<endl;
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
	cout << "max=" << maxCard << endl <<endl;
	file.close();
}

void generateAll(){

	/*for(int i = 10;i<100;i=i+10){
		string nom="../Instances/", nom4n = "d4n", nom5n="d5n", nomlogn="dlogn", nomrn="drn", nom01="d01",nom02="d02";
		nom = nom+to_string(i);

		nom4n = nom+nom4n;
		nom5n = nom+nom5n;
		nomlogn = nom+nomlogn;
		nomrn = nom+nomrn;
		nom01 = nom+nom01;
		nom02 = nom+nom02;

		generate(i,4/i,nom4n.c_str());
		generate(i,5/i,nom5n.c_str());
		generate(i,log(i)/i,nomlogn.c_str());
		generate(i,1/sqrt(i),nomrn.c_str());
		generate(i,0.1,nom01.c_str());
		generate(i,0.2,nom02.c_str());
	}
	for(int i = 100;i<500;i=i+20){
		string nom="../Instances/", nom4n = "d4n", nom5n="d5n", nomlogn="dlogn", nomrn="drn", nom01="d01",nom02="d02";
		nom = nom+to_string(i);

		nom4n = nom+nom4n;
		nom5n = nom+nom5n;
		nomlogn = nom+nomlogn;
		nomrn = nom+nomrn;
		nom01 = nom+nom01;
		nom02 = nom+nom02;

		generate(i,4/i,nom4n.c_str());
		generate(i,5/i,nom5n.c_str());
		generate(i,log(i)/i,nomlogn.c_str());
		generate(i,1/sqrt(i),nomrn.c_str());
		generate(i,0.1,nom01.c_str());
		generate(i,0.2,nom02.c_str());
	}*/
	for(int i = 500;i<1000;i=i+50){
		string nom="../Instances/", nom4n = "d4n", nom5n="d5n", nomlogn="dlogn", nomrn="drn", nom01="d01",nom02="d02";
		nom = nom+to_string(i);

		nom4n = nom+nom4n;
		nom5n = nom+nom5n;
		nomlogn = nom+nomlogn;
		nomrn = nom+nomrn;
		nom01 = nom+nom01;
		nom02 = nom+nom02;

		generate(i,4/i,nom4n.c_str());
		generate(i,5/i,nom5n.c_str());
		generate(i,log(i)/i,nomlogn.c_str());
		generate(i,1/sqrt(i),nomrn.c_str());
		generate(i,0.1,nom01.c_str());
		generate(i,0.2,nom02.c_str());
	}
}


/* pour un grand écart de cardinalités, les cardinalités
 * min et max sont proches du min et du max réellement possibles
 */
int main(int argc, char *argv[]) {
	//checkParameters(argc, argv);
	//generate(atoi(argv[1]), atof(argv[2]), argv[3]);
	generateAll();
	cout << "done" << endl;
	return 0;
}
