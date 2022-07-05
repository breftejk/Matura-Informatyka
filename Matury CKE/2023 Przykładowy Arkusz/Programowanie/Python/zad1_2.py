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

bierki = ['k', 'w', 's', 'h', 'g', 'p']

count_plansz=0
min_bierek=1000

for plansza in plansze:
    bierki_w_planszy=[]

    for i in range(len(plansza)):
        for j in range(len(plansza)):
            if plansza[i][j] != '.':
                bierki_w_planszy.append(plansza[i][j])

    czy_tyle_samo=True
    for bierka in bierki:
        if bierki_w_planszy.count(bierka) != bierki_w_planszy.count(bierka.upper()):
            czy_tyle_samo=False
            break

    if czy_tyle_samo:
        count_plansz+=1
        min_bierek=min(len(bierki_w_planszy), min_bierek)

print(f'1.2. {count_plansz} {min_bierek}')