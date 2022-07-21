#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void wczytaj_dane(vector<vector<int>> &liczby)
{
    // ifstream dane("C:/Matury-Informatyka/Matury CKE/2017 Maj/DANE/przyklad.txt");
    ifstream dane("C:/Matury-Informatyka/Matury CKE/2017 Maj/DANE/dane.txt");

    while(!dane.eof()){
        string liczby_str;
        getline(dane, liczby_str);
        stringstream liczby_ss;
        liczby_ss << liczby_str;

        vector<int> liczbyV;
        int liczba;
        while(liczby_ss >> liczba){
            liczbyV.push_back(liczba);
        }

        liczby.push_back(liczbyV);
    }
}

bool czy_symetryczny(vector<int> wiersz)
{
    bool symetryczny = true;

    for(int i = 0; i<wiersz.size()/2; i++){
        if(wiersz[i] != wiersz[wiersz.size()-1-i]){
            symetryczny = false;
            break;
        }
    }

    return symetryczny;
}

int main()
{
    vector<vector<int>> dane;
    wczytaj_dane(dane);

    cout << "6.2.\n";

    int licznik = 0;

    for(int i = 0; i<dane.size(); i++){
        if(!czy_symetryczny(dane[i])){
            licznik += 1;
        }
    }

    cout << licznik;

    return 0;
}
