#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Maj/DANE_2105/instrukcje.txt");
    // ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Maj/DANE_2105/przyklad.txt");

    string odpowiedz = "";

    string instrukcja; char argument;
    while(dane >> instrukcja >> argument){
        if(instrukcja == "DOPISZ"){
            odpowiedz += argument;
        }else if(instrukcja == "USUN"){
            odpowiedz.pop_back();
        }else if(instrukcja == "ZMIEN"){
            odpowiedz.pop_back();
            odpowiedz += argument;
        }else if(instrukcja == "PRZESUN"){
            int idx = odpowiedz.find(argument);
            if(!idx && idx != 0)continue;
            int i = (int)argument;
            char a = (i==90 ? 65 : i+1);
            odpowiedz[idx] = a;
        }
    }

    cout << "4.4. " << odpowiedz;

    return 0;
}
