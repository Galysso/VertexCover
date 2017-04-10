#include <iostream>

#include "Graph/Graph.hpp"
#include "Algorithms/Algorithms.hpp"

using namespace std;

void affichageLatex() {
	cout.precision(3);
	clock_t debut, fin;
	int i = 10;
	int incr = 10;
	bool *booleens = new bool [24];
	for (int j = 0; j < 24; ++j) {
		booleens[j] = true;
	}

	while(i < 1000) {
		int j = 0;


		cout<<"\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|c|c|c|c|}";
		cout<<endl;
		cout<<"\\hline"<<endl;
		cout<<"\\multicolumn{4}{|c|}{} & \\multicolumn{3}{c|}{Kernel-VC}& \\multicolumn{3}{c|}{ARB-VC}& \\multicolumn{2}{c|}{Glouton-VC}& \\multicolumn{2}{c|}{IPL-VC} \\\\"<<endl;
  		cout<<"\\hline"<<endl;
		cout<<"$n="<<i<<"$ & $m$ & $\\Delta$ & $d_{moy}$ & Temps & Val & Nb Exec & Temps & Val & Nb Exec & Temps & Val & Temps & Val \\\\ \\hline" << endl;
		

		// P = 4/n
		string chemin = "../Instances/"+to_string(i)+"d4n";
		Graph gGlouton(chemin);
		Graph gIpl(gGlouton);
		Graph gArb(gGlouton);
		Graph gKernel(gGlouton);
		int m = gGlouton.getNbEdges();
		int delta = gGlouton.getDelta();
		double dMoy = gGlouton.getDeltaMoy();
		int sol;
		clock_t temps;

		cout<<"$p=4/n$ & "<<m<<" & "<<delta<<" & "<<dMoy<<" & ";
		// Kernel-VC
		if (booleens[j]) {
			debut=clock(); sol=KERNEL_VC(gKernel,500); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & "<<1<<" & ";
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & nan & ";
		}
		++j;
		//	ARB-VC
		if (booleens[j]) {
			debut=clock(); sol=ARB_VC(gArb,500); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & "<<1<<" & ";
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & nan & ";
		}
		++j;
		// Greedy-VC
		if (booleens[j]) {
			debut=clock(); sol=glouton_VC(gGlouton); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & ";
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & ";
		}
		++j;
		// IPL-VC
		if (booleens[j]) {
			debut=clock(); sol=IPL_VC(gIpl); fin=clock();
			temps = ((fin-debut))/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<< " \\\\ \\hline" << endl;
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & ";
		}
		++j;

		// P = 5/n
		chemin = "../Instances/"+to_string(i)+"d5n";
		gGlouton = Graph(chemin);
		gIpl = Graph(gGlouton);
		gArb = Graph(gGlouton);
		gKernel = Graph(gGlouton);
		m = gGlouton.getNbEdges();
		delta = gGlouton.getDelta();
		dMoy = gGlouton.getDeltaMoy();

		cout<<"$p=5/n$ & "<<m<<" & "<<delta<<" & "<<dMoy<<" & ";
		// Kernel-VC
		if (booleens[j]) {
			debut=clock(); sol=KERNEL_VC(gKernel,500); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & "<<1<<" & ";
			booleens[j] = temps < 0;
		} else {
			cout<<"$\\infty$ & nan & nan & ";
		}
		++j;
		//	ARB-VC
		if (booleens[j]) {
			debut=clock(); sol=ARB_VC(gArb,500); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & "<<1<<" & ";
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & nan & ";
		}
		++j;
		// Greedy-VC
		if (booleens[j]) {
			debut=clock(); sol=glouton_VC(gGlouton); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & ";
			booleens[j] = temps < 0;
		} else {
			cout<<"$\\infty$ & nan & ";
		}
		++j;
		// IPL-VC
		if (booleens[j]) {
			debut=clock(); sol=IPL_VC(gIpl); fin=clock();
			temps = ((fin-debut))/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<< " \\\\ \\hline" << endl;
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & ";
		}
		++j;


		// P = log(n)
		chemin = "../Instances/"+to_string(i)+"dlogn";
		gGlouton = Graph(chemin);
		gIpl = Graph(gGlouton);
		gArb = Graph(gGlouton);
		gKernel = Graph(gGlouton);
		m = gGlouton.getNbEdges();
		delta = gGlouton.getDelta();
		dMoy = gGlouton.getDeltaMoy();

		cout<<"$p=(log n)/n$ & "<<m<<" & "<<delta<<" & "<<dMoy<<" & ";
		// Kernel-VC
		if (booleens[j]) {
			debut=clock(); sol=KERNEL_VC(gKernel,500); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & "<<1<<" & ";
			booleens[j] = temps < 0;
		} else {
			cout<<"$\\infty$ & nan & nan & ";
		}
		++j;
		//	ARB-VC
		if (booleens[j]) {
			debut=clock(); sol=ARB_VC(gArb,500); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & "<<1<<" & ";
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & nan & ";
		}
		++j;
		// Greedy-VC
		if (booleens[j]) {
			debut=clock(); sol=glouton_VC(gGlouton); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & ";
			booleens[j] = temps < 0;
		} else {
			cout<<"$\\infty$ & nan & ";
		}
		++j;
		// IPL-VC
		if (booleens[j]) {
			debut=clock(); sol=IPL_VC(gIpl); fin=clock();
			temps = ((fin-debut))/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<< " \\\\ \\hline" << endl;
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan \\\\ \\hline" << endl;
		}
		++j;


		// P = 1/racine(n)
		chemin = "../Instances/"+to_string(i)+"drn";
		gGlouton = Graph(chemin);
		gIpl = Graph(gGlouton);
		gArb = Graph(gGlouton);
		gKernel = Graph(gGlouton);
		m = gGlouton.getNbEdges();
		delta = gGlouton.getDelta();
		dMoy = gGlouton.getDeltaMoy();

		cout<<"$p=1/\\sqrt n$ & "<<m<<" & "<<delta<<" & "<<dMoy<<" & ";
		// Kernel-VC
		if (booleens[j]) {
			debut=clock(); sol=KERNEL_VC(gKernel,500); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & "<<1<<" & ";
			booleens[j] = temps < 0;
		} else {
			cout<<"$\\infty$ & nan & nan & ";
		}
		++j;
		//	ARB-VC
		if (booleens[j]) {
			debut=clock(); sol=ARB_VC(gArb,500); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & "<<1<<" & ";
			booleens[j] = temps < 0;
		} else {
			cout<<"$\\infty$ & nan & nan & ";
		}
		++j;
		// Greedy-VC
		if (booleens[j]) {
			debut=clock(); sol=glouton_VC(gGlouton); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & ";
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & ";
		}
		++j;
		// IPL-VC
		if (booleens[j]) {
			debut=clock(); sol=IPL_VC(gIpl); fin=clock();
			temps = ((fin-debut))/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<< " \\\\ \\hline" << endl;
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan \\\\ \\hline" << endl;
		}
		++j;


		// P = 0.1
		chemin = "../Instances/"+to_string(i)+"d01";
		gGlouton = Graph(chemin);
		gIpl = Graph(gGlouton);
		gArb = Graph(gGlouton);
		gKernel = Graph(gGlouton);
		m = gGlouton.getNbEdges();
		delta = gGlouton.getDelta();
		dMoy = gGlouton.getDeltaMoy();

		cout<<"$p=0.1$ & "<<m<<" & "<<delta<<" & "<<dMoy<<" & ";
		// Kernel-VC
		if (booleens[j]) {
			debut=clock(); sol=KERNEL_VC(gKernel,500); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & "<<1<<" & ";
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & nan & ";
		}
		++j;
		//	ARB-VC
		if (booleens[j]) {
			debut=clock(); sol=ARB_VC(gArb,500); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & "<<1<<" & ";
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & nan & ";
		}
		++j;
		// Greedy-VC
		if (booleens[j]) {
			debut=clock(); sol=glouton_VC(gGlouton); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & ";
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & ";
		}
		++j;
		// IPL-VC
		if (booleens[j]) {
			debut=clock(); sol=IPL_VC(gIpl); fin=clock();
			temps = ((fin-debut))/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<< " \\\\ \\hline" << endl;
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan \\\\ \\hline" << endl;
		}
		++j;


		// P = 0.2
		chemin = "../Instances/"+to_string(i)+"d02";
		gGlouton = Graph(chemin);
		gIpl = Graph(gGlouton);
		gArb = Graph(gGlouton);
		gKernel = Graph(gGlouton);
		m = gGlouton.getNbEdges();
		delta = gGlouton.getDelta();
		dMoy = gGlouton.getDeltaMoy();

		cout<<"$p=0.2$ & "<<m<<" & "<<delta<<" & "<<dMoy<<" & ";
		// Kernel-VC
		if (booleens[j]) {
			debut=clock(); sol=KERNEL_VC(gKernel,500); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & "<<1<<" & ";
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & nan & ";
		}
		++j;
		//	ARB-VC
		if (booleens[j]) {
			debut=clock(); sol=ARB_VC(gArb,500); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & "<<1<<" & ";
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & nan & ";
		}
		++j;
		// Greedy-VC
		if (booleens[j]) {
			debut=clock(); sol=glouton_VC(gGlouton); fin=clock();
			temps = (fin-debut)/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<<" & ";
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan & ";
		}
		++j;
		// IPL-VC
		if (booleens[j]) {
			debut=clock(); sol=IPL_VC(gIpl); fin=clock();
			temps = ((fin-debut))/CLOCKS_PER_SEC;
			cout<<temps<<" & "<<sol<< " \\\\ \\hline" << endl;
			booleens[j] = temps < 1;
		} else {
			cout<<"$\\infty$ & nan \\\\ \\hline" << endl;
		}

		i += incr;
		if (i == 100) {
			incr = 20;
		} else if (i == 500) {
			incr = 50;
		}

		cout<<"\\end{tabular}" << endl << endl;
	}
}

void affichageUtilisateur() {
	clock_t debut, fin;
	int i = 10;
	int incr = 10;

	while(i < 1000) {
		string chemin = "../Instances/"+to_string(i)+"d4n";
		Graph gGlouton(chemin);
		Graph gIpl(chemin);
		Graph gArb(chemin);
		Graph gKernel(chemin);

		cout << " | Kernel-VC | ARB-VC | Greedy-VC | IPL-VC" << endl;
		cout << "n = " << i << "\t||m\tdelta\tdmoy\t|Temps" << endl;
	




		i += incr;
		if (i == 100) {
			incr = 20;
		} else if (i == 500) {
			incr = 50;
		}
	}
}

int main() {

	affichageLatex();

	/*for(int i=10; i < 100; i+=10) {
		string chemin = "../Instances/"+to_string(i)+"dlogn";

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

		Graph gGlouton(chemin);
		glouton_VC(gGlouton);

		Graph gIpl(chemin);
		IPL_VC(gIpl);

		Graph gArb(chemin);
		ARB_VC(gArb,500);

		Graph gKernel(chemin);
		KERNEL_VC(gKernel,384);
	}*/

	return 0;
}
