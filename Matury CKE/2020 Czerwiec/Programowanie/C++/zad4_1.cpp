#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int const N = 100;

bool czy_pierwsza(int liczba){
    for(int i = 2; i<=sqrt(liczba); i++){
        if(liczba%i == 0)return false;
    }
    return true;
}

vector<int> liczby_pierwsze()
{
    vector<int> pierwsze;
    for(int i = 3; i<=N; i++){
        if(czy_pierwsza(i)){
            pierwsze.push_back(i);
        }
    }
    return pierwsze;
}

vector<pair<int,string>> wczytaj_dane()
{
    vector<pair<int,string>> dane;

    // ifstream f("C:/Matury-Informatyka/Matury CKE/2020 Czerwiec/DANE/przyklad.txt");
    ifstream f("C:/Matury-Informatyka/Matury CKE/2020 Czerwiec/DANE/pary.txt");
    int num; string str;
    while(f >> num >> str){
        dane.push_back(pair<int,string> {num, str});
    }

    return dane;
}

int main()
{
    vector<pair<int,string>> dane = wczytaj_dane();
    vector<int> pierwsze = liczby_pierwsze();

    vector<int> liczby_odp;

    for(auto p: dane){
        int liczba = p.first;
        if(liczba>4 && liczba%2==0){
            for(int i = 0; i<pierwsze.size(); i++){
                bool found = false;
                for(int j = pierwsze.size()-1; j>=0; j--){
                    if(pierwsze[i] + pierwsze[j] == liczba){
                        cout << liczba << " " << pierwsze[i] << " " << pierwsze[j] << endl;
                        found = true;
                        break;
                    }
                }
                if(found)break;
            }
        }
    }

    return 0;
}
