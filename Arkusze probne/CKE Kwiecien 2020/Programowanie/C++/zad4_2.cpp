#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> wczytaj_dane()
{
    vector<int> dane;

    ifstream file("C:/Matury-Informatyka/Arkusze probne/CKE Kwiecien 2020/DANE/dane4.txt");
    int liczba;
    while(file >> liczba){
        dane.push_back(liczba);
    }

    return dane;
}

int main()
{
    vector<int> liczby = wczytaj_dane();

    int maxRoznica;
    int maxMinIndex;
    int maxMaxIndex;
    int maxCount;

    int tempRoznica = NULL;
    int tempMinIndex;
    int tempMaxIndex;
    int tempCount = 0;

    for(int i = 0; i<liczby.size(); i++){
        int roznica = abs(liczby[i+1] - liczby[i]);

        if(tempRoznica == NULL){
            tempRoznica = roznica;
            tempMinIndex = i;
            tempMaxIndex = i+1;
            tempCount = 2;
            continue;
        }

        if(roznica == tempRoznica){
            tempMaxIndex = i+1;
            tempCount+=1;

            if(tempCount > maxCount){
                maxCount = tempCount;
                maxRoznica = tempRoznica;
                maxMinIndex = tempMinIndex;
                maxMaxIndex = tempMaxIndex;
            }
        }else{
            tempRoznica = roznica;
            tempMinIndex = i;
            tempMaxIndex = i+1;
            tempCount = 2;
        }
    }

    cout << "4.2.\nNajwieksza dlugosc fragmentu regularnego: " << maxCount << "\nPierwsza liczba: " << liczby[maxMinIndex] << "\nOstatnia liczba: " << liczby[maxMaxIndex];

    return 0;
}
