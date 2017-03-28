/*!
 * \file Generator.hpp
 * \author Jocelin C.
 * \brief Generate a connected graph G=(V,E)\n
 * 			Exemple of data format\n
 * 			Vi is the vertex indexes, VCij is the indexes of vertices connected to Vi :\n
 * 				|V|\n
 * 				V0 |V0| VC00 VC01 VC02 VC03\n
 * 				V1 |V1| VC10 VC11 VC12 VC13 VC14 VC15\n
 * 				V2 |V2| VC20\n
 * 				V3 |V3| VC30 VC31\n
 * 				V4 |V4| VC40 VC41 VC42\n
 * 
 * \param 1 (card)	: graph cardinality, |V| (card > 1)
 * \param 2 (min)	: minimum degree of vertices ((min > 0) AND (min < card))
 * \param 3 (max)	: maximum degree of vertices ((max > min-1) AND (min < card))
 * \param 4 (file)	: name of the generated file
 */

#ifndef GENERATOR_HPP
#define GENERATOR_HPP

/*!
 * \brief Check if the string is an integer
 * \param string the string to check
 * \return true if the string is an integer, false otherwise
 */
bool stringIsInt(char *string);

/*!
 * \brief check the given parameters when the program is executed
 */
void checkParameters(int argc, char *argv[]);

/*!
 * \brief Delete the element of a table at the given position and shift the table
 * \param ind the index of the element to delete
 * \param size the size of the table
 * \param table the table
 */
void deleteElement(int ind, int *size, int *table);

/*!
 * \brief Delete two elements of a table at the given positions and shift the table
 * \param ind1 the index of the first element to delete
 * \param ind2 the index of the second element to delete
 * \param size the size of the table
 * \param table the table
 */
void deleteTwoElements(int ind1, int ind2, int *size, int *table);

/*!
 * \brief Connect two vertices in the graph
 * \param V1 the first vertex to connect
 * \param V2 the second vertex to connect
 * \param graph the graph
 */
void connect(int V1, int V2, int **graph);

/*!
 * \brief Check if two vertices are connected
 * \param V1 the first vertex
 * \param V2 the seconde vertex
 * \param graph the graph
 * \return true if V1 and V2 are connected in the given graph, false otherwise
 */
bool areConnected(int V1, int V2, int **graph);

/*!
 * \brief Generate the graph and write it in the choosen file
 * \param card the cardinality of the graph
 * \param min the minimum cardinality of the vertices
 * \param max the maximum cardinality of the vertices (it can be violated sometimes)
 * \param filename the file in which the instance is written
 */
void generate(int card, int min, int max, char *fileName);

#endif //GENERATOR_HPP
