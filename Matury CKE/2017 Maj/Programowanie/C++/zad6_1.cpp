#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

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

int main()
{
    vector<vector<int>> dane;
    wczytaj_dane(dane);

    cout << "6.1.\n";

    int najciemniejszy = 999;
    int najjasniejszy = -1;

    for(auto a: dane){
        for(auto b: a){
            if(b > najjasniejszy){
                najjasniejszy = b;
            }
            if(b < najciemniejszy){
                najciemniejszy = b;
            }
        }
    }

    cout << najjasniejszy << " " << najciemniejszy;

    return 0;
}
