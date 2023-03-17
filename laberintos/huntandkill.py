import random
import numpy as np
filas = 30
columnas = 50
H = (2 * filas) + 1
W = (2 * columnas) + 1
entrada_salida = int(filas/2)

def nuevaMatriz():
    grid = np.empty((H, W), dtype=np.int8)
    grid.fill(1)
    return grid

def _find_neighbors(r, c, grid, is_wall=False):
    ns = []

    if r > 1 and grid[r - 2][c] == is_wall:
        ns.append((r - 2, c))
    if r < H - 2 and grid[r + 2][c] == is_wall:
        ns.append((r + 2, c))
    if c > 1 and grid[r][c - 2] == is_wall:
        ns.append((r, c - 2))
    if c < W - 2 and grid[r][c + 2] == is_wall:
        ns.append((r, c + 2))

    random.shuffle(ns)
    return ns 

def huntAndKill():
    fila=random.randint(0,filas-1)
    columna=random.randint(0,columnas-1)
    prevf,prevcolumna = fila,columna
    matriz = nuevaMatriz()
    matriz[fila][columna]=0
    while True:
        vecinos_mat = _find_neighbors(fila,columna,matriz)
        if len(vecinos_mat)==0:
                vecinos_mat = _find_neighbors(prevf,prevcolumna,matriz)
        else:
            fila,columna = vecinos_mat[0]
            try:
                prevf,prevcolumna = vecinos_mat[1]
            except:
                break
        matriz[fila][columna]=0
    return matriz

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

printMatriz(huntAndKill())
