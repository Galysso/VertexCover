#include "Functions.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

bool *copierSol(bool *s, int n) {
	bool *res = new bool [n];
	for (int i = 0; i < n; ++i) {
		res[i] = s[i];
	}
	return res;
}

void retirerInf3(Graph &g, int *vertices, int &size) {
	int decal = 0;
	int v;
	for (int i = 0; i < size; ++i) {
		v = vertices[i+decal];
		vertices[i] = v;
		if (g.getCardV(vertices[i]) < 3) {
			++decal;
			vertices[i] = vertices[i+decal];
			--i;
			--size;
		}
	}
}

int isSolution(Graph &g, int* T){
	//pour chaque sommet, si deg>0 ou il est dans le VC, ou tous ses voisins y sont
	for(int i = 0;i<g.getCardG();i++){
		if(T[i]!=1){
			for(int j=0;j<g.getCardV(i);j++){
				if(T[g.getVertices(i)[j]]!=1){
					//printf("\npas de solution\n");
					return 0;
				}
			}
		}
	}
	//printf("SOLUTIONNNN\n");
	return 1;
}

int* next(int* VC1, int* L, int k,int n){
	int bouge = 0, loc = 0, pdernier=-1;

	while(!bouge && loc!=-1){
			loc = -1;
			for(int i=0;i<n;i++){
				if(L[i]==1&&VC1[i]!=1){
					loc = i;
					//cout<<i<<endl;
				}
			}
			if(loc!=-1 && loc!=n-1 && loc+1!=pdernier){//il peut bouger
				L[loc]=0;
				loc++;
				while(VC1[loc]==1)
					loc++;
				L[loc]=1;
				bouge=1;
			}
			else{
				L[loc]=0;
				pdernier=loc;
			}
		}
		int compte=0;
		for(int i=0;i<n;i++){
			if(L[i]==1)
				compte++;
		}
		while(compte<k){
			loc++;
			if(VC1[loc]!=1){
				L[loc]=1;
				compte++;
			}
		}
		return L;
}

void afficher(int L[],int n){
	for(int i=0;i<n;i++)
		cout<<L[i]<<" ";
	cout<<endl;
}

int testnext(int L[],int VC1[], int n){
  //test de peut bouger = reste des 0 à la fin
  int test1 = 0, test0 = 0;
  for(int i=0;i<n;i++){
    if(L[i]==1&&VC1[i]!=1)
      test1 = 1;
    if(test1&&L[i]==0)
      test0 = 1;
  }
  if(!test0){
    cout<<"toutes les possibilités ont été testées, pas de solution"<<endl;
    return 0;
  }
  return 1;
}
