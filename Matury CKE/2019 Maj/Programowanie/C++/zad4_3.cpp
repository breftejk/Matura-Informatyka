#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void wczytaj_dane(vector<int> &liczby)
{
    // ifstream dane("C:/Matury-Informatyka/Matury CKE/2019 Maj/DANE/przyklad.txt");
    ifstream dane("C:/Matury-Informatyka/Matury CKE/2019 Maj/DANE/liczby.txt");
    int temp_liczba;
    while(dane >> temp_liczba){
        liczby.push_back(temp_liczba);
    }
}

vector<int> dzielniki(int liczba)
{
    vector<int> dzielniki_result;

    for(int i = 2; i<=liczba/2; i++){
        if(liczba%i == 0){
            dzielniki_result.push_back(i);
        }
    }

    dzielniki_result.push_back(liczba);

    return dzielniki_result;
}

vector<int> wspolne(vector<int> lista1, vector<int> lista2)
{
    vector<int> wspolne_result;

    for(auto a: lista1){
        if(find(lista2.begin(), lista2.end(), a) != lista2.end()){
            wspolne_result.push_back(a);
        }
    }

    return wspolne_result;
}

int main()
{
    vector<int> liczby;
    wczytaj_dane(liczby);

    int maxSize = 0;
    int maxStart;
    int tempSize = 0;
    int tempStart;
    vector<int> tempDzielnikiLista, maxDzielnikiLista;

    for(int i = 0; i<liczby.size(); i++){
        if(i == 0){
            tempSize = 1;
            tempStart= liczby[i];
            tempDzielnikiLista = dzielniki(liczby[i]);
        }else{
            vector<int> dzielniki_liczby = dzielniki(liczby[i]);
            vector<int> dzielniki_wspolne_z_poprzednimi = wspolne(dzielniki_liczby, tempDzielnikiLista);
            if(dzielniki_wspolne_z_poprzednimi.size() > 0){
                tempSize += 1;
                tempDzielnikiLista = dzielniki_wspolne_z_poprzednimi;

                if(tempSize > maxSize){
                    maxSize = tempSize;
                    maxStart = tempStart;
                    maxDzielnikiLista = tempDzielnikiLista;
                }
            }else{
                tempSize = 2;
                tempStart = liczby[i-1];
                tempDzielnikiLista = wspolne( dzielniki(liczby[i]), dzielniki(liczby[i-1]) );
            }
        }
    }

    int maxDzielnik = 0;
    for(int a: maxDzielnikiLista){
        if(a > maxDzielnik)maxDzielnik = a;
    }

    cout << "4.3.\n" << maxStart << " " << maxSize << " " << maxDzielnik;

    return 0;
}
