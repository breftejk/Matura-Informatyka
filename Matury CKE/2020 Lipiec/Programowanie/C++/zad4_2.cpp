#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Identyfikator {
    string seria;
    int numer;
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
        id.numer = stoi(identyfikator.substr(3, 8));
        identyfikatory.push_back(id);
    }

    return identyfikatory;
}

bool czy_palindrom(string tekst)
{
    for(int i = 0; i<tekst.size(); i++)
    {
        if(tekst[i] != tekst[tekst.size()-1-i])return false;
    }
    return true;
}

int main()
{
    // wczytaj identyfikatory z struktur¹ Identyfikator na vector
    vector<Identyfikator> identyfikatory = wczytaj_dane();

    // rozwiazanie
    vector<Identyfikator> palindromIdentyfikatory;

    for(auto identyfikator: identyfikatory){
        string numerString = to_string(identyfikator.numer);
        if(czy_palindrom(identyfikator.seria) || czy_palindrom(numerString)){
            palindromIdentyfikatory.push_back(identyfikator);
        }
    }

    ofstream wyniki("C:/Matury-Informatyka/Matury CKE/2020 Lipiec/Programowanie/C++/wyniki4_2.txt");

    for(auto identyfikator: palindromIdentyfikatory){
        wyniki << identyfikator.seria << identyfikator.numer << endl;
    }

    wyniki.close();

    return 0;
}
