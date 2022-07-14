#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

int main()
{
    ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Czerwiec/DANE/napisy.txt");
    // ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Czerwiec/DANE/przyklad.txt");
    int charsDigitCount = 0;

    string text;
    while(dane >> text){
        for(auto a: text){
            if(isdigit(a)){
                charsDigitCount += 1;
            }
        }
    }

    cout << "4.1. " << charsDigitCount;
    return 0;
}
