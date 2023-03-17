import random
filas = 30
columnas = 50
entrada_salida = int(filas/2)

def nuevaMatriz():
    matriz=[]
    for _ in range(filas):
        matriz.append([0 for _ in range(columnas)])
    matriz[entrada_salida][0]=2
    matriz[entrada_salida][columnas-1]=2
    return matriz

def drawVertical(columna,elementos,matriz):
    for i in range(elementos):
        matriz[i][columna]=1

def drawHorizontal(fila,elementos,matriz):
    for i in range(elementos):
        matriz[fila][i]=1

def printMatriz(mat):
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if mat[i][j]==1:
                print("\033[91m█\033[0m",end="") #pared
            elif mat[i][j]==0:
                print("\033[92m█\033[0m",end="") #libre
            else:
                print("█",end="")
        print()

def random2(nume):
    matriz = nuevaMatriz()
    for i in range(nume):
        while True:
            horizontal = random.randint(3,filas-2)
            veritcal = random.randint(3,columnas-2)
            if horizontal != entrada_salida and veritcal != 0:
                break
        drawHorizontal(horizontal, columnas-i, matriz)
        drawVertical(veritcal, filas-i, matriz)
    return matriz

def random1():
    matriz = []
    for _ in range(filas):
        matriz.append([(1 if random.random()>0.8 else 0) for _ in range(columnas)])
    matriz[int(filas/2)][0]=2
    matriz[int(filas/2)][columnas-1]=2
    unblock_path=random.randint(0,1)
    match unblock_path:
        case 0:
            for i in range(0,int(filas/2)):
                matriz[i][0]=0
                matriz[i][columnas-1]=0
        case 1:
            for i in range(int(filas/2)+1,filas):
                matriz[i][0]=0
                matriz[i][columnas-1]=0
    return matriz


val = 0
while True:
    matriz =  random2(2)
    printMatriz(matriz)
    input()
