#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool czy_szachuje(std::string bierki, char w, char k)
{
    int wCount = std::count(bierki.begin(), bierki.end(), w);
    int kCount = std::count(bierki.begin(), bierki.end(), k);
    if(wCount == 0 || kCount == 0)return false;

    int wIndex = bierki.find(w);

    if(wIndex == 0){
        if(bierki[1] == k){
            return true;
        }
    }else if(wIndex == bierki.size()-1){
        if(bierki[bierki.size()-2] == k){
            return true;
        }
    }else{
        if(bierki[wIndex-1] == k){
            return true;
        }
        if(bierki[wIndex+1] == k){
            return true;
        }
    }

    return false;
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

    int szachujeBialyCount = 0;
    int szachujeCzarnyCount = 0;

    for(auto szachownica: szachownice){
        std::string szachuje = "";
        for(int i = 0; i<8; i++){
            std::string wiersz = "";
            std::string kolumna = "";

            for(int j = 0; j<8; j++){
                wiersz+=szachownica[i][j];
                kolumna+=szachownica[j][i];
            }

            wiersz.erase(std::remove(wiersz.begin(), wiersz.end(), '.'), wiersz.end());
            kolumna.erase(std::remove(kolumna.begin(), kolumna.end(), '.'), kolumna.end());

            std::vector<std::string> wierszKolumnaCases = {wiersz, kolumna};

            std::vector<std::vector<char>> bierkiCases = { {'W', 'k'}, {'w', 'K'} };


            for(auto wierszKolumna: wierszKolumnaCases){
                for(auto bierkaCase: bierkiCases){
                    bool szachuje = czy_szachuje(wierszKolumna, bierkaCase[0], bierkaCase[1]);
                    if(szachuje){
                        bool czyBialy = std::isupper(bierkaCase[0]);

                        if(czyBialy){
                            szachujeBialyCount++;
                        }else{
                            szachujeCzarnyCount++;
                        }

                        break;
                    }
                }
            }
        }
    }

    std::cout << "1.3. " << szachujeBialyCount << " " << szachujeCzarnyCount;

    return 0;
}
