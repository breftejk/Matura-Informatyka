#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<int> wczytaj_dane()
{
    vector<int> dane;

    ifstream file("C:/Matury-Informatyka/Arkusze probne/CKE Kwiecien 2020/DANE/dane4.txt");
    int liczba;
    while(file >> liczba){
        dane.push_back(liczba);
    }

    return dane;
}

int main()
{
    vector<int> liczby = wczytaj_dane();

    map<int,int> krotnosci;

    for(int i = 0; i<liczby.size(); i++){
        int roznica = abs(liczby[i+1] - liczby[i]);
        int krotnosci_teraz = krotnosci[roznica];
        krotnosci[roznica] = krotnosci_teraz+1;
    }

    int maxKrotnosc = 0;
    vector<int> maxKrotnosci;

    for(auto a: krotnosci){
        if(a.second > maxKrotnosc){
            maxKrotnosci.clear();

            maxKrotnosc = a.second;
            maxKrotnosci.push_back(a.first);
        }else if(a.second == maxKrotnosc){
            maxKrotnosci.push_back(a.first);
        }
    }

    cout << "4.3.\nNajczestsza luka: " << maxKrotnosc << "\nWartosci luk: \n";
    for(auto a: maxKrotnosci){
        cout << a << " ";
    }

    return 0;
}
