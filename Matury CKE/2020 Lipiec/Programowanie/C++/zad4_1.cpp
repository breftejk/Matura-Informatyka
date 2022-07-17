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

int main()
{
    // wczytaj identyfikatory z struktur¹ Identyfikator na vector
    vector<Identyfikator> identyfikatory = wczytaj_dane();

    // rozwi¹zanie
    int maxSuma = 0;
    vector<Identyfikator> maxIdentyfikatory;

    for(auto identyfikator: identyfikatory){
        int tempSuma = 0;
        int tempNumer = identyfikator.numer;
        while(tempNumer != 0){
            tempSuma += tempNumer%10;
            tempNumer /= 10;
        }

        if(tempSuma == maxSuma){
            maxSuma = tempSuma;
            maxIdentyfikatory.push_back(identyfikator);
        }else if(tempSuma > maxSuma){
            maxSuma = tempSuma;
            maxIdentyfikatory.clear();
            maxIdentyfikatory.push_back(identyfikator);
        }
    }

    ofstream wyniki("C:/Matury-Informatyka/Matury CKE/2020 Lipiec/Programowanie/C++/wyniki4_1.txt");

    for(auto identyfikator: maxIdentyfikatory){
        wyniki << identyfikator.seria << identyfikator.numer << endl;
    }

    wyniki.close();

    return 0;
}
