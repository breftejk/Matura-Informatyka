import math
# numbers=[i.strip() for i in open('../../DANE/przyklad.txt').readlines()]
numbers=[i.strip() for i in open('../../DANE/liczby.txt').readlines()]

max_diff=0
max_num=0
for i in numbers:
    reflection=int(i[::-1])
    num_diff=int(i)-reflection
    if math.fabs(num_diff)>max_diff:
        max_diff=int(math.fabs(num_diff))
        max_num=i

print(f'4.2. {max_num} {max_diff}')