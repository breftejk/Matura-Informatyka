with open("../../DANE_2105/instrukcje.txt", "r") as plik:
    caly_plik = plik.read()
    print(caly_plik.count("DOPISZ") - caly_plik.count("USUN"))
