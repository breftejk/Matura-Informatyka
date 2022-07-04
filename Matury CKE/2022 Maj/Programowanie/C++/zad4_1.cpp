#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::cout<<"4.1. ";

    // std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Maj/Dane_2205/przyklad.txt");
    std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Maj/Dane_2205/liczby.txt");

    std::string num;

    std::string first = "";
    int nCount = 0;

    while(dane >> num){
        if(num[0] == num[num.length()-1]){
            nCount += 1;
            if(first.size() == 0){
                first = num;
            }
        }
    }

    std::cout << nCount << " " << first;

    return 0;
}
