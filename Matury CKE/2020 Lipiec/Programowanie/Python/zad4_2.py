# identyfikatory=[[identyfikator[0:3],identyfikator[3:9]] for identyfikator in open('../../DANE/identyfikator_przyklad.txt').readlines()]
identyfikatory=[[identyfikator[0:3],identyfikator[3:9]] for identyfikator in open('../../DANE/identyfikator.txt').readlines()]


def czy_palindrom(tekst):
    return tekst == tekst[::-1]

wyniki = open("./wyniki4_2.txt", "w")

for identyfikator in identyfikatory:
    if czy_palindrom(identyfikator[0]) or czy_palindrom(identyfikator[1]):
        wyniki.write(identyfikator[0] + identyfikator[1] + '\n')

wyniki.close()