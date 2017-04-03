#include <iostream>

#include "Graph/Graph.hpp"
#include "Algorithms/Algorithms.hpp"

using namespace std;

int main() {

	Graph g("../Instances/jouetManuel11");

	g.showGraph();

	KERNEL_VC(g,5);
	//ARB_VC(g);
	//IPL_VC(g);

	cout << endl << "COCO" << endl << endl;

	return 0;
}
