# numbers=[i.strip() for i in open('../../DANE/przyklad.txt').readlines()]
numbers=[i.strip() for i in open('../../DANE/liczby.txt').readlines()]
reflections=[int(i[::-1]) for i in numbers]
reflections_divisible_by_17=[str(i) for i in reflections if i%17==0]

print(f'4.1. {" ".join(reflections_divisible_by_17)}')
