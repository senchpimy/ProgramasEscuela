import random
total=0
for _ in range(0,4):
    numero_random = random.randint(10000,999999)
    print(numero_random)
    total=total+numero_random
input()
print(total)
