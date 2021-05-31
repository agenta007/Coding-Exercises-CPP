#include <iostream>
using namespace std;

class Animal
{
public:
	Animal() { life = 0; }
	Animal(bool vital) { vital ? life = 1 : 0; }
	bool getLife() { return life; }
	~Animal() {}
private:
	bool life;
};


class Person: public Animal
{
private:
	string name;
	int age;
public:
	Person() { age = 0; name = ""; }
	Person(int age, string name) { this->age = age; this->name = name; }
	~Person() {}
	void setAge(int a) { age = a; }
	int getAge() const { return age; }
	void setName(string input) { name = input; }
	string getName() const { return name; }
protected:
};

typedef struct MyStruct
{
private:
	Animal jivotno;
public:
	Person chovek;
}MyStruct1;

union MyUnion
{
	int a;//32bits
	char masiv[4];//4*8=32bits
};

int main()
{
	MyUnion EU;
	EU.a = 8;
	Person a = Person(5, "Petko");
	bool isAAlive = a.getLife();
	MyStruct1 myStruct1a;
	myStruct1a.chovek = a;
	cout << myStruct1a.chovek.getAge() << " "  << myStruct1a.chovek.getName()<< endl;
}