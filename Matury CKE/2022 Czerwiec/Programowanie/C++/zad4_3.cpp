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

bool isFirst(int num)
{
    for (int i = 2; i <= sqrt(num); i++) {
      if (num % i == 0) {
        return false;
      }
    }
    return true;
}

int main()
{
    std::cout << "4.3. " << std::endl;

    // std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Czerwiec/DANE/przyklad.txt");
    std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Czerwiec/DANE/liczby.txt");

    std::vector<std::string> numsList;
    std::vector<int> areBothFirstList;

    std::string num;
    while(dane >> num){
        numsList.push_back(num);
        int numNow = std::stoi(num);
        int refNum = reflection(num);

        if(isFirst(numNow) && isFirst(refNum))
        {
            std::cout << numNow << std::endl;
        }
    }

    return 0;
}
