#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // A - 17 w ASCII
    const int N = 26;
    int licznikiLiczb[N] = { 0 };

    ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Maj/DANE_2105/instrukcje.txt");
    // ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Maj/DANE_2105/przyklad.txt");

    string instrukcja; char argument;
    while(dane >> instrukcja >> argument){
        if(instrukcja == "DOPISZ"){
            licznikiLiczb[((int)argument-'0')-17] += 1;
        }
    }

    int maks = 0;
    char maksChar;

    for(int i = 17; i<N+17; i++){
        if(licznikiLiczb[i-17] > maks){
            maks = licznikiLiczb[i-17];
            maksChar = i+'0';
        }
    }

    cout << "4.3. " << maksChar << " " << maks;

    return 0;
}
