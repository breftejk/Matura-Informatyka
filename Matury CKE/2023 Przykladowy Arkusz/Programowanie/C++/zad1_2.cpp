#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool czyRownowaga(std::vector<char> bierki){
    std::vector<char> bierki_list = {'k', 'w', 's', 'h', 'g', 'p'};

    for(char bierka: bierki_list){
        int bierka_count=count(bierki.begin(),bierki.end(),bierka);
        int bierka_upper_count=count(bierki.begin(),bierki.end(),toupper(bierka));
        if(bierka_count != bierka_upper_count)return false;
    }

    return true;
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

    int min_bierki, total_rownowaga;

    for(auto szachownica: szachownice){
        std::vector<char> bierki_szachownica;

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                char bierka = szachownica[i][j];
                if(bierka != '.') {
                    bierki_szachownica.push_back(bierka);
                }
            }
        }

        if(czyRownowaga(bierki_szachownica)){
            total_rownowaga += 1;
            if(bierki_szachownica.size() < min_bierki){
                min_bierki = bierki_szachownica.size();
            }
        }
    }

    std::cout << "1.2. " << total_rownowaga << " " << min_bierki;

    return 0;
}
