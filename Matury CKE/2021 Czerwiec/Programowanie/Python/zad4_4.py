# dane=[i.strip() for i in open("../../DANE/przyklad.txt")]
dane=[i.strip() for i in open("../../DANE/napisy.txt")]

w_napis=""

for napis in dane:
    finished=False
    digits=[]
    cache_digit=None
    for char in napis:
        if char.isdigit():
            if cache_digit==None:
                cache_digit=char
            else:
                digits.append(int(cache_digit+char))
                cache_digit=None
    for suma in digits:
        if suma > 90 or suma < 65: continue
        w_napis += chr(suma)
        if len(w_napis) > 3:
            if w_napis[-1] == 'X' and w_napis[-2] == 'X' and w_napis[-3] == 'X':
                finished = True
                break
    if finished == True:
        break
print(w_napis)