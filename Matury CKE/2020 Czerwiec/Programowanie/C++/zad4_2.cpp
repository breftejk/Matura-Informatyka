#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

pair<string,int> najwiekszy_podciag(string tekst)
{
    int maxCount = 0;
    char maxZnak;
    int tempCount = 0;
    char tempZnak;

    for(int i = 0; i<tekst.size(); i++){
        if(tempZnak == tekst[i]){
            tempCount += 1;
        }else{
            tempZnak = tekst[i];
            tempCount = 1;
        }

        if(tempCount > maxCount){
            maxCount = tempCount;
            maxZnak = tempZnak;
        }
    }

    string w = "";

    for(int i = 0; i<maxCount; i++){
        w+=maxZnak;
    }

    pair<string,int> wynik = { w, maxCount };

    return wynik;
}

vector<pair<int,string>> wczytaj_dane()
{
    vector<pair<int,string>> dane;

    // ifstream f("C:/Matury-Informatyka/Matury CKE/2020 Czerwiec/DANE/przyklad.txt");
    ifstream f("C:/Matury-Informatyka/Matury CKE/2020 Czerwiec/DANE/pary.txt");
    int num; string str;
    while(f >> num >> str){
        dane.push_back(pair<int,string> {num, str});
    }

    return dane;
}

int main()
{
    vector<pair<int,string>> dane = wczytaj_dane();

    for(auto p: dane){
        string tekst = p.second;
        pair<string,int> np = najwiekszy_podciag(tekst);
        cout << np.first << " " << np.second << endl;
    }

    return 0;
}
