#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void wczytaj_dane(vector<string> &dane)
{
    // ifstream fdane("C:/Matury-Informatyka/Matury CKE/2018 Maj/DANE/przyklad.txt");
    ifstream fdane("C:/Matury-Informatyka/Matury CKE/2018 Maj/DANE/sygnaly.txt");
    string tekst;
    while(fdane >> tekst){
        dane.push_back(tekst);
    }
}

int unikalne(string tekst){
    int licznik = 0;
    vector<char> uzyte;

    for(char a: tekst){
        if(find(uzyte.begin(), uzyte.end(), a) == uzyte.end()){
            licznik += 1;
            uzyte.push_back(a);
        }
    }

    return licznik;
}

int main()
{
    vector<string> slowa;
    wczytaj_dane(slowa);

    cout << "4.2.\n";

    int maxLicznik = 0;
    string maxSlowo;

    for(auto a: slowa){
        int licznik = unikalne(a);
        if(licznik > maxLicznik){
            maxLicznik = licznik;
            maxSlowo = a;
        }
    }

    cout << maxSlowo << " " << maxLicznik;

    return 0;
}
