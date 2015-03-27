//
//  Graphe.h
//  métroparis
//
//  Created by Mario Marchand on 2015-03-05.
//  Copyright (c) 2015 Mario Marchand. All rights reserved.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

//! \brief Patron de classe pour graphes orientés utilisant une matrice d'adgacence
template <typename T>
class Graphe
{
public:
    
	 //! \brief		Constructeur sans paramètre
	 //! \post		Un graphe vide est créé
	Graphe();
    
	 //! \brief		Destructeur
	 //! \post		Le graphe est détruit
	~Graphe();


    //! \brief Algorithme de Dijkstra permettant de trouver le plus court chemin entre p_origine et p_destination
    //! \pre p_origine et p_destination doivent être des sommets du graphe
    //! \param[out] la longueur du plus court chemin est retournée
    //! \param[out] le chemin est retourné
	int dijkstra(const T & p_origine, const T & p_destination, std::vector<T> & p_chemin);


	/*
	 * \brief	Ajoute une somme au graphe
	 * \param[in] sommet Le somme à ajouter au graphe
	 *
	 */
	void ajouteSommet(const T& sommet);
    
	/*
	 *
	 */
	void ajouteArete(int noSommetDepart, int noSommetArrivee, int poids);

	int reqTaille() const;

	const T& operator[](int i) const;

private:
    std::vector<T> m_sommets;	/*!< Les sommets */
    std::vector< std::vector<int> > m_matriceAdj; /*!< la matrice d'adjacence */

    bool ComparerPlusPetit(int a, int b);
    int min(int a, int b);
};

#include "Graphe.hpp"

#endif
