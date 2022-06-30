# numbers=[i.strip() for i in open('../../DANE/przyklad.txt').readlines()]
numbers=[i.strip() for i in open('../../DANE/liczby.txt').readlines()]

checked=[]
count=[]

for i in range(len(numbers)):
    if numbers[i] not in checked:
        count.append([ numbers[i], numbers.count(numbers[i]) ])
        checked.append(numbers[i])

total_diff=len(count)
total_double=len([i for i in count if i[1]==2])
total_tripple=len([i for i in count if i[1]==3])

print(f'4.4. {total_diff} {total_double} {total_tripple}')