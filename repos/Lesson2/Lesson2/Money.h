//
// Created by agenta on 12-Mar-21.
//

#ifndef LESSON2_MONEY_H
#define LESSON2_MONEY_H
class Money
{
private:
    int levs, stotinkis;
public:
    Money operator + (Money const& obj) 
    {
        {
            Money sumObj;
            sumObj.levs = this->levs + obj.levs;
            sumObj.stotinkis = this->stotinkis + obj.stotinkis;
            makeStotinkisToLevs();
            return  sumObj;
        }
    }
    Money();
    Money(int);
    bool operator -(Money const& obj);
    Money operator * (Money const& obj);
    int getLevs() const;
    int getStotinkis() const;
    int setLevs(int);
    int setStotinkis(int);
    int printMoney()const;
    int makeStotinkisToLevs();
    void setName(char*);
    char* getName()const;

};
#endif //LESSON2_MONEY_H
