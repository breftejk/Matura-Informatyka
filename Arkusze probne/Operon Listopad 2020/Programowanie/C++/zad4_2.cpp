#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int const N = 10000; // 10'000 liczb

void wczytaj_dane(vector<int> &lista)
{
    ifstream dane("C:/Matury-Informatyka/Arkusze probne/Operon Listopad 2020/DANE/dane.txt");
    int liczba;
    while(dane >> liczba){
        lista.push_back(liczba);
    }
}

void lec_po(vector<int> &lista, int dla){
    vector<int> listaTemp;

    for(int i = 0; i<lista.size(); i++){
        if((i+1)%dla != 0){
            listaTemp.push_back(lista[i]);
        }
    }

    lista = listaTemp;
}

vector<int> liczby_szczesliwe()
{
    vector<int> szczesliwe;
    for(int i = 1; i<=N; i++){
        szczesliwe.push_back(i);
    }

    lec_po(szczesliwe, 2);

    for(int i = 1; i<N; i++){
        int co_ktora = szczesliwe[i];
        if(co_ktora>szczesliwe.size()-1)break;
        lec_po(szczesliwe, co_ktora);
    }

    return szczesliwe;
}

bool czy_szczesliwa(vector<int> szczesliwe, int liczba)
{
    return find(szczesliwe.begin(), szczesliwe.end(), liczba) != szczesliwe.end();
}

int main()
{
    // dane z pliku
    vector<int> liczby;
    wczytaj_dane(liczby);

    // wszystkie liczby szczesliwe do N
    vector<int> szczesliwe = liczby_szczesliwe();

    // rozwiazanie
    int licznik = 0;
    int firstIndex;

    int maxLicznik = 0;
    int maxFirstIndex;

    for(int i=0; i<liczby.size(); i++){
        if(czy_szczesliwa(szczesliwe, liczby[i])){
            licznik += 1;
        }else{
            licznik = 0;
        }

        if(licznik == 1){
            firstIndex = i;
        }

        if(licznik > maxLicznik){
            maxLicznik = licznik;
            maxFirstIndex = firstIndex;
        }
    }

    cout << "4.2. " << maxLicznik << " " << liczby[maxFirstIndex];

    return 0;
}
