#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Czerwiec/DANE/napisy.txt");
    // ifstream dane("C:/Matury-Informatyka/Matury CKE/2021 Czerwiec/DANE/przyklad.txt");

    // Wczytaj dane na vector words

    vector<string> words;

    string text;
    while(dane >> text){
        words.push_back(text);
    }

    // Stworz tekst

    string answer_text = "";

    for(int i = 1; i < words.size()/20+1;i++){
        answer_text += words[i*20-1][i-1];
    }

    cout << "4.2. " << answer_text;

    return 0;
}
