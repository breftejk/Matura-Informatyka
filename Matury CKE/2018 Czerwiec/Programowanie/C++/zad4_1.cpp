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

int main()
{
    vector<vector<int>> dane1, dane2;
    wczytaj_dane(dane1, dane2);

    int const N = 10; // 10 liczb

    int licznik = 0;

    for(int i = 0; i<dane1.size(); i++){
        if(dane1[i][N-1] == dane2[i][N-1])licznik+=1;
    }

    ofstream fwynik("C:/Matury-Informatyka/Matury CKE/2018 Czerwiec/Programowanie/C++/wynik4_1.txt");
    fwynik << licznik;
    fwynik.close();

    return 0;
}
