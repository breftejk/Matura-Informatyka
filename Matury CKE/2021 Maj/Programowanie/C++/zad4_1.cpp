#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Maj/DANE_2105/instrukcje.txt");
    // ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Maj/DANE_2105/przyklad.txt");

    int licznik = 0;

    string instrukcja; char argument;
    while(dane >> instrukcja >> argument){
        if(instrukcja == "DOPISZ"){
            licznik+=1;
        }else if(instrukcja == "USUN"){
            licznik-=1;
        }
    }

    cout << "4.1. " << licznik;

    return 0;
}
