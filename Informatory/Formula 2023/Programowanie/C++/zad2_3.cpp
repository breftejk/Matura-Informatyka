#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::ifstream dane("C:/Matury-Informatyka/Informatory/Formula 2023/DANE/dane2_3.txt");
    std::ofstream odpowiedzi("C:/Matury-Informatyka/Informatory/Formula 2023/Programowanie/C++/zadanie2_3.txt");

    std::vector<std::string> nawiasyKwadratowe;

    std::string tempString;
    while(dane >> tempString){
        nawiasyKwadratowe.push_back(tempString);
    }

    for(auto nawias: nawiasyKwadratowe){
        int glebokosc = 0;
        int glebokoscTemp = 0;
        for(auto nawiasTemp: nawias){
            if(nawiasTemp == '['){
                glebokoscTemp += 1;
                if(glebokoscTemp > glebokosc){
                    glebokosc = glebokoscTemp;
                }
            }else if(nawiasTemp == ']'){
                glebokoscTemp -= 1;
            }
        }
        odpowiedzi << glebokosc << std::endl;
    }
    odpowiedzi.close();

    std::cout << "Zapisano odpowiedzi w pliku.";

    return 0;
}
