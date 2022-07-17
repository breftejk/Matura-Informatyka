#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

typedef pair<int,int> coords;
typedef vector<coords> VectorCords;

struct Galeria {
    string kraj;
    string miasto;
    VectorCords koordynaty;
};

int main()
{
    // ifstream dane("C:/Matury-Informatyka/Arkusze probne/CKE Marzec 2021/Dane_2103/galerie_przyklad.txt");
    ifstream dane("C:/Matury-Informatyka/Arkusze probne/CKE Marzec 2021/Dane_2103/galerie.txt");

    vector<Galeria> galerie;

    // temp
    string row;

    while(getline(dane, row)){
        string kraj, miasto;
        VectorCords koordynaty;

        stringstream rowSS;
        rowSS << row;
        rowSS >> kraj >> miasto;

        for(int i = 0; i<70; i++){
            int num1, num2;
            rowSS >> num1 >> num2;
            if(num1 != 0){
                coords xy = {num1, num2};
                koordynaty.push_back(xy);
            }
        }

        Galeria galeria;
        galeria.miasto = miasto;
        galeria.kraj = kraj;
        galeria.koordynaty = koordynaty;

        galerie.push_back(galeria);
    }


    //4_2 a
    ofstream output42a("C:/Matury-Informatyka/Arkusze probne/CKE Marzec 2021/Programowanie/C++/wynik4_2a.txt");

    map<string, pair<int, int>> miastaPowierzchnieLokale;

    for(int i = 0; i<galerie.size(); i++){
        Galeria galeria_teraz = galerie[i];

        int sumaPowierzchni = 0;
        for(int i=0; i<galeria_teraz.koordynaty.size(); i++){
            sumaPowierzchni += galeria_teraz.koordynaty[i].first * galeria_teraz.koordynaty[i].second;
        }

        miastaPowierzchnieLokale[galeria_teraz.miasto] = { sumaPowierzchni, galeria_teraz.koordynaty.size() };
    }

    //4_2 b
    ofstream output42b("C:/Matury-Informatyka/Arkusze probne/CKE Marzec 2021/Programowanie/C++/wynik4_2b.txt");

    string maxCityName;
    int maxCity;
    string minCityName;
    int minCity;

    for(auto a: miastaPowierzchnieLokale){
        output42a << a.first << " " << a.second.first << " " << a.second.second << endl;

        if(!maxCity){
            maxCity = a.second.first;
            maxCityName = a.first;
        }
        if(!minCity){
            minCity = a.second.first;
            minCityName = a.first;
        }

        if(a.second.first > maxCity){
            maxCity = a.second.first;
            maxCityName = a.first;
        }

        if(a.second.first < minCity){
            minCity = a.second.first;
            minCityName = a.first;
        }
    }

    output42b << maxCityName << " " << maxCity << endl;
    output42b << minCityName << " " << minCity << endl;

    output42a.close();
    output42b.close();

    return 0;
}
