#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int const N = 200; // liczba wierszy

struct Point;
vector<vector<Point>> dane;

bool czy_kontrastuja(int a, int b)
{
    return (abs(a-b) > 128);
}

struct Point {
    int i, j, value;

    // i-1 j
    bool k1() {
        if(i == 0)return false;
        return czy_kontrastuja(value, dane[i-1][j].value);
    }

    // i+1 j
    bool k2() {
        if( i == N-1 )return false;
        return czy_kontrastuja(value, dane[i+1][j].value);
    }

    // i j-1
    bool k3() {
        if(j == 0)return false;
        return czy_kontrastuja(value, dane[i][j-1].value);
    }

    // i j+1
    bool k4() {
        if( j == 320-1 )return false;
        return czy_kontrastuja(value, dane[i][j+1].value);
    }
};

void wczytaj_dane(vector<vector<Point>> &liczby)
{
    // ifstream dane("C:/Matury-Informatyka/Matury CKE/2017 Maj/DANE/przyklad.txt");
    ifstream dane("C:/Matury-Informatyka/Matury CKE/2017 Maj/DANE/dane.txt");

    int i = 0;
    while(!dane.eof()){
        string liczby_str;
        getline(dane, liczby_str);
        stringstream liczby_ss;
        liczby_ss << liczby_str;

        vector<Point> liczbyV;
        int liczba;
        int j = 0;
        while(liczby_ss >> liczba){
            Point point;
            point.i = i;
            point.j = j;
            point.value = liczba;

            liczbyV.push_back(point);
            j++;
        }

        liczby.push_back(liczbyV);
        i++;
    }
}

int main()
{
    wczytaj_dane(dane);
    cout.sync_with_stdio(false);

    cout << "6.3.\n";

    int licznik = 0;

    for(auto a: dane){
        for(auto b: a){
            if(b.k1() || b.k2() || b.k3() || b.k4()) licznik += 1;
        }
    }

    cout << licznik;

    return 0;
}
