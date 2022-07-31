# dane=[i.strip() for i in open("../../DANE/przyklad.txt")]
dane=[i.strip() for i in open("../../DANE/napisy.txt")]

licznik=0
for napis in dane:
    for znak in napis:
        if znak.isdigit():
            licznik+=1

print(licznik)