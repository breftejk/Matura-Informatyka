#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::ifstream dane("C:/Matury-Informatyka/Informatory/Formula 2023/DANE/dane2_4.txt");
    std::ofstream odpowiedzi("C:/Matury-Informatyka/Informatory/Formula 2023/Programowanie/C++/zadanie2_4.txt");

    std::vector<std::string> nawiasyKwadratowe;

    std::string tempString;
    while(dane >> tempString){
        nawiasyKwadratowe.push_back(tempString);
    }

    for(auto nawias: nawiasyKwadratowe){
        bool czyPoprawny;

        int lCount = std::count(nawias.begin(), nawias.end(), '[');
        int pCount = std::count(nawias.begin(), nawias.end(), ']');

        czyPoprawny = lCount == pCount;

        odpowiedzi << (czyPoprawny == true ? "tak" : "nie") << std::endl;
    }
    odpowiedzi.close();

    std::cout << "Zapisano odpowiedzi w pliku.";

    return 0;
}
