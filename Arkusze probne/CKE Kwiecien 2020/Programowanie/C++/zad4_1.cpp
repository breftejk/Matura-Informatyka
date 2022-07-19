#include <iostream>
#include <fstream>
#include <vector>
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

    int minRoznica = 999999999;
    int maxRoznica = -999999999;

    for(int i = 0; i<liczby.size(); i++){
        int roznica = abs(liczby[i+1] - liczby[i]);
        if(roznica > maxRoznica)maxRoznica = roznica;
        if(roznica < minRoznica)minRoznica = roznica;
    }

    cout << "4.1.\nNajmniejsza: " << minRoznica << "\nNajwieksza: " << maxRoznica;

    return 0;
}
