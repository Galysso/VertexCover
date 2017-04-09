#include <iostream>

#include "Graph/Graph.hpp"
#include "Algorithms/Algorithms.hpp"

using namespace std;

int main() {
	for(int i=10; i < 100; i+=10) {
		string chemin = "../Instances/"+to_string(i)+"dlogn";

		Graph gExact(chemin);
		optimal(gExact);

		Graph gGlouton(chemin);
		glouton_VC(gGlouton);

		Graph gIpl(chemin);
		IPL_VC(gIpl);

		Graph gArb(chemin);
		ARB_VC(gArb,500);

		Graph gKernel(chemin);
		KERNEL_VC(gKernel,384);

		//cout << endl;
	}
	for(int i=100; i < 500; i+=20) {
		string chemin = "../Instances/"+to_string(i)+"dlogn";

		Graph gExact(chemin);
		optimal(gExact);

		Graph gGlouton(chemin);
		glouton_VC(gGlouton);

		Graph gIpl(chemin);
		IPL_VC(gIpl);

		Graph gArb(chemin);
		ARB_VC(gArb,500);

		Graph gKernel(chemin);
		KERNEL_VC(gKernel,384);

		//cout << endl;
	}
	for(int i=500; i<1000; i=i+50){
		string chemin = "../Instances/"+to_string(i)+"dlogn";

		Graph gExact(chemin);
		optimal(gExact);

		Graph gGlouton(chemin);
		glouton_VC(gGlouton);

		Graph gIpl(chemin);
		IPL_VC(gIpl);

		Graph gArb(chemin);
		ARB_VC(gArb,500);

		Graph gKernel(chemin);
		KERNEL_VC(gKernel,384);
	}

	return 0;
}
