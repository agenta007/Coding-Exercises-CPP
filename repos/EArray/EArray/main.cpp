#include <iostream>
using namespace std;
//��������� ����� � �������� �� �������� � ����
//� � ����������� ����������� ��� ������������. 
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
    //�������� �� ��� ������� � ���� �� ������
    void push_back(const T& t) 
    {
        if (count == capacity) 
        {
            // ��� ��������� ������� �� ��������� ������
            size_t newCap = 2 * capacity;
            T* newData = new T[newCap];
            //������ �� �������������� �����
            for (size_t i = 0; i < count; ++i)
                newData[i] = data[i];
            delete[] data; //������������� �� ������� �����
            data = newData; //��������� �� �����������
            capacity = newCap;//���� � ������ ������
        }
        data[count++] = t;
    }
    //��������� �� ������ � ���� �������
    void pop_back() 
    {
        if (count > 0) --count;
    }
    //������� �� ��������� ��� ������ ������� 
    //� ��� ������� �������� �����
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

//����-������ � ��� ����������, 
//������� �� ����� - ���� ����-������.
//������� ��������� ������ ���� �� ����������,
//� ������� - ������ �� ������ �� ���. 
template<class T, template<class> class Seq>
class Container {
    Seq<T> seq;//��� �� �����, �� ������� ��������� ��
    //�������� �� ��������������� �� ������.
    //������ ��� ������������ �� ���� ���� �� ��������� ���� 2 ����. 
public:
    //�������� �� ��� ������� � ����
    void append(const T& t) { seq.push_back(t); }
    //��������� �� ������� ����� ������ �������� ��������������
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
