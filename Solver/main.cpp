#include <iostream>

#include "Graph/Graph.hpp"
#include "Algorithms/Algorithms.hpp"

using namespace std;

int main() {

	Graph g("../Instances/petitTest10");

	g.showGraph();

	bool *solution = new bool [g.getCardG()];	
	ARB_VC(g);

	cout << endl << "COCO" << endl << endl;

	return 0;
}