#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void wczytaj_dane(vector<int> &liczby, vector<int> &pierwsze)
{
    // ifstream dane_liczby("C:/Matury-Informatyka/Matury CKE/2019 Czerwiec/DANE/liczby_przyklad.txt");
    // ifstream dane_pierwsze("C:/Matury-Informatyka/Matury CKE/2019 Czerwiec/DANE/pierwsze_przyklad.txt");
    ifstream dane_liczby("C:/Matury-Informatyka/Matury CKE/2019 Czerwiec/DANE/liczby.txt");
    ifstream dane_pierwsze("C:/Matury-Informatyka/Matury CKE/2019 Czerwiec/DANE/pierwsze.txt");

    int temp_liczba;

    while(dane_liczby >> temp_liczba){
        liczby.push_back(temp_liczba);
    }

    while(dane_pierwsze >> temp_liczba){
        pierwsze.push_back(temp_liczba);
    }
}

int suma_w (int liczba)
{
    int suma_cyfr = 0;
    while( liczba != 0 ){
        suma_cyfr += liczba%10;
        liczba /= 10;
    }
    if(suma_cyfr < 10)return suma_cyfr;
    return suma_w(suma_cyfr);
}

int main()
{
    vector<int> liczby, pierwsze;
    wczytaj_dane(liczby, pierwsze);

    int licznik = 0;

    for(auto a: pierwsze){
        if(suma_w(a) == 1)licznik+=1;
    }

    ofstream wynik("C:/Matury-Informatyka/Matury CKE/2019 Czerwiec/Programowanie/C++/wyniki4_3.txt");
    wynik << licznik;
    wynik.close();

    return 0;
}
