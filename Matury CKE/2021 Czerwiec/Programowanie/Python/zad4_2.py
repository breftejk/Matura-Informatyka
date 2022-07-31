# dane=[i.strip() for i in open("../../DANE/przyklad.txt")]
dane=[i.strip() for i in open("../../DANE/napisy.txt")]

napis=""
for i in range(50):
    napis += dane[i*20+20-1][i]
print(napis)