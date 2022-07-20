#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 100000;

void wczytaj_dane(vector<int> &liczby)
{
    // ifstream dane("C:/Matury-Informatyka/Matury CKE/2019 Maj/DANE/przyklad.txt");
    ifstream dane("C:/Matury-Informatyka/Matury CKE/2019 Maj/DANE/liczby.txt");
    int temp_liczba;
    while(dane >> temp_liczba){
        liczby.push_back(temp_liczba);
    }
}

int silnia(int liczba){
    if(liczba == 0)return 1;
    if(liczba == 1)return 1;
    return liczba*silnia(liczba-1);
}

int main()
{
    vector<int> liczby;
    wczytaj_dane(liczby);

    cout << "4.1.\n";

    for(int a: liczby){
        int b = a;
        int suma_silni = 0;
        while(b != 0){
            int c = b % 10;
            b /= 10;

            suma_silni += silnia(c);
        }

        if(suma_silni == a){
            cout << a << endl;
        }
    }

    return 0;
}
