# dane=[i.strip() for i in open('../../Dane_2203/szachy_przyklad.txt')]
dane=[i.strip() for i in open('../../Dane_2203/szachy.txt')]

i=0
plansze=[[]]
for row in dane:
    if row == '':
        i+=1
        plansze.append([])
    else:
        plansze[i].append(row)

# Cke dodało dwie nowe linie na końcu a to mogło popsuć program :o
if plansze[-1] == []:
    plansze.pop(len(plansze)-1)

puste=[]
for p in range(len(plansze)):
    plansza=plansze[p]
    puste_kolumny = 0
    for i in range(len(plansza)):
        ta_pusta=True
        for j in range(len(plansza)):
            if plansza[j][i] != '.':
                ta_pusta=False
                break
        if ta_pusta == True:
            puste_kolumny += 1
    if puste_kolumny > 0:
        puste.append(puste_kolumny)

print(f'1.1. {len(puste)} {max(puste)}')