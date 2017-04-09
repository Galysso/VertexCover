#include <iostream>

#include "Graph/Graph.hpp"
#include "Algorithms/Algorithms.hpp"

using namespace std;

int main() {
	for(int i=500;i<1000;i=i+50){
		string chemin = "../Instances/"+to_string(i)+"dlogn";

		Graph gGlouton(chemin);
		glouton_VC(gGlouton);

		Graph gKernel(chemin);
		KERNEL_VC(gKernel,384);
		//IPL_VC(g);
	}

	//bool *solution = new bool [g.getCardG()];
	//glouton_VC(g);
	//IPL_VC(g);
	//ARB_VC(g);
	//KERNEL_VC(g,5);

	//cout << endl << "COCO" << endl << endl;

	return 0;
}
