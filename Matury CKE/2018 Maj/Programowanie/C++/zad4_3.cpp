#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

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

int main()
{
    vector<string> slowa;
    wczytaj_dane(slowa);

    cout << "4.3.\n";

    for(auto slowo: slowa){
        bool poprawne = true;

        for(char a: slowo){
            if(poprawne == false)break;
            for(char b: slowo){
                if( abs( (int)a - (int)b ) > 10){
                    poprawne = false;
                    break;
                }
            }
        }

        if(poprawne){
            cout << slowo << endl;
        }
    }

    return 0;
}
