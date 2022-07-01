#numbers=[int(l.strip()) for l in open('../../Dane_2205/przyklad.txt').readlines()]
numbers=[int(l.strip()) for l in open('../../Dane_2205/liczby.txt').readlines()]

# a) Ile jest dobrych trójek (trójki wraz z zapisaniem do pliku trojki.txt)?

goodThreeCount=0
trojki=open('./trojki.txt', 'w')

for i in numbers:
    for j in numbers:
        if j%i>0 or i==j:
            continue
        for k in numbers:
            if i==k or j==k:
                continue
            if k%j==0:
                trojki.write(f'{str(i)} {str(j)} {str(k)}\n')
                goodThreeCount+=1
trojki.close()

# a) Ile jest dobrych piątek?

goodFiveCount=0

for i in numbers:
    for j in numbers:
        if i==j:
            continue
        if j%i>0:
            continue
        for k in numbers:
            if i==k or j==k:
                continue
            if k%j>0:
                continue
            for l in numbers:
                if i==l or j==l or k==l:
                    continue
                if l%k>0:
                    continue
                for m in numbers:
                    if i==m or j==m or k==m or l==m:
                        continue
                    if m%l==0:
                        goodFiveCount+=1

print('4.3.', 'a)', goodThreeCount, 'b)', goodFiveCount)