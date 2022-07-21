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

bool czy_wewnatrz(Punkt punkt)
{
    int x = punkt.x;
    int y = punkt.y;

    return (x > -5000 && x < 5000) && (y > -5000 && y < 5000);
}

bool czy_na_brzegu(Punkt punkt)
{
    int x = punkt.x;
    int y = punkt.y;

    return ((x == -5000 || x == 5000) && (y >= -5000 && y <= 5000) || (y == -5000 || y == 5000) && (x >= -5000 && x <= 5000));
}

int main()
{
    vector<Punkt> punkty;
    wczytaj_dane(punkty);

    cout << "4.3.\n";

    //na
    int zewnatrz = 0, wewnatrz = 0, brzegu = 0;
    for(auto punkt: punkty){
        if(czy_wewnatrz(punkt)){
            wewnatrz+=1;
        }else if(czy_na_brzegu(punkt)){
            brzegu+=1;
        }else{
            zewnatrz+=1;
        }
    }

    cout << wewnatrz << " " << brzegu<< " " << zewnatrz;

    return 0;
}
