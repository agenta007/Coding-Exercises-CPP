#include <iostream>
using namespace std;

class Employee
{
public:
	Employee(string = "noID");
	Employee(const Employee&);
	string getID()const { return employeeID; }
	void setID(string input) { employeeID = input; }
	friend ostream& operator<<(ostream&, const Employee&);
	void operator=(const Employee&);
private:
	string employeeID;
};
ostream& operator<< (ostream& out, const Employee& empRef)
{
	out << empRef.employeeID;
	return out;
}
Employee::Employee(string id)
{
	employeeID = id;
}
Employee::Employee(const Employee& empRef)
{
	employeeID = empRef.employeeID;
}
void Employee::operator=(const Employee& rhs)
{
	employeeID = rhs.employeeID;
}
class Programmer:public Employee
{
public:
	Programmer(string = "noName", double = 0);
	string getName()const;
	double getSalary()const { return salary; }
	void setName(string input) { name = input;}
	void setSalary(double value) { salary = value; }
private:
	string name;
	double salary;
};

Programmer::Programmer(string name, double salary)
{
	this->name = name;
	this->salary = salary;
}
string Programmer::getName()const
{
	return "Hacker, " + name + "(Programmer)";
}

int main()
{
	Employee employeeOfTheMonth("111111");
	Employee notSoGoodEmployee("222222");
	Programmer hisBuddy("Stati, ", 5555.55);
	cout << hisBuddy.getName() << endl;
	cout << hisBuddy.getID() << endl;
	cout << notSoGoodEmployee << endl;
	notSoGoodEmployee = employeeOfTheMonth;
	cout << notSoGoodEmployee << endl;
	return 0;
}
