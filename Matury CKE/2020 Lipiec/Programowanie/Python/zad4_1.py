# identyfikatory=[[identyfikator[0:3],identyfikator[3:9]] for identyfikator in open('../../DANE/identyfikator_przyklad.txt').readlines()]
identyfikatory=[[identyfikator[0:3],identyfikator[3:9]] for identyfikator in open('../../DANE/identyfikator.txt').readlines()]

max_sum=0
max_identyfikatory=[]

for identyfikator in identyfikatory:
    temp_sum=0
    for num in identyfikator[1]:
        temp_sum+=int(num)

    if temp_sum == max_sum:
        max_identyfikatory.append(identyfikator)
    elif temp_sum>max_sum:
        max_identyfikatory=[]
        max_sum=temp_sum
        max_identyfikatory.append(identyfikator)

wyniki = open("./wyniki4_1.txt", "w")

for identyfikator in max_identyfikatory:
    wyniki.write(f'{identyfikator[0]}{identyfikator[1]}\n')

wyniki.close()