//
//  Metro.cpp
//  métroparis
//
//  Created by Mario Marchand on 2015-03-06.
//  Copyright (c) 2015 Mario Marchand. All rights reserved.
//

#include "Metro.h"

Metro::Metro(std::ifstream & p_fichierEntree)
{
  PRECONDITION(p_fichierEntree.is_open());

  //indice pour lire le fichier
	int nbStations, noStation, nbLiens;
	p_fichierEntree >> nbStations >> nbLiens;

	//Lecture du nom des stations
	char buff[255];

	for (int i = 0; i < nbStations; i++)
	{
		p_fichierEntree >> noStation;
		p_fichierEntree.ignore();
		p_fichierEntree.getline(buff, 100);
		std::string s(buff);
		m_leGraphe.ajouteSommet(Station(i,s.substr(0, s.size()-1)));
	}

	p_fichierEntree.getline(buff,100);

	int noStationDepart, noStationArrivee, poids;
	while(!p_fichierEntree.eof()){
		p_fichierEntree >> noStationDepart >> noStationArrivee >> poids;
		m_leGraphe.ajouteArete(noStationDepart, noStationArrivee, poids);
	}
}

void Metro::afficherStations() const {
	for(int i = 0 ; i < m_leGraphe.reqTaille() ; i++){
		std::cout << m_leGraphe[i]<< std::endl ;
	}
}

const Station& Metro::operator [](int i) const{
	return m_leGraphe[i];
}

std::vector<Station> Metro::plusCourtChemin(const Station& p_origine, const Station& p_destination, int& p_nbSec){
	std::vector<Station> chemin;
	p_nbSec = m_leGraphe.dijkstra(p_origine, p_destination, chemin);
	return chemin;
}

Metro::~Metro() {}
