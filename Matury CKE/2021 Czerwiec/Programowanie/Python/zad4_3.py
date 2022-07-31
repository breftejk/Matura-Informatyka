# dane=[i.strip() for i in open("../../DANE/przyklad.txt")]
dane=[i.strip() for i in open("../../DANE/napisy.txt")]

def czy_palindrom(tekst):
    return tekst == tekst[::-1]

for napis in dane:
    if czy_palindrom(napis + napis[0]):
        print((napis + napis[0])[25], end='')
    elif czy_palindrom(napis[len(napis)-1] + napis):
        print((napis[len(napis)-1] + napis)[25], end='')
