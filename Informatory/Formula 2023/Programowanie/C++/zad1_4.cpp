#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::ifstream dane("C:/Matury-Informatyka/Informatory/Formula 2023/DANE/dane1_4.txt");

    std::vector<long> liczby;

    long liczbaTemp;
    while(dane >> liczbaTemp){
        liczby.push_back(liczbaTemp);
    }

    long maxSuma;
    long maxPoczatek;
    long maxKoniec;

    long tempSuma;
    long tempPoczatek;

    maxSuma = tempSuma = liczby[0];
    maxPoczatek = maxKoniec = tempPoczatek = 0;

    for(long i = 1; i < liczby.size(); i++) {
        if(tempSuma >= 0){
            tempSuma += liczby[i];
        }else{
            tempPoczatek = i;
            tempSuma = liczby[i];
        }

        if(tempSuma > maxSuma){
            maxSuma = tempSuma;
            maxPoczatek = tempPoczatek;
            maxKoniec = i;
        }
    }

    std::cout << maxPoczatek+1 << " " << maxKoniec+1; // Indeks od 1

    return 0;
}
