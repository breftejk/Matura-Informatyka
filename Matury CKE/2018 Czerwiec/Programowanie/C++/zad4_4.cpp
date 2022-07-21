#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

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

int main()
{
    vector<vector<int>> dane1, dane2;
    wczytaj_dane(dane1, dane2);

    int const N = 10; // 10 liczb

    ofstream fwynik("C:/Matury-Informatyka/Matury CKE/2018 Czerwiec/Programowanie/C++/wynik4_4.txt");

    for(int i = 0; i<dane1.size(); i++){
        vector<int> liczby1 = dane1[i];
        sort(liczby1.begin(), liczby1.end());
        vector<int> liczby2 = dane2[i];
        sort(liczby2.begin(), liczby2.end());
        vector<int> scalone;

        while(liczby1.size() > 0 && liczby2.size() > 0){
            if(liczby1[0] <= liczby2[0]){
                scalone.push_back(liczby1[0]);
                liczby1.erase(liczby1.begin());
            }else{
                scalone.push_back(liczby2[0]);
                liczby2.erase(liczby2.begin());
            }
        }

        if(liczby1.size()>0){
            scalone.insert(scalone.end(), liczby1.begin(), liczby1.end());
        }else if(liczby2.size()>0){
            scalone.insert(scalone.end(), liczby2.begin(), liczby2.end());
        }

        for(auto a: scalone){
            fwynik << a << " ";
        }
        fwynik << endl;
    }

    fwynik.close();

    return 0;
}
