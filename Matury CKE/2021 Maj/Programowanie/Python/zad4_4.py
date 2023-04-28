import string

t = []
alfabet = list(string.ascii_uppercase)  # ABCDEFGHIJKLMNOPQRSTUVWXYZ

with open("../../DANE_2105/instrukcje.txt", "r") as plik:
    for linia in plik.readlines():
        cmd, litera = linia.strip().split(" ")
        if cmd == "DOPISZ":
            t.append(litera)
        elif cmd == "ZMIEN":
            t[-1] = litera
        elif cmd == "USUN":
            t.pop(-1)
        elif cmd == "PRZESUN":
            nast_litera = 'A' if litera == 'Z' else alfabet[alfabet.index(litera)+1]
            t[t.index(litera)] = nast_litera

print(''.join(t))
