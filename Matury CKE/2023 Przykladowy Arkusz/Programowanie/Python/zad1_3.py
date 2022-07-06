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

szach_bialy=0
szach_czarny=0

def czy_szachuje(k, w, string):
    bialy = w.isupper()
    k_idx = string.index(k)
    if k_idx>0 and k_idx<len(string)-1:
        if string[k_idx-1] or string[k_idx+1] == w:
            return [True, bialy]
    elif k_idx == 0:
        if string[k_idx+1]==w:
            return [True, bialy]
    elif k_idx == len(string) - 1:
        if string[k_idx-1]==w:
            return [True, bialy]
    return [False, bialy]


for plansza in plansze:
    for i in range(len(plansza)):
        ten_wiersz=''
        ta_kolumna=''
        for j in range(len(plansza)):
            ten_wiersz+=plansza[i][j]
            ta_kolumna+=plansza[j][i]
        ten_wiersz=ten_wiersz.replace('.','')
        ta_kolumna=ta_kolumna.replace('.','')

        teksty=[ten_wiersz, ta_kolumna]
        bierki_cases=[['k', 'W'], ['K', 'w']]

        for tekst in teksty:
            for bierki in bierki_cases:
                if bierki[0] in tekst and bierki[1] in tekst:
                    szachuje = czy_szachuje(bierki[0], bierki[1], tekst)
                    if(szachuje[0]):
                        if(szachuje[1]):
                            szach_bialy+=1
                        else:
                            szach_czarny+=1

print(f'1.3. {szach_bialy} {szach_czarny}')