#identyfikatory=[[identyfikator[0:3],identyfikator[3:9]] for identyfikator in open('../../DANE/identyfikator_przyklad.txt').readlines()]
identyfikatory=[[identyfikator[0:3],identyfikator[3:9]] for identyfikator in open('../../DANE/identyfikator.txt').readlines()]

def czy_palindrom(tekst):
    return tekst == tekst[::-1]

niepoprawne=[]

wagi=[7, 3, 1, None, 7, 3, 1, 7, 3]

for identyfikator in identyfikatory:
    full = identyfikator[0] + identyfikator[1]
    sum=0

    for i in range(len(full)):
        if i == 3: continue
        a=full[i]
        if a.isnumeric():
            sum += int(a)*wagi[i]
        else:
            sum += (ord(a)-55)*wagi[i]

    if sum%10 != int(full[3]):
        niepoprawne.append(full)

wyniki = open("./wyniki4_3.txt", "w")
for n in niepoprawne:
    wyniki.write(n+'\n')
wyniki.close()