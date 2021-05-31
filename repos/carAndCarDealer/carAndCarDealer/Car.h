//
//  Car.hpp
//  CSCB212_Theme_2
//
//  Created by Mariana Raykova on 9.03.21.
//  Copyright © 2021 Mariana Raykova. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
using namespace std;
//За една кола трябва да можем да опишем коя е марката на колата, колко врати има, колко конски сили, коя година е произведена и каква цена е.
//За една кола до можем да реализираме голямата петорка - трите вида конструктора, предефинирано = и деструктор.
//Нека за колата да имаме сетъри и гетъри,
//да можем да отпечатваме данните за една кола в изходен поток, т.е. Car car; cout << car;

//Да увеличаване конските сили на кола софтуерно, като използваме изрази от вида
//car+3; 3+car;
//car+=3;

//car-- или  --car с което намалям цената на колата със 100лв;

//както и на колко години е колата, процентно намаляне на цената на колата за всяка следваща година, с 10%
//=, +=, -=, ..., [], ()
//car%5=>2 versions - member, global function
//car%20
//20%car

//Сравнение на коли с оператор > като сравняваме цените и ако те са равни сравняваме годините
//1. >
//2. ==
//3. >=

//car1<car2
//car1<=car2

#include <iostream>
#include <cstring>


class Car {
    //friend std::ostream& operator<<(std::ostream & lhs, const Car & rhs);
public:
    //За една кола до можем да реализираме голямата петорка - трите вида конструктора, предефинирано = и деструктор.
    //Car();
    Car(char* = nullptr, unsigned = 0, unsigned = 0, unsigned = 0, double = 0.);
    Car(const Car&);
    ~Car();
    Car& operator=(const Car&);
    int print() const;
    int setBrand(char*);
    char* getBrand()const;
    double getPrice()const;

    std::ostream& ins(std::ostream&) const;

    Car operator+(int) const;
    Car& operator+=(int);

    Car& operator--();
    Car operator--(int);

    Car operator%(int)const;

    bool operator>(const Car&) const;
    bool operator==(const Car&) const;
    bool operator>=(const Car&) const;
    bool operator<(const Car&) const;
    bool operator<=(const Car&) const;
    friend ostream& operator<<(ostream& out, Car* parr);
    int operator++(int);
    int operator*=(int);
private:
    //марката на колата,
    char* brand;
    //колко врати има,
    unsigned doors;
    //колко конски сили,
    unsigned power;
    //коя година е произведена и
    unsigned year;
    //каква цена е.
    double price;
};
std::ostream& operator<<(std::ostream& lhs, const Car& rhs);
Car operator+(int, const Car&);
#endif /* Car_hpp */
