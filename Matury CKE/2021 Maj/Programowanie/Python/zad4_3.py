import string

t = []
alfabet = list(string.ascii_uppercase)  # ABCDEFGHIJKLMNOPQRSTUVWXYZ

liczba_liter = {

}


with open("../../DANE_2105/instrukcje.txt", "r") as plik:
    for linia in plik.readlines():
        cmd, litera = linia.strip().split(" ")
        if cmd == "DOPISZ":
            if litera in liczba_liter:
                liczba_liter[litera] += 1
            else:
                liczba_liter[litera] = 1
            t.append(litera)
        elif cmd == "ZMIEN":
            t[-1] = litera
        elif cmd == "USUN":
            t.pop(-1)
        elif cmd == "PRZESUN":
            nast_litera = 'A' if litera == 'Z' else alfabet[alfabet.index(litera)+1]
            t[t.index(litera)] = nast_litera

# I sposob
print(
    max(liczba_liter.items(), key=lambda litera_cyfra: litera_cyfra[1])
)

# II sposob

litera_max = None
liczba_max = 0
for litera in liczba_liter:
    liczba = liczba_liter[litera]
    if liczba > liczba_max:
        liczba_max = liczba
        litera_max = litera

print(litera_max, liczba_max)
