import random
import time


def bubbleSort(arr,comp):
    n = len(arr)
    bal=0
    for i in range(n-1):
        bandera = True
        bal=i
        for j in range(0, n-1):
            if arr[j] > arr[j + 1]:
                bandera = False
                comp=comp+1
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
 
        if bandera:
            #print(f"Se hicieron {comp} comparaciones")
            return comp,bal

def test():
    start=time.time()
    lista = [random.randint(0,10_000) for _ in range(10_000)]
    end=time.time()
    crear=end-start
    print(f"Tomo {end-start} segundos para crear la lista")
    
    comp=0
    start=time.time()
    comp,bal=bubbleSort(lista,comp)
    end=time.time()
    ordenar = end-start
    print(f"Tomo {end-start} segundos para ordenar la lista")
    print(f"Se hicieron {comp} comparaciones")
    print(lista[:100])
    return crear,ordenar,comp,bal

l_crear=0 
l_ordenar=0 
l_comp=0 
l_bal=0

for i in range(5):
    c,o,co,b=test()
    l_crear+=c
    l_ordenar+=o
    l_comp+=co
    l_bal+=b

print(f"Tiempo promedio en crear {l_crear/5}")
print(f"Tiempo promedio en ordenar {l_ordenar/5}")
print(f"Comparaciones Promedio: {l_comp/5}")
print(f"Estuvo lista en el momento promedio {l_bal/5}")
