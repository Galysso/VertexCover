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
		int _cardG;
		int *_cardV;
		int **_vertices;

	public:
		Graph(string fileName);
		~Graph();
		bool areLinked(int v1, int v2);

		// DEBUG
		void showGraph();

};


#endif