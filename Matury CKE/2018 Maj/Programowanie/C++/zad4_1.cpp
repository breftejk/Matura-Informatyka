#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void wczytaj_dane(vector<string> &dane)
{
    // ifstream fdane("C:/Matury-Informatyka/Matury CKE/2018 Maj/DANE/przyklad.txt");
    ifstream fdane("C:/Matury-Informatyka/Matury CKE/2018 Maj/DANE/sygnaly.txt");
    string tekst;
    while(fdane >> tekst){
        dane.push_back(tekst);
    }
}

int main()
{
    vector<string> slowa;
    wczytaj_dane(slowa);

    cout << "4.1.\n";

    for(int i = 40; i<=slowa.size(); i+=40){
        cout << slowa[i-1][9];
    }

    return 0;
}
