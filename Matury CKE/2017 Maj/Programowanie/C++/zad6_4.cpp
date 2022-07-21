#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int const N = 200; // liczba wierszy

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

    cout << "6.4.\n";

    int maxLicznik;
    for(int i = 0; i<320; i++){
        int tempLicznik = 0;
        int tempLiczba = 999;
        for(int j = 0; j<N; j++){
            if(dane[j][i] == tempLiczba){
                tempLicznik += 1;

                if(tempLicznik > maxLicznik){
                    maxLicznik = tempLicznik;
                }
            }else{
                tempLicznik = 1;
                tempLiczba = dane[j][i];
            }
        }
    }

    cout << maxLicznik;

    return 0;
}
