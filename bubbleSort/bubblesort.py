import random
import time


def bubbleSort(arr,comp):
    n = len(arr)
    for i in range(n-1):
        bandera = True
        for j in range(0, n-1):
            if arr[j] > arr[j + 1]:
                bandera = False
                comp=comp+1
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
 
        if bandera:
            print(f"Se hicieron {comp} comparaciones")
            return comp

start=time.time()
lista = [random.randint(0,10_000) for _ in range(10_000)]
end=time.time()

print(f"Tomo {end-start} segundos para crear la lista")

comp=0
start=time.time()
comp=bubbleSort(lista,comp)
end=time.time()
print(f"Tomo {end-start} segundos para ordenar la lista")
print(f"Se hicieron {comp} comparaciones")
print(lista[:100])
