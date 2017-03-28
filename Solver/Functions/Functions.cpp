#include "Functions.hpp"

#include <iostream>

using namespace std;

void bubbleSort(int *tab, int size) {
	bool sorted;
	int j;
	int tmp;

	do {
		sorted = true;
		for (j = 1; j < size; ++j) {
			if (tab[j-1] > tab[j]) {
				tmp = tab[j];
				tab[j] = tab[j-1];
				tab[j-1] = tmp;
				sorted = false;
			}
		}
		--size;
	} while (!sorted);
}

void bubbleSortVertices(int *v, int size) {
	bool sorted;
	int j;
	int tmp;
	bool btmp;

	do {
		sorted = true;
		for (j = 1; j < size; ++j) {
			if (v[j-1] > v[j]) {
				sorted = false;
				tmp = v[j];
				v[j] = v[j-1];
				v[j-1] = tmp;				
			}
		}
		--size;
	} while (!sorted);
}

int dichotomySearch(int *tab, int size, int val) {
	int ind;

	if ((val >= tab[0]) && (val <= tab[size-1])) {
		int lower, upper, indVal;
		lower = 0;
		upper = size;
		ind = upper/2;
		indVal = tab[ind];

		while ((upper > lower+1) && (indVal != val)) {
			if (indVal > val) {
				upper = ind;
			} else {
				lower = ind;
			}
			ind = lower + (upper-lower)/2;
			indVal = tab[ind];
		}

		if (indVal != val) {
			ind = -1;
		}
	} else {
		ind = -1;
	}

	return ind;
}