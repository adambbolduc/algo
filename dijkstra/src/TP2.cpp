//
//  main.cpp
//  métroparis
//
//  Created by Mario Marchand on 2015-03-05.
//  Copyright (c) 2015 Mario Marchand. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Metro.h"
#include "ContratException.h"


int main()
{

    using namespace std;
    
	ifstream fichier("Metro.txt");
	Metro metro(fichier);

	int temps, noStationDepart, noStationArrivee;



	cout << "Entrez le numéro de la station de départ" << endl;
	cin >> noStationDepart;
	cout << "Entrez le numéro de la station d'arrivée" << endl;
	cin >> noStationArrivee;

	vector<Station> chemin = metro.plusCourtChemin(metro[noStationDepart], metro[noStationArrivee],temps);

	cout << "Le plus court chemin trouvé est :" << endl;

	for(unsigned int i = 0 ; i < chemin.size() ; i++){
		cout << chemin[i] << endl;
	}

	cout << "Avec un temps estimé de " << temps << " secondes"<< endl;
    return 0;
}

