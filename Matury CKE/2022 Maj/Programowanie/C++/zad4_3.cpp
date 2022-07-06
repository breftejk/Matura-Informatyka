#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::cout<<"4.3. ";

    // std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Maj/Dane_2205/przyklad.txt");
    std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Maj/Dane_2205/liczby.txt");

    std::ofstream trojki("trojki.txt");

    std::vector<int> numbersList;

    int number;
    while(dane >> number){
        numbersList.push_back(number);
    }

    int trojkiCount = 0;

    for(auto x: numbersList){
        for(auto y: numbersList){
            if(x==y)continue;
            if(y%x!=0)continue;
            for(auto z: numbersList){
                if(y==z)continue;
                if(z%y!=0)continue;
                trojkiCount+=1;
                trojki << x << " " << y << " " << z << std::endl;
            }
        }
    }

    std::cout << "a) " << trojkiCount << " ";

    trojki.close();

    int piatkiCount = 0;

    for(auto u: numbersList){
        for(auto w: numbersList){
            if(u==w)continue;
            if(w%u!=0)continue;
            for(auto x: numbersList){
                if(w==x || u==x)continue;
                if(x%w!=0)continue;
                for(auto y: numbersList){
                    if(x==y || w==y || u==y)continue;
                    if(y%x!=0)continue;
                    for(auto z: numbersList){
                        if(y==z || x==z || w==z || u==z)continue;
                        if(z%y!=0)continue;
                        piatkiCount += 1;
                    }
                }
            }
        }
    }

    std::cout<<"b) " << piatkiCount;

    return 0;
}
