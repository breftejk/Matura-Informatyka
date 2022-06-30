# numbers=[i.strip() for i in open('../../DANE/przyklad.txt').readlines()]
numbers=[i.strip() for i in open('../../DANE/liczby.txt').readlines()]


def is_prime(n):
    for i in range(2, n):
        if n%i==0:
            return False
    return True


primes_with_prime_reflections=[i for i in numbers if is_prime(int(i)) and is_prime(int(i[::-1]))]
print(f'4.3. {" ".join(primes_with_prime_reflections)}')
