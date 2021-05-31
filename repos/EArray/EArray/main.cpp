#include <iostream>
using namespace std;
//Динамичен масив с добавяне на елементи в края
//и с автоматично разширяване при необходимост. 
template<class T> class EArray 
{
    static const size_t INIT = 10;
    T* data;
    size_t capacity;
    int count;
public:
    EArray() 
    {
        count = 0;
        data = new T[capacity = INIT];
    }
    ~EArray() { delete[] data; }
    //Добавяне на нов елемент в края на масива
    void push_back(const T& t) 
    {
        if (count == capacity) 
        {
            // при запълване масивът се разширява двойно
            size_t newCap = 2 * capacity;
            T* newData = new T[newCap];
            //пренос на съществуващите данни
            for (size_t i = 0; i < count; ++i)
                newData[i] = data[i];
            delete[] data; //освобождаване на старата памет
            data = newData; //прикачане на новозаетата
            capacity = newCap;//тове е новият размер
        }
        data[count++] = t;
    }
    //Скъсяване на масива с една позиция
    void pop_back() 
    {
        if (count > 0) --count;
    }
    //Връщане на указатели към първия елемент 
    //и към първото свободно място
    T* begin() { return data; }
    T* end() { return data + count; }
    void inc_count() { count++; }
    T* operator[](int index)
    {
        try
        {
            if (index>count-1 || index < 0)
            {
                throw std::out_of_range("OUT_OF_RANGE");
            }
            else
            {
                return data + index;
            }
        }
        catch (const out_of_range&)
        {
            cout << "Range of EArray[0 - " << count-1 << "]" << "\nWrong index " << index << " enter new one:";
            int ind;
            cin >> ind;
            operator[](ind);
        }
    }
};

//Клас-шаблон с два параметъра, 
//вторият от които - също клас-шаблон.
//Първият параметър описва типа на елементите,
//а вторият - начина за достъп до тях. 
template<class T, template<class> class Seq>
class Container {
    Seq<T> seq;//тук се вижда, че първият параметър се
    //използва за конкретизацията на втория.
    //Затова при инстанциране от този клас се използват само 2 типа. 
public:
    //добавяне на нов елемент в края
    void append(const T& t) { seq.push_back(t); }
    //прилагане на функция върху всички елементи последователно
    void foreach(void (*fp)(T)) {
        for (T* p = seq.begin(); p != seq.end(); p++)fp(*p);
    }
    T* begin() { return seq.begin(); }
    T* end() { return seq.end(); }
};
void print(int i) { cout << i << endl; }

int main() 
{
    EArray<int>m_array;
    //zapisvam nov element, zatova uvelichavam count chrez metod
    m_array.inc_count();
    //zapis
    *(m_array[0]) = 15;
    //chetene
    cout << m_array[0] << endl;
    cout << *m_array[0] << endl;
    m_array.inc_count();
    *m_array[1] = 25;
    cout << m_array[5] << endl;



    Container<int, EArray> container;
    //Container<int, EArray<int> > container;
    for (int i = 0; i < 5; i++) container.append(rand());
    int* p = container.begin();
    while (p != container.end())
        cout << *p++ << endl;
    cout << endl;
    container.foreach(print);
}
