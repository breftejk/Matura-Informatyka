#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct Punkt {
    int x, y;
};

bool czy_pierwsza(int liczba)
{
    for(int i = 2; i<=sqrt(liczba); i++){
        if(liczba%i == 0)return false;
    }
    return true;
}

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

int main()
{
    vector<Punkt> punkty;
    wczytaj_dane(punkty);

    cout << "4.1.\n";

    int licznik = 0;

    for(auto punkt: punkty){
        if(czy_pierwsza(punkt.x) && czy_pierwsza(punkt.y)) licznik+=1;
    }

    cout << licznik;

    return 0;
}
