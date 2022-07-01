def decomposeToFactors(number):
    factors=[]
    k=2
    while number!=1:
        while number%k==0:
            number//=k
            factors.append(k)
        k+=1
    return factors


def countDifferent(list):
    diffList=[]
    for i in list:
        if i not in diffList:
            diffList.append(i)
    return len(diffList)


#numbers=[l.strip() for l in open('../../Dane_2205/przyklad.txt').readlines()]
numbers=[l.strip() for l in open('../../Dane_2205/liczby.txt').readlines()]
dataFactors=[decomposeToFactors(int(i)) for i in numbers]

max_index=0
max_count=0

max_diff_index=0
max_diff_count=0

for i in range(len(dataFactors)):
    # Najwięcej, mogą być takie same
    if len(dataFactors[i]) > max_count:
        max_index=i
        max_count=len(dataFactors[i])

    # Najwięcej, muszą być różne
    if countDifferent(dataFactors[i]) > max_diff_count:
        max_diff_index=i
        max_diff_count=countDifferent(dataFactors[i])

print('4.2.', numbers[max_index], max_count, numbers[max_diff_index], max_diff_count)