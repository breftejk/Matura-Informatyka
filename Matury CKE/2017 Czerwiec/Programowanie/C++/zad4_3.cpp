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

int odleglosc_miedzy_punktami(Punkt a, Punkt b){
    return abs( sqrt( (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) ) );
}

int main()
{
    vector<Punkt> punkty;
    wczytaj_dane(punkty);

    cout << "4.3.\n";

    int max_odleglosc = 0;
    Punkt max_a, max_b;

    for(auto a: punkty){
        for(auto b: punkty){
            if(odleglosc_miedzy_punktami(a, b) > max_odleglosc){
                max_odleglosc = odleglosc_miedzy_punktami(a, b);
                max_a = a;
                max_b = b;
            }
        }
    }

    cout << "(" << max_a.x << "," << max_a.y << ")" << " i " << "(" << max_b.x << "," << max_b.y << ") " << max_odleglosc;

    return 0;
}
