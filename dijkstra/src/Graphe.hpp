//
//  Graphe.hpp
//  métroparis
//
//  Created by Mario Marchand on 2015-03-06.
//  Copyright (c) 2015 Mario Marchand. All rights reserved.
//

#include "Graphe.h"
#include <vector>
#include "ContratException.h"
#include <iostream>

const int INFINITY = -1;


template<typename T>
Graphe<T>::Graphe(){}

template<typename T>
Graphe<T>::~Graphe(){}

template<typename T>
void Graphe<T>::ajouteSommet(const T& sommet){
	m_sommets.push_back(sommet);

	std::vector<int> vec = std::vector<int>(m_matriceAdj.size());
	for(unsigned int i = 0 ; i < vec.size() ; i++){
		vec[i] = -1;
	}
	m_matriceAdj.push_back(vec);
	for(unsigned int i = 0; i < m_matriceAdj.size() ; i++){
		m_matriceAdj[i].push_back(INFINITY);
	}
}

template<typename T>
void Graphe<T>::ajouteArete(int noSommetDepart, int noSommetArrivee, int poids){
	PRECONDITION((unsigned)noSommetDepart < m_sommets.size());
	PRECONDITION((unsigned)noSommetArrivee < m_matriceAdj[noSommetDepart].size());
	PRECONDITION(poids > 0);

	m_matriceAdj[noSommetDepart][noSommetArrivee] = poids;
}

template<typename T>
int Graphe<T>::reqTaille() const{
	return m_sommets.size();
}

template<typename T>
const T& Graphe<T>::operator[](int i) const{
	return m_sommets[i];
}

template<typename T>
bool Graphe<T>::ComparerPlusPetit(int a, int b){
	if(a == INFINITY){
		return false;
	}
	else if(b == INFINITY){
		return true;
	}
	else{
		return a < b;
	}
}

template<typename T>
int Graphe<T>::min(int a, int b){
	if(ComparerPlusPetit(a,b)){
		return a;
	}
	else{
		return b;
	}
}

template<typename T>
int Graphe<T>::dijkstra(const T& p_origine, const T& p_destination, std::vector<T>& p_chemin){
	int n =m_sommets.size();
	int y[n];
	int a;
	int b;
	std::vector<int>  sommetDansT;

	int provenance[n];


	for(int i = 0 ; i < n ; i++){
		if(m_sommets[i] == p_origine){
			a = i;
			break;
		}
	}

	for(int i = 0 ; i < n ; i++){
		if(m_sommets[i] == p_destination){
			b = i;
			break;
		}
	}

	for(int i = 0 ; i < n ; i++){
		y[i] = INFINITY;
		provenance[i] = INFINITY;
	}
	y[a] = 0;

	for(int i = 0 ; i < n ; i++){
		sommetDansT.push_back(i);
	}

	while(!sommetDansT.empty()){
		int j = sommetDansT[0];
		for(std::vector<int>::iterator it = sommetDansT.begin(); it != sommetDansT.end() ; it++){
			if(ComparerPlusPetit(y[*it], y[j])){
				j = *it;
			}
		}

		for(std::vector<int>::iterator it = sommetDansT.begin(); it != sommetDansT.end() ; it++){
			if(*it == j){
				sommetDansT.erase(it);
				break;
			}
		}

		std::vector<int> cheminInverse;

		if(m_sommets[j] == p_destination){
			int noStation = b;
			while(noStation != a){
				cheminInverse.push_back(noStation);
				noStation = provenance[noStation];
			}

			p_chemin.push_back(m_sommets[a]);
			while(!cheminInverse.empty()){
				p_chemin.push_back(m_sommets[cheminInverse[cheminInverse.size()-1]]);
				cheminInverse.pop_back();
			}

			return y[j];
		}

		for(std::vector<int>::iterator it = sommetDansT.begin(); it != sommetDansT.end() ; it++){
			int k = *it;
			if( j != k && m_matriceAdj[j][k] != INFINITY){
				if(ComparerPlusPetit(y[k],y[j] + m_matriceAdj[j][k])){

				}
				else{
					provenance[k] = j;
					y[k] = y[j] + m_matriceAdj[j][k];
				}
			}
		}

	}
}


