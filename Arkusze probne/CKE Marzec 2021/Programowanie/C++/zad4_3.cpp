#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

typedef pair<int, int> coords;
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

        vector<int> coordsUsed;

        for(int i = 0; i<70; i++){
            int num1, num2;
            rowSS >> num1 >> num2;
            if(num1 != 0){
                int powierzchnia = num1 * num2;
                if(find(coordsUsed.begin(), coordsUsed.end(), powierzchnia) == coordsUsed.end()){
                    coords xy = {num1, num2};
                    koordynaty.push_back(xy);

                    coordsUsed.push_back(powierzchnia);
                }
            }
        }

        Galeria galeria;
        galeria.miasto = miasto;
        galeria.kraj = kraj;
        galeria.koordynaty = koordynaty;

        galerie.push_back(galeria);
    }

    ofstream wynik43("C:/Matury-Informatyka/Arkusze probne/CKE Marzec 2021/Programowanie/C++/wynik4_3.txt");

    map<string, pair<int, int>> miastaPowierzchnieLokale;

    int maxMiasto = 0;
    int minMiasto = 9999999;
    string maxMiastoS, minMiastoS;

    for(int i = 0; i<galerie.size(); i++){
        Galeria galeria_teraz = galerie[i];

        if(galeria_teraz.koordynaty.size() > maxMiasto){
            maxMiasto = galeria_teraz.koordynaty.size();
            maxMiastoS = galeria_teraz.miasto;
        }

        if(galeria_teraz.koordynaty.size() < minMiasto){
            minMiasto = galeria_teraz.koordynaty.size();
            minMiastoS = galeria_teraz.miasto;
        }
    }

    wynik43 << maxMiastoS << " " << maxMiasto << endl;
    wynik43 << minMiastoS << " " << minMiasto;
    wynik43.close();

    return 0;
}
