#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

int reflection(std::string str)
{
    std::reverse(str.begin(), str.end());
    return std::stoi(str);
}

int main()
{
    std::cout << "4.1. ";

    // std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Czerwiec/DANE/przyklad.txt");
    std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Czerwiec/DANE/liczby.txt");

    std::vector<std::string> numsList;
    std::vector<int> reflectedAndDivBy17List;

    std::string num;
    while(dane >> num){
        numsList.push_back(num);
        int refNum = reflection(num);
        if(refNum % 17 == 0){
            reflectedAndDivBy17List.push_back(refNum);
            std::cout << refNum << " ";
        }
    }

    return 0;
}
