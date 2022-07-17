#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct Identyfikator {
    string seria;
    string numer;
};

vector<Identyfikator> wczytaj_dane()
{
    vector<Identyfikator> identyfikatory;
    // ifstream dane("C:/Matury-Informatyka/Matury CKE/2020 Lipiec/DANE/identyfikator_przyklad.txt");
    ifstream dane("C:/Matury-Informatyka/Matury CKE/2020 Lipiec/DANE/identyfikator.txt");

    string identyfikator;
    while(dane >> identyfikator){
        Identyfikator id;
        id.seria = identyfikator.substr(0, 3);
        id.numer = identyfikator.substr(3, 8);
        identyfikatory.push_back(id);
    }

    return identyfikatory;
}

int main()
{
    // wczytaj identyfikatory z struktur¹ Identyfikator na vector
    vector<Identyfikator> identyfikatory = wczytaj_dane();

    // rozwiazanie
    vector<Identyfikator> poprawneIdentyfikatory;

    vector<int> wagi = {7, 3, 1, NULL, 7, 3, 1, 7, 3};

    for(int i = 0; i<identyfikatory.size(); i++){
        int suma = 0;
        int j = 0;

        string fullString = identyfikatory[i].seria + identyfikatory[i].numer;

        for(int j = 0; j<fullString.size(); j++){
            if(j==3)continue;
            if(isdigit( fullString[j] )){
                suma += ((int)fullString[j]-48) * wagi[j]; // char -> liczba to (int)a-48
            }else{
                suma += ((int)fullString[j]-55) * wagi[j]; // char -> index char z tabeli to (int)a-55
            }
        }

        if(suma%10 != (int)identyfikatory[i].numer[0]-48){
            poprawneIdentyfikatory.push_back(identyfikatory[i]);
        }
    }

    ofstream wyniki("C:/Matury-Informatyka/Matury CKE/2020 Lipiec/Programowanie/C++/wyniki4_3.txt");

    for(auto identyfikator: poprawneIdentyfikatory){
        wyniki << identyfikator.seria << identyfikator.numer << endl;
    }

    wyniki.close();

    return 0;
}
