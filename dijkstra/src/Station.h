//
//  Station.h
//  métroparis
//
//  Created by Mario Marchand on 2015-03-05.
//  Copyright (c) 2015 Mario Marchand. All rights reserved.
//

#ifndef Station_H
#define Station_H

#include <string>

class Station
{
public:
    Station(const int& p_numero, const std::string& p_nom);
    ~Station();
    const int& get_numero() const;
    const std::string& get_nom() const;
    bool operator==(const Station& station) const;
    
    friend std::ostream& operator<<(std::ostream& out, const Station& station);

private:
    int m_numero;
    std::string m_nom;
    
};

#endif
