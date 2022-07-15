#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Maj/DANE_2105/instrukcje.txt");
    // ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Maj/DANE_2105/przyklad.txt");

    string aktualny = "";
    int licznik = 0;

    string maxAktualny;
    int maxLicznik = 0;

    string instrukcja; char argument;
    while(dane >> instrukcja >> argument){
        if(aktualny == "")aktualny = instrukcja;

        if(instrukcja == aktualny){
            licznik+=1;

            if(licznik > maxLicznik){
                maxLicznik = licznik;
                maxAktualny = aktualny;
            }
        }else{
            aktualny = instrukcja;
            licznik = 1;
        }
    }

    cout << "4.2. " << maxAktualny << " " << maxLicznik;

    return 0;
}
