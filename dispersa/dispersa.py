import sys

matriz="""0 2 0 0 0 0 0 0 0 3 0 0 0
4 0 0 0 0 0 0 0 20 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 23 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 2 0"""
if len(sys.argv)>2:
    matriz=""
    for line in sys.stdin:
        matriz+=line

print(matriz)
print()
print()

columna = 0
fila=0
list_columna = []
lista_fila=[]
numero_lista=[]
numero_de_encuentros=0

max_len=0
for i in matriz.split("\n"):
    max_len=len(i)
    max_len=int((max_len/2)+0.5)
    for j in i.split(" "):
        columna+=1
        if j!="0":
            lista_fila.append(fila)
            list_columna.append(columna%max_len)
            numero_lista.append(int(j))
            print(fila, columna%max_len, f"Numero: {j}")
    fila+=1

print()
print()
print(f"{fila} {columna/fila}")
print()
print()

for i in lista_fila:
    print(i, end=" ")
print()
for i in list_columna:
    print(i, end=" ")
print()
for i in numero_lista:
    print(i, end=" ")
print()

indice_fila=0
for i in range(fila):
    print()
    for j in range(1,int(max_len)+1):
        try:
            if i==lista_fila[indice_fila] and j==list_columna[indice_fila]:
                #print(i,j%max_len)
                print(numero_lista[indice_fila],end=" ")
                indice_fila+=1
            else:
                print("0", end=" ")
        except:
            print("0", end=" ")
print()
print()
