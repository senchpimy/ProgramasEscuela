import random
import sys

filas = 30
columnas = 30
entrada_salida = int(filas/2)

def nuevaMatriz():
    matriz=[]
    for _ in range(filas):
        matriz.append([1 for _ in range(columnas)])
    matriz[entrada_salida][0]=2
    matriz[entrada_salida][columnas-1]=2
    return matriz

def draw_line(matrix, x1, y1, x2, y2):
    dx = abs(x2 - x1)
    dy = abs(y2 - y1)
    sx = 1 if x1 < x2 else -1
    sy = 1 if y1 < y2 else -1
    err = dx - dy

    while x1 != x2 or y1 != y2:
        matrix[x1][y1] = 0
        try:
            matrix[x1][y1+1] = 0
        except:
            matrix[x1][y1-1] = 0
        e2 = 2 * err
        if e2 > -dy:
            err -= dy
            x1 += sx
        if e2 < dx:
            err += dx
            y1 += sy

    matrix[x1][y1] = 0


#def draw_line(matrix, x1, y1, x2, y2):
#    if x1 == x2:
#        for j in range(min(y1, y2), max(y1, y2)+1):
#            matrix[x1][j] = 0
#    else:
#        diflarge = (max(x1,x2)-min(x1,x2))+1
#        difheight = (max(y1,y2)-min(y1,y2))+1
#        num_to_paint = diflarge//difheight
#        for i in range(min(x1, x2), max(x1, x2)+1):
#            for k in range(min(y1,y2),max(y1,y2)):
#                matrix[i][k]=0

def propio(num,mat):
    prev_fila = entrada_salida
    prev_col= 0
    for _ in range(num):
        fila=random.randint(1,filas-1)
        columna=random.randint(1,columnas-1)
        draw_line(mat,prev_fila,prev_col,fila,columna)
        mat[fila][columna]=2
        prev_fila=fila
        prev_col=columna


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

while True:
    mat = nuevaMatriz()
    propio(8,mat)
    printMatriz(mat)
