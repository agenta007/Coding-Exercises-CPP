#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

int cifra(int& chislo) {
    int a;
    a = chislo % 10;
    chislo /= 10;
    return a;
}


int main(int argc, char* argv[])
{
    int chislo, chislo1, osnowa;
    double desetichno = 0;
    cout << "Wuwedete chislo w broina sistema s osnowa po-malka ot 10: ";
    cin >> chislo;
    chislo1 = chislo;
    cout << "Wuwedete osnowata na broinata sistema: ";
    cin >> osnowa;
    if ((osnowa >= 2) && (osnowa < 10))
    {

        for (double i = 1, p = 0; i <= chislo1; i = i * pow(10, p))  //Kum i pri wsqka prowerka na uslowieto se pribawq nula w reda na deseticite (i=10^p)
        {
            desetichno = desetichno + cifra(chislo) * pow(osnowa, p);
            ++p;
            i = 1;
        }
        cout << "\n Chisloto " << chislo1 << " prewurnato w desetichno e " << desetichno << endl;
    }
    else cout << "Newalidna osnowa\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}