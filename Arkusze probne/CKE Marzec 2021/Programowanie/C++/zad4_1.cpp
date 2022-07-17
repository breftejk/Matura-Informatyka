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

    ofstream wynik41("C:/Matury-Informatyka/Arkusze probne/CKE Marzec 2021/Programowanie/C++/wynik4_1.txt");

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

    map<string, int> krajeZGaleriami;

    for(int i = 0; i<galerie.size(); i++){
        Galeria galeria_teraz = galerie[i];

        if(krajeZGaleriami[galeria_teraz.kraj] || krajeZGaleriami[galeria_teraz.kraj]==0){
            int count_now = krajeZGaleriami[galeria_teraz.kraj];
            krajeZGaleriami[galeria_teraz.kraj] = count_now+1;
        }else{
            krajeZGaleriami[galeria_teraz.kraj] = 0;
        }
    }

    for(auto a: krajeZGaleriami){
        wynik41 << a.first << " " << a.second << endl;
    }

    wynik41.close();

    return 0;
}
