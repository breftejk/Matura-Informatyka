#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

std::vector<int> toFactors(int n)
{
    std::vector<int> factors;
    int g, i;
    g = sqrt(n);

    for (i = 2; i <= g; i++) {
        while(n % i == 0){
            factors.push_back(i);
            n /= i;
        }
        if(n == 1){
            return factors;
        }
    }

    factors.push_back(n);
    return factors;
}

int main()
{
    std::cout<<"4.2. ";

    // std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Maj/Dane_2205/przyklad.txt");
    std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Maj/Dane_2205/liczby.txt");


    int num, uniqueMax, uniqueNumber, allMax, allNumber = 0;
    while(dane >> num){
        std::vector<int> factors = toFactors(num);
        std::vector<int> uniqueFactors;

        int uniqueCount = 0;

        for(auto a: factors){
            bool uniqueAlready = std::find(uniqueFactors.begin(), uniqueFactors.end(), a) != uniqueFactors.end();
            if(!uniqueAlready){
                uniqueFactors.push_back(a);
                uniqueCount += 1;
            }
        }

        int countAll = factors.size();

        if(countAll > allMax){
            allMax = countAll;
            allNumber = num;
        }

        if(uniqueCount > uniqueMax){
            uniqueMax = uniqueCount;
            uniqueNumber = num;
        }
    }


    std::cout << allNumber << " " << allMax << " " << uniqueNumber << " " << uniqueMax;

    return 0;
}
