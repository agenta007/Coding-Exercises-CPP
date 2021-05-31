#include <iostream>
#include "Money.h"
#include "bigInteger.h"
#include <vector>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;

int Money::getLevs() const
{
    return levs;
}

int Money::getStotinkis() const
{
    return stotinkis;
}

int Money::setLevs(int levs)
{
    (*this).levs = levs;
    return 0;
}

int Money::makeStotinkisToLevs() 
{
    while (stotinkis > 99)
    {
        ++levs;
        stotinkis -= 100;
    }
    return 0;
}

int Money::setStotinkis(int stotinkis)
{
    (*this).stotinkis = stotinkis;
    this->makeStotinkisToLevs();
    return 0;
}

int Money::printMoney()const
{
    cout << "Object has " << levs << "." << stotinkis << " BGN" << endl;
    return 0;
}

bool Money::operator-(Money const &obj)
{
    (*this).makeStotinkisToLevs();
    if ((*this).levs > obj.levs && this->stotinkis > obj.stotinkis)
    {
        return false;
    }
    return true;
}

Money::Money()
{
    levs = stotinkis = 0;
}

Money::Money(int n)
{
    levs = n;
    stotinkis = 0;
}

Money Money::operator*(Money const& obj)
{
    Money resObj;
    resObj.levs = obj.levs * levs;
    resObj.stotinkis = obj.stotinkis * stotinkis;
    return resObj;
}

BigInteger BigInteger::operator*(BigInteger &b)
{
    BigInteger res;

}

int main()
{
    long long i(9);
    std::vector<long long> llVec;
    while (i!=0)
    {
        cout << "123456789 * " << i << " = " << 123456789 * i << endl;
        llVec.push_back(123456789*i);
        --i;
    }

    long long j = 0;

    int power = 0;
    for (auto& el : llVec)
    {
        j += el * 10 * power;
        cout << el * pow(10,power) << endl;
        ++power;
    }
    cout << j << endl;

    //+ subirane
    //- sravnenie
    Money dancho;
    Money go6o;
    go6o.setLevs(54);
    go6o.setStotinkis(2478);
    dancho.setLevs(25);
    dancho.setStotinkis(505);
    dancho.printMoney();
    Money partiq = go6o + dancho;
    partiq.printMoney();
    bool cmpRes = go6o - dancho;
    if (!cmpRes)
        cout << "Go6o has more money: " << go6o.getLevs() << "." << go6o.getStotinkis() << "BGN than dancho, which has " << dancho.getLevs() << "." << dancho.getStotinkis() << " bgn" << endl;
    else
        cout << "Dancho has more money : " << dancho.getLevs() << "." << dancho.getStotinkis() << " bgn than go6o, who has" << go6o.getLevs() << "." << go6o.getStotinkis() << endl;
    return 0;
}
