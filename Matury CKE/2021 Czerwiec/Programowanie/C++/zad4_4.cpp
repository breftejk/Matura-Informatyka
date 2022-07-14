#include <iostream>
#include <fstream>
#include <ctype.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cout << "4.4. ";
    ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Czerwiec/DANE/napisy.txt");
    // ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Czerwiec/DANE/przyklad.txt");

    string resultText;

    string text;

    int xCount = 0;

    while(dane >> text){
        vector<int> liczbyWiersz;
        for(char a: text){
            if(isdigit(a)){
                liczbyWiersz.push_back((int)a-48);
            }
        }
        if(liczbyWiersz.size()%2!=0){
            liczbyWiersz.pop_back();
        }

        int i = 0;
        int numNow = 0;
        for(int a: liczbyWiersz){
            i++;
            if(i==1){
                numNow = a;
            }else{
                numNow = numNow*10+a;

                if(numNow >= 65 && numNow <= 90){
                    cout << char(numNow);

                    if(char(numNow) == 'X'){
                        xCount+=1;
                    }else{
                        xCount = 0;
                    }
                    if(xCount == 3){
                        return 0;
                    }
                }

                i=0;
                numNow=0;
            }
        }
    }

    return 0;
}
