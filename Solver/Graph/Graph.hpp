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
		int _cardG;							// Le nombre de sommets
		int _nbEdges;
		int *_cardV;						// Le nombre d'arêtes pour le sommet i
		int **_vertices;					// Les sommets reliés au sommet i

	private:
		void bubbleSort();
		int dichotomySearch(int i, int j);	// Indice du sommet j dans la liste des sommets de i

	public:
		Graph(string fileName);				// Lit un fichier pour construire l'instance
		Graph(const Graph &g);
		~Graph();
		bool areLinked(int v1, int v2);		// Vrai si les sommets i et j sont reliés
		int getCardG();						// Renvoie la cardinalité du graphe
		int getNbEdges();					// Renvoie le nombre d'arêtes dans le graphe
		int getCardV(int i);				// Renvoie la cardinalité du sommet i
		int *getVertices(int v);			// Renvoie la liste des sommets reliés au sommet v
		void deleteVertex(int v);			// Retire toutes les arêtes du graphe reliées au sommet v

		// DEBUG
		void showGraph();

};


#endif