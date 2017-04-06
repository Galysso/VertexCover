#include <iostream>

#include "Graph/Graph.hpp"
#include "Algorithms/Algorithms.hpp"

using namespace std;

int main() {

	Graph g("../Instances/petitTestFelix");

	g.showGraph();

	bool *solution = new bool [g.getCardG()];
	//IPL_VC(g);
	//ARB_VC(g, solution);

	KERNEL_VC(g,5);

	cout << endl << "COCO" << endl << endl;

	return 0;
}
