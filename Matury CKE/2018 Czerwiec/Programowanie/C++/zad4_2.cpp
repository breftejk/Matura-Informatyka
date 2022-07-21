#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void wczytaj_dane(vector<vector<int>> &dane1, vector<vector<int>> &dane2)
{
    // ifstream f1("C:/Matury-Informatyka/Matury CKE/2018 Czerwiec/DANE/przyklad1.txt");
    ifstream f1("C:/Matury-Informatyka/Matury CKE/2018 Czerwiec/DANE/dane1.txt");
    while(!f1.eof())
    {
        string text;
        stringstream textStream;
        getline(f1, text);
        textStream << text;

        int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
        while(textStream >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9 >> n10){
            dane1.insert(dane1.end(), vector<int>{ n1, n2, n3, n4, n5, n6, n7, n8, n9, n10 });
        }
    }
    f1.close();

    // ifstream f2("C:/Matury-Informatyka/Matury CKE/2018 Czerwiec/DANE/przyklad2.txt");
    ifstream f2("C:/Matury-Informatyka/Matury CKE/2018 Czerwiec/DANE/dane2.txt");
    while(!f2.eof())
    {
        string text;
        stringstream textStream;
        getline(f2, text);
        textStream << text;

        int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
        while(textStream >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9 >> n10){
            dane2.insert(dane2.end(), vector<int>{ n1, n2, n3, n4, n5, n6, n7, n8, n9, n10 });
        }
    }
    f2.close();
}

pair<int,int> policz(vector<int> ciag)
{
    int nieparzyste = 0;
    int parzyste = 0;
    for(auto a: ciag){
        if(a%2 == 0) parzyste += 1;
        else nieparzyste += 1;
    }
    return pair<int,int> { parzyste, nieparzyste };
}

int main()
{
    vector<vector<int>> dane1, dane2;
    wczytaj_dane(dane1, dane2);

    int const N = 10; // 10 liczb

    int licznik = 0;

    for(int i = 0; i<dane1.size(); i++){
        pair<int,int> licznik1 = policz(dane1[i]);
        pair<int,int> licznik2 = policz(dane2[i]);
        if(licznik1.first == 5 && licznik1.second == 5 && licznik2.first == 5 && licznik2.second == 5)licznik += 1;
    }

    ofstream fwynik("C:/Matury-Informatyka/Matury CKE/2018 Czerwiec/Programowanie/C++/wynik4_2.txt");
    fwynik << licznik;
    fwynik.close();

    return 0;
}
