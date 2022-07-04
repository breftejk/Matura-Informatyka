#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

int reflection(std::string str)
{
    std::reverse(str.begin(), str.end());
    return std::stoi(str);
}

int main()
{
    std::cout << "4.2. ";

    // std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Czerwiec/DANE/przyklad.txt");
    std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Czerwiec/DANE/liczby.txt");

    std::vector<std::string> numsList;
    std::vector<int> reflectedAndDivBy17List;

    int refDifMax, numMax = 0;

    std::string num;
    while(dane >> num){
        numsList.push_back(num);
        int numNow = std::stoi(num);
        int refNum = reflection(num);

        int difNow = abs(numNow-refNum);
        if(difNow > refDifMax){
            refDifMax = difNow;
            numMax = numNow;
        }
    }

    std::cout << numMax << " " << refDifMax;

    return 0;
}
