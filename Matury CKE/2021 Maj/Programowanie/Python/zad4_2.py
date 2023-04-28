import string

t = []

alfabet = list(string.ascii_uppercase)  # ABCDEFGHIJKLMNOPQRSTUVWXYZ

poprz_cmd = None
n = 1
n_max = 0
cmd_max = None

with open("../../DANE_2105/instrukcje.txt", "r") as plik:
    for linia in plik.readlines():
        cmd, litera = linia.strip().split(" ")

        if cmd == poprz_cmd:
            n += 1
        else:
            n = 1
        if n > n_max:
            n_max = n
            cmd_max = cmd

        if cmd == "DOPISZ":
            t.append(litera)
        elif cmd == "ZMIEN":
            t[-1] = litera
        elif cmd == "USUN":
            t.pop(-1)
        elif cmd == "PRZESUN":
            nast_litera = 'A' if litera == 'Z' else alfabet[alfabet.index(litera)+1]
            t[t.index(litera)] = nast_litera

        poprz_cmd = cmd

print(cmd_max, n_max)
