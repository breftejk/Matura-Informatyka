#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <bits/stdc++.h>

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

bool czy_pierwsza(int liczba)
{
    for(int i = 2; i <= sqrt(liczba); i++){
        if(liczba % i == 0)return false;
    }
    return true;
}

int main()
{
    vector<int> liczby, pierwsze;
    wczytaj_dane(liczby, pierwsze);

    ofstream wynik("C:/Matury-Informatyka/Matury CKE/2019 Czerwiec/Programowanie/C++/wyniki4_2.txt");

    for(auto a: pierwsze){
        string liczba_string = to_string(a);
        string liczba_string_reversed = liczba_string;
        reverse(liczba_string_reversed.begin(), liczba_string_reversed.end());

        if( czy_pierwsza(stoi(liczba_string)) && czy_pierwsza(stoi(liczba_string_reversed)) ){
            wynik << liczba_string << endl;
        }
    }

    wynik.close();

    return 0;
}
