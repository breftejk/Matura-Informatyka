#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool isEmpty(std::string text){
    return text == "........";
}

int main()
{
    // std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2023 Przykladowy Arkusz/Dane_2203/szachy_przyklad.txt");
    std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2023 Przykladowy Arkusz/Dane_2203/szachy.txt");

    std::vector<std::vector<std::string>> szachownice;

    std::string tempWiersz;
    std::vector<std::string> tempSzachownica;
    int s_i=0;
    while(dane >> tempWiersz){
        tempSzachownica.push_back(tempWiersz);

        s_i++;
        if(s_i==8){
            s_i=0;
            szachownice.push_back(tempSzachownica);
            tempSzachownica.clear();
        }
    }

    int puste_total=0;
    int max_total=0;

    for(auto szachownica: szachownice){
        int puste_temp = 0;
        for(int i=0;i<8;i++){
            std::string kolumna = "";

            for(int j=0;j<8;j++){
                kolumna+=szachownica[j][i];
            }

            if(isEmpty(kolumna)){
                puste_temp+=1;
            }
        }

        if(puste_temp > 0){
            puste_total += 1;
            if(puste_temp > max_total){
                max_total = puste_temp;
            }
        }
    }

    std::cout << "1.1. " << puste_total << " " << max_total;

    return 0;
}
