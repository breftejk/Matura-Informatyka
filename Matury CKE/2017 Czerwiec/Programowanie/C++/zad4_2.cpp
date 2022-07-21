#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Punkt {
    int x, y;
};

void wczytaj_dane(vector<Punkt> &punkty)
{
    ifstream dane("C:/Matury-Informatyka/Matury CKE/2017 Czerwiec/DANE/punkty.txt");
    int x, y;
    while(dane >> x >> y){
        Punkt punkt;
        punkt.x = x;
        punkt.y = y;
        punkty.push_back(punkt);
    }
}

vector<int> rozloz_unikalnie_posortowanie(int liczba){
    vector<int> rozlozone;
    while(liczba != 0){
        rozlozone.push_back(liczba%10);
        liczba/=10;
    }

    vector<int> rozlozone_unikalne;
    for(auto a: rozlozone){
        if(find(rozlozone_unikalne.begin(), rozlozone_unikalne.end(), a) == rozlozone_unikalne.end()){
            rozlozone_unikalne.push_back(a);
        }
    }

    sort(rozlozone_unikalne.begin(), rozlozone_unikalne.end());
    return rozlozone_unikalne;
}

bool czy_cyfropodobne(int x, int y){
    vector<int> r_x = rozloz_unikalnie_posortowanie(x);
    vector<int> r_y = rozloz_unikalnie_posortowanie(y);

    if(r_x.size() != r_y.size())return false;
    for(int i = 0; i<r_x.size(); i++){
        if(r_x[i] != r_y[i])return false;
    }

    return true;
}

int main()
{
    vector<Punkt> punkty;
    wczytaj_dane(punkty);

    cout << "4.2.\n";

    int licznik = 0;

    for(auto punkt: punkty){
        if(czy_cyfropodobne(punkt.x, punkt.y)) licznik+=1;
    }

    cout << licznik;

    return 0;
}
