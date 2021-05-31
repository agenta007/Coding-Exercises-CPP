#include <iostream>
using namespace std;
class Employee
{
public:
    virtual int getinfo() = 0;
    const char* name = "NoName";
    Employee& operator = (const Employee&) {}
};
class Worker :public Employee
{
public:
    Worker() {};
    int getinfo(){
      cout << this->name << this->age;
      return 0;
    };
private:
    int age;
};
class Boss :public Employee
{
public:
    Boss() {};
    int getinfo(){
      cout << this->name << this->salary;
      return 0;
    };
private:
    double salary;
};
class LineinaMatrica
{
    int delimiter;//10
    int sz;//200
    int* elements;
public:
    LineinaMatrica(int redove, int delimiter) { this->sz = redove*delimiter; this->delimiter = delimiter; elements = new int[this->sz]; };
    ~LineinaMatrica() { delete elements; };
    friend ostream& operator<<(ostream&, const LineinaMatrica&);
    void zanulqvane();
    int* operator[](int);
    void print();
};
ostream& operator<<(ostream& out, const LineinaMatrica& matrica)
{
    for (size_t i = 0; i < matrica.sz / matrica.delimiter; i++)
    {
        for (size_t j = 0; j < matrica.delimiter; j++)
        {
            out << matrica.elements[i * matrica.delimiter + j] << " ";
        }
        out << "\n";
    }
    return out;
}
int* LineinaMatrica::operator[](int idx)
{
    int* lineOfMatrix = new int[delimiter];
    for (size_t i = idx*delimiter; i < (idx+1)*delimiter; i++)
    {
        lineOfMatrix[i] = elements[i];
    }
    return lineOfMatrix;
}
void LineinaMatrica::zanulqvane()
{
    for (size_t i = 0; i < sz; i++)
    {
        elements[i] = 0;
    }
}
void LineinaMatrica::print()
{
    for (size_t i = 0; i < sz; i++)
    {
        cout << elements[i] << " ";
    }
}
int main()
{
    LineinaMatrica A(20, 10);
    A.zanulqvane();
    A.print();
    for (size_t i = 0; i < 20; i++)
    {
        int* lineP = A[i];
        for (size_t j = 0; j < 10; j++)
        {
            cout << *(lineP + j) << " ";
        }
        cout << endl;
    }
    cout << A << endl;
    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            A[i][j] = i * j;
        }
    }
    Employee** empl = new Employee*[10];

    for (int i = 0; i < 5; i++)
    {
        empl[i] = (new Worker());
    }

    for (int i = 5; i < 10; i++)
    {
        empl[i] = (new Boss());
    }

    for (int i = 0; i < 10; i++)
    {
        empl[i]->getinfo();
    }

    return 0;
}