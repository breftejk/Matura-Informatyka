#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::ifstream dane("C:/Matury-Informatyka/Informatory/Formula 2023/DANE/dane1_3.txt");

    std::vector<int> liczby;

    int liczbaTemp;
    while(dane >> liczbaTemp){
        liczby.push_back(liczbaTemp);
    }

    int maxSuma = 0;

    for(int i = 0; i<liczby.size()-1; i++){
        int tempSuma = 0;
        for(int j = i; j<liczby.size()-1-i; j++){
            tempSuma += liczby[j];
            if(tempSuma > maxSuma){
                maxSuma = tempSuma;
            }
        }
    }

    std::cout << maxSuma;

    return 0;
}
