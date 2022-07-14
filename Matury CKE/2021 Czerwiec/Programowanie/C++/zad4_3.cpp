#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool czy_palindrom (string text)
{
    bool palindrom = true;
    for(int i = 0; i < text.size()-1; i++){
        if(text[i] != text[text.size()-1-i]){
            palindrom = false;
            break;
        }
    }
    return palindrom;
}

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

    // Sprawdz, czy slowo jest palindromem (uwzglednij 2 przypadki)

    string answerString = "";

    for(auto word: words){
        // 1st case
        if(czy_palindrom(word+word[0])){
            string newString = word+word[0];
            answerString += newString[newString.size()/2];
            continue;
        }

        //2nd case
        if(czy_palindrom(word[word.size()-1]+word)){
            string newString = word[word.size()-1]+word;
            answerString += newString[newString.size()/2];
            continue;
        }
    }

    cout << "4.3. " << answerString;
    return 0;
}
