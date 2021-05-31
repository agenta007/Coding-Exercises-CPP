//
//  Car.cpp
//  CSCB212_Theme_2
//
//  Created by Mariana Raykova on 9.03.21.
//  Copyright © 2021 Mariana Raykova. All rights reserved.
//
#include "Car.h"
Car::Car(char* brand, unsigned doors, unsigned p, unsigned y, double price) :
    doors(doors), power(p), year(y), price(price) {
    if (brand != nullptr)
    {
        setBrand(brand);
    }
    else
    {
        setBrand(nullptr);
        return;
    }
    //strcpy(this->brand, brand);
    strcpy_s(this->brand, strlen(brand)+1, brand);
}

Car::Car(const Car& rhs) {
    brand = new char[strlen(rhs.brand) + 1];
    //strcpy(brand, rhs.brand);
    strcpy_s(brand, strlen(rhs.brand)+1, rhs.brand);
    doors = rhs.doors;
    power = rhs.power;
    year = rhs.year;
    price = rhs.price;
}

Car::~Car() {
    if (brand != nullptr) {
        delete[] brand;
    }
}

Car& Car::operator=(const Car& rhs) {
    /*if (this != &rhs) {
        if (brand != nullptr) {
            delete[] brand;
        }
        brand = new char[strlen(rhs.brand) + 1];
        //strcpy(brand, rhs.brand);
        strcpy_s(brand, strlen(rhs.brand)+1, rhs.brand);
        doors = rhs.doors;
        power = rhs.power;
        year = rhs.year;
        price = rhs.price;
    }
    return *this;*/
    setBrand(rhs.brand);
    doors = rhs.doors;
    power = rhs.power;
    year = rhs.year;
    price = rhs.price;
    return *this;
}

int Car::print() const 
{
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Doors: " << doors << std::endl;
    std::cout << "Power: " << power << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Price: " << price << std::endl;
    return 0;
}

int Car::setBrand(char* brand) {
    if (brand == nullptr)
    {
        this->brand = new char[]{'N','o','B','r','a','n','d','\0' };
        return 0;
    }
    this->brand = new char[strlen(brand) + 1];
    //strcpy(this->brand, brand);
    strcpy_s(this->brand, strlen(brand) + 1, brand);
    return 0;
}

char* Car::getBrand()const {
    return brand;
}

std::ostream& Car::ins(std::ostream& out) const {
    out << "Brand: " << brand << std::endl;
    out << "Doors: " << doors << std::endl;
    out << "Power: " << power << std::endl;
    out << "Year: " << year << std::endl;
    out << "Price: " << price << std::endl;

    return out;
}

std::ostream& operator<<(std::ostream& lhs, const Car& rhs) {
    return rhs.ins(lhs);
}

Car Car::operator+(int rhs) const {
    return Car(brand, doors, power + rhs, year, price);
}

Car& Car::operator+=(int rhs) {
    power += rhs;
    return *this;
}

Car operator+(int lhs, const Car& rhs) {
    return rhs + lhs;
}

Car& Car::operator--() {
    this->price -= 100;
    return *this;
}

Car Car::operator--(int) {
    Car tmp = *this;
    price -= 100;
    return tmp;
}

Car Car::operator%(int rhs)const {
    //10000->? след 5 години, на всяка година се намаля с 10% цената=>c1%5
    Car tmp(*this);
    tmp.price = price - price * (rhs * 10. / 100);
    return tmp;
}

bool Car::operator>(const Car& rhs) const {
    //c1->30000, 2018 c2->30000, 2021
    if (this->price > rhs.price) return true;
    else if (this->price == rhs.price && this->year < rhs.year) return true;
    else return false;
}
bool Car::operator ==(const Car& rhs) const {
    return price == rhs.price && doors == rhs.doors && year == rhs.year && power == rhs.power &&
        !strcmp(brand, rhs.brand);
}

bool Car::operator>=(const Car& rhs) const {
    return *this > rhs || *this == rhs;
}

bool Car::operator<(const Car& rhs) const {
    return !(*this >= rhs);
}

bool Car::operator<=(const Car& rhs) const {
    return !(*this > rhs);
}

std::ostream& operator<<(std::ostream& out, Car* parr)
{
    int arrSz = sizeof(parr);
    for (int i = 0; i < 24; i++)
    {
        out << *(parr)->brand << " " << (parr)->doors << " " << parr->power << " " << parr->price << " " << parr->year << " ";
        ++parr;
    }
    return out;
}

int Car::operator++(int inc) 
{
    this->price += 150;
    return 0;
}

int Car::operator*=(int multiplier)
{
    price *= multiplier;
    return 0;
}

double Car::getPrice()const {
    return price;
}



