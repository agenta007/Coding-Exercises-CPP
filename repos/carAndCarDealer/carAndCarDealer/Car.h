//
//  Car.hpp
//  CSCB212_Theme_2
//
//  Created by Mariana Raykova on 9.03.21.
//  Copyright � 2021 Mariana Raykova. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
using namespace std;
//�� ���� ���� ������ �� ����� �� ������ ��� � ������� �� ������, ����� ����� ���, ����� ������ ����, ��� ������ � ����������� � ����� ���� �.
//�� ���� ���� �� ����� �� ����������� �������� ������� - ����� ���� ������������, ������������� = � ����������.
//���� �� ������ �� ����� ������ � ������,
//�� ����� �� ����������� ������� �� ���� ���� � ������� �����, �.�. Car car; cout << car;

//�� ����������� �������� ���� �� ���� ���������, ���� ���������� ������ �� ����
//car+3; 3+car;
//car+=3;

//car-- ��� �--car � ����� ������� ������ �� ������ ��� 100��;

//����� � �� ����� ������ � ������, ��������� �������� �� ������ �� ������ �� ����� �������� ������, � 10%
//=, +=, -=, ..., [], ()
//car%5=>2 versions - member, global function
//car%20
//20%car

//��������� �� ���� � �������� > ���� ���������� ������ � ��� �� �� ����� ���������� ��������
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
    //�� ���� ���� �� ����� �� ����������� �������� ������� - ����� ���� ������������, ������������� = � ����������.
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
    //������� �� ������,
    char* brand;
    //����� ����� ���,
    unsigned doors;
    //����� ������ ����,
    unsigned power;
    //��� ������ � ����������� �
    unsigned year;
    //����� ���� �.
    double price;
};
std::ostream& operator<<(std::ostream& lhs, const Car& rhs);
Car operator+(int, const Car&);
#endif /* Car_hpp */
