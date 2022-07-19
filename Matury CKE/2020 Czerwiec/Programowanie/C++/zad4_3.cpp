#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,string>> wczytaj_dane()
{
    vector<pair<int,string>> dane;

    // ifstream f("C:/Matury-Informatyka/Matury CKE/2020 Czerwiec/DANE/przyklad.txt");
    ifstream f("C:/Matury-Informatyka/Matury CKE/2020 Czerwiec/DANE/pary.txt");
    int num; string str;
    while(f >> num >> str){
        dane.push_back(pair<int,string> {num, str});
    }

    return dane;
}

bool czy_mniejsza(pair<int,string> ta, pair<int,string> od)
{
    if(-ta.first < od.first)return true;

    vector<char> first, second;

    for(auto a: ta.second){ first.push_back(a); }

    for(auto a: od.second){ second.push_back(a); }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    string first_str, second_str = "";

    for(auto a: first){ first_str+=a; }
    for(auto a: second){ second_str+=a; }

    if((-ta.first == od.first) && (first_str < second_str))return true;

    return false;
}

int main()
{
    vector<pair<int,string>> dane = wczytaj_dane();

    pair<int,string> najmniejsza = {NULL, ""};

    for(auto p: dane){
        int liczba = p.first;
        string tekst = p.second;

        if(tekst.size() != liczba)continue;

        if(najmniejsza.first == NULL){
            najmniejsza = p;
            continue;
        }

        if(czy_mniejsza(p, najmniejsza)){
            najmniejsza = p;
        }
    }


    cout << najmniejsza.first << " " << najmniejsza.second;

    return 0;
}
