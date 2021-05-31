//
//  CarDealer.hpp
//  CSCB212_Theme_2
//
//  Created by Mariana Raykova on 16.03.21.
//  Copyright © 2021 Mariana Raykova. All rights reserved.
//

#include "Car.h"
#ifndef CarDealer_hpp
#define CarDealer_hpp

#include <iostream>
#include <cstring>

class CarDealer 
{
public:
    CarDealer();
    CarDealer(const char*, unsigned, Car*);
    CarDealer(const CarDealer&);
    ~CarDealer();
    CarDealer& operator=(const CarDealer&);
    std::ostream& ins(std::ostream&)const;
    Car operator[](unsigned) const;
    Car& operator[](unsigned);

    double operator()() const;
    double operator()(unsigned, unsigned) const;
    int operator+(const Car &);
private:
    char* name;
    unsigned sz;
    Car* cars; //член-данна от друг клас се нар. композиция
};

std::ostream& operator<<(std::ostream&, const CarDealer&);

#endif /* CarDealer_hpp */
