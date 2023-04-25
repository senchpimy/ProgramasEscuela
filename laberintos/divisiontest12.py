import random
matrix = [[0 for _ in range(20)] for _ in range(20)]

def printMatriz(mat):
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if mat[i][j]==1:
                print("\033[91m█\033[0m",end="") #pared
            elif mat[i][j]==0:
                print("\033[92m█\033[0m",end="") #libre
            elif mat[i][j]==3:
                print("\033[94m█\033[0m",end="") #libre
            else:
                print("█",end="")

        print()

def dividir(x1,y1,x2,y2):
    anchura=x2-x1
    y2=max(y2,y1)
    y1=min(y1,y2)
    altura=y2-y1
    if altura<=2 or anchura<=2:return
    #Horizontal true, vwritcal false
    #direccion=random.randint(0,1)
    if True:
        linea=random.randint(x1,x2)
        for i in range(y1,y2+1):
            matrix[linea][i]=1
        matrix[linea][random.randint(x1,x2)]=0 #Puerta

        dividir(x1+1, y1, x2 - (linea), y2)
        dividir(x1 + linea + 2, y1, x2, y2)
    else:
        linea=random.randint(y1,y2)
        #while matrix[0 or 19][linea]==1:
        #    linea=random.randint(y1,y2)
        for i in range(y1,y2):
            #try:
                matrix[i][linea]=1
            #except:
            #    print(i,",",linea)
        val=random.randint(x1,x2)
        matrix[val][linea]=0 #Puerta
        dividir(x1, y1, x2, y2 - linea + 1)
        dividir(x1, y1 + linea, x2, y2 - 2)
        #dividir(x1,y1,x2,y2-linea+1)
        #dividir(x1,y1+linea,x2,y2-2)

while True:
    matrix = [[0 for _ in range(20)] for _ in range(20)]
    dividir(0,0,19,19)
    printMatriz(matrix)
    input()

