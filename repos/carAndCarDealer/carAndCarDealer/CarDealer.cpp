//
//  CarDealer.cpp
//  CSCB212_Theme_2
//
//  Created by Mariana Raykova on 16.03.21.
//  Copyright © 2021 Mariana Raykova. All rights reserved.
//

#include "CarDealer.h"

CarDealer::CarDealer() :name(new char[7]), sz(0), cars(nullptr) {
    //strcpy(name, "NoName");
    strcpy_s(name, strlen("NoName"), "NoName");
}

CarDealer::CarDealer(const char* name, unsigned sz, Car* cars):
    name(new char[strlen(name) + 1]), sz(sz), cars(new Car[sz]) {
    //strcpy(this->name, name);
    strcpy_s(this->name, strlen(name) + 1, name);
    for (int i = 0; i < sz; i++) {
        this->cars[i] = cars[i];
    }
}

CarDealer::CarDealer(const CarDealer& rhs) :
    name(new char[strlen(rhs.name) + 1]), sz(rhs.sz), cars(new Car[sz]) {
    //strcpy(name, rhs.name);
    strcpy_s(name, strlen(rhs.name) + 1, rhs.name);
    for (int i = 0; i < sz; i++) {
        cars[i] = rhs.cars[i];
    }
}

CarDealer::~CarDealer() {
    if (name != nullptr) {
        delete[] name;
        name = nullptr;
    }
    if (cars != nullptr) {
        delete[] cars;
        cars = nullptr;
    }
}

CarDealer& CarDealer::operator=(const CarDealer& rhs) {
    if (this != &rhs) {
        if (name != nullptr) {
            delete[] name;
            name = nullptr;
        }
        if (cars != nullptr) {
            delete[] cars;
            cars = nullptr;
        }
        name = new char[strlen(rhs.name) + 1];
        //strcpy(name, rhs.name);
        strcpy_s(name, strlen(rhs.name) + 1, rhs.name);
        sz = rhs.sz;
        cars = new Car[sz];
        for (int i = 0; i < sz; i++) {
            cars[i] = rhs.cars[i];
        }
    }
    return *this;
}

std::ostream& CarDealer::ins(std::ostream& out)const {
    out << "Dealer name: " << name << std::endl;
    out << "Number of cars: " << sz << std::endl;
    out << "Cars: " << std::endl;
    for (int i = 0; i < sz; i++) {
        out << "Car[" << i + 1 << "]: " << cars[i] << std::endl;
    }
    return out;
}

std::ostream& operator<<(std::ostream& lhs, const CarDealer& rhs) {
    return rhs.ins(lhs);
}

Car CarDealer::operator[](unsigned rhs) const {
    int ind = (rhs >= sz) ? sz - 1 : rhs;
    return cars[ind];
}

Car& CarDealer::operator[](unsigned rhs) {
    int ind = (rhs >= sz) ? sz - 1 : rhs;
    return cars[ind];
}

double CarDealer::operator()() const {
    double sum = 0.;
    for (int i = 0; i < sz; i++) {
        sum += cars[i].getPrice();
    }
    return sum;
}
double CarDealer::operator()(unsigned b, unsigned e) const {
    double sum = 0.;
    if (b > e) {
        int t = b;
        b = e;
        e = t;
    }
    if (e >= sz) e = sz - 1;
    for (int i = b; i <= e; i++) {
        sum += cars[i].getPrice();
    }
    return sum;
}

int CarDealer::operator+(const Car& rhs)
{
    Car a;
    ++sz;
    Car* tmp = new Car[sz];
    for (int i = 0; i < sz-1; i++)
    {
        tmp[i] = cars[i];
    }
    delete[] cars;
    cars = new Car[sz];
    tmp[sz] = rhs;
    cars = tmp;
    return 0;
}