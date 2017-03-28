#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>

using namespace std;

/*!
 * \class Graph
 * \author Jocelin C.
 * \brief
 */

class Graph {
	private:
		int _cardG;						// Le nombre de sommets
		int *_cardV;					// Le nombre d'arêtes pour le sommet i
		int **_vertices;				// Les sommets reliés au sommet i

	private:
		void bubbleSort();

	public:
		Graph(string fileName);			// Lit un fichier pour construire l'instance
		~Graph();
		bool areLinked(int v1, int v2);	// Vrai si les sommets i et j sont reliés
		int dichotomySearch(int i, int j);

		// DEBUG
		void showGraph();

};


#endif