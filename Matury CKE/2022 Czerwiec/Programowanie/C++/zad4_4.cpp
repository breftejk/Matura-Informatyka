#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::cout << "4.4. ";

    // std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Czerwiec/DANE/przyklad.txt");
    std::ifstream dane("C:/Matury-Informatyka/Matury CKE/2022 Czerwiec/DANE/liczby.txt");

    std::vector<std::string> numsList;

    std::string num;
    while(dane >> num){
        numsList.push_back(num);
    }

    std::vector<std::string> diffNums;
    std::vector<std::string> twoTimes;
    std::vector<std::string> threeTimes;

    for(auto a: numsList){
        int timesIn = count(numsList.begin(), numsList.end(), a);

        bool foundInAll = find(diffNums.begin(), diffNums.end(), a) != diffNums.end();
        if(!foundInAll){
            diffNums.push_back(a);
        }

        switch (timesIn) {
            case 2:
                {
                    bool foundInTwo = find(twoTimes.begin(), twoTimes.end(), a) != twoTimes.end();
                    if(!foundInTwo){
                        twoTimes.push_back(a);
                    }
                }
                break;
            case 3:
                {
                    bool foundInThree = find(threeTimes.begin(), threeTimes.end(), a) != threeTimes.end();
                    if(!foundInThree){
                        threeTimes.push_back(a);
                    }
                }
                break;
            default:
                break;
        }
    }

    std::cout<<diffNums.size() << " " << twoTimes.size() << " " << threeTimes.size();

    return 0;
}
