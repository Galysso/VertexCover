#include <iostream>

#include "Graph/Graph.hpp"
#include "Algorithms/Algorithms.hpp"

using namespace std;

int main() {

	Graph g("../Instances/petitTest10");

	g.showGraph();

	bool *solution = new bool [g.getCardG()];
	//glouton_VC(g);
	//IPL_VC(g);
	ARB_VC(g);
	//KERNEL_VC(g,5);

	//cout << endl << "COCO" << endl << endl;

	return 0;
}
