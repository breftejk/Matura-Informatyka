#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 100000;

void wczytaj_dane(vector<int> &liczby)
{
    // ifstream dane("C:/Matury-Informatyka/Matury CKE/2019 Maj/DANE/przyklad.txt");
    ifstream dane("C:/Matury-Informatyka/Matury CKE/2019 Maj/DANE/liczby.txt");
    int temp_liczba;
    while(dane >> temp_liczba){
        liczby.push_back(temp_liczba);
    }
}

vector<int> gen_potegi_3()
{
    vector<int> potegi = {1};

    int teraz = 3;
    while(teraz <= N){
        potegi.push_back(teraz);
        teraz = teraz * 3;
    }

    return potegi;
}

bool czy_potega_3(vector<int> potegi_3, int liczba)
{
    return find(potegi_3.begin(), potegi_3.end(), liczba) != potegi_3.end();
}

int main()
{
    vector<int> liczby;
    wczytaj_dane(liczby);

    vector<int> potegi_3 = gen_potegi_3();

    int licznik = 0;

    for(auto a: liczby){
        if(czy_potega_3(potegi_3, a)){
            licznik += 1;
        }
    }

    cout << "4.1.\n" << licznik;

    return 0;
}
