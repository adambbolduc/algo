//
//  Metro.h
//  métroparis
//
//  Created by Mario Marchand on 2015-03-05.
//  Copyright (c) 2015 Mario Marchand. All rights reserved.
//

#ifndef Metro_H
#define Metro_H

#include "Graphe.h"
#include "Station.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include "ContratException.h"

class Metro
{
    
public:
    
     //! \brief		Constructeur à partir d'un fichier en entrée.
     //! \param[in]	Le fichier d'entrée contenant les stations à charger.
     //! \pre		Le fichier d'entrée est ouvert corectement.
     //! \post		Le fichier d'entrée n'est pas fermé par la fonction.
     //! \post		Si les préconditions sont respectées, les données du métro contenu
     //!			dans le fichier en entrée sont organisées dans un graphe en mémoire.
    Metro(std::ifstream & p_fichierEntree);
    
    
     //! \brief		Détruit et libére toute la mémoire allouée auparavant pour le métro.
     //! \post		Toute la mémoire allouée auparavant pour le Metro est libérée.
     //! \post		L'Objet Metro n'est plus valide.
    ~Metro();
    
    
     //! \brief		Affiche la liste de toutes les stations du métro à l'écran
     //! \post		Toutes les stations du métro sont affichées.
    void afficherStations() const;
    
     //! \brief		 Trouve le plus court chemin entre deux stations en utilisant l'algorithme de Dijkstra défini dans Graphe
     //! \param[out] Le temps pris pour parcourir la distance est retournée; -1 s'il n'y a pas de chemin
     //! \param[out] La liste des stations à parcourir est retournée
    std::vector<Station> plusCourtChemin(const Station & p_origine, const Station & p_destination, int & p_nbSec);

    const Station& operator[](int i) const;
    
private:
    
    Graphe<Station> m_leGraphe;

};


#endif
