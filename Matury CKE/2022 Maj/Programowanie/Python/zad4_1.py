#numbers=[i.strip() for i in open('../../Dane_2205/przyklad.txt')]
numbers=[i.strip() for i in open('../../Dane_2205/liczby.txt')]
first_latest_the_same=[i for i in numbers if i[0]==i[-1]]
print(f'4.1. {len(first_latest_the_same)} {first_latest_the_same[0]}')