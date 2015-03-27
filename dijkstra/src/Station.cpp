//
//  Station.cpp
//  métroparis
//
//  Created by Mario Marchand on 2015-03-05.
//  Copyright (c) 2015 Mario Marchand. All rights reserved.
//

#include "Station.h"
#include <iostream>

Station::Station(const int& p_numero, const std::string& p_nom) :
    m_numero(p_numero), m_nom(p_nom) {}

Station::~Station() {}

const int& Station::get_numero() const
{
    return m_numero;
}
const std::string& Station::get_nom() const
{
    return m_nom;
}

bool Station::operator==(const Station& station) const{
	return (station.m_nom == this->m_nom) && (station.m_numero == this->m_numero);
}


std::ostream& operator<<(std::ostream& out, const Station& station){
	out << station.m_nom;
	return out;
}
