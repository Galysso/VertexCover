#include <iostream>

#include "Graph/Graph.hpp"

using namespace std;

int main() {

	Graph g("../Instances/test10");

	g.showGraph();


	int v1 = 3;
	int v2 = 2;
	cout << v1 << " et " << v2 << " ? " << g.areLinked(v1,v2) << endl;

	cout << endl << "COCO" << endl << endl;

	return 0;
}