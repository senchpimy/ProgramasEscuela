import random

def recursive_division(m, n):
    # Crear una matriz de m x n con todas las celdas llenas de paredes (1)
    maze = [[1 for y in range(n)] for x in range(m)]

    # Llamar a la función recursiva para dividir el laberinto
    entrada_salida = int(m/2)
    divide(maze, 0, 0, m-2, n-1)
    for i in range(3):
        maze[entrada_salida][i]=0
        maze[entrada_salida][n-1-i]=0
    for i in range(m):
        maze[n-1][i]=0

    maze[entrada_salida][0]=2
    maze[entrada_salida][n-1]=2

    return maze

def divide(maze, row1, col1, row2, col2):
    # Si la matriz es demasiado pequeña, salir de la función recursiva
    if row2 - row1 < 2 or col2 - col1 < 2:
        return

    # Seleccionar una fila o columna aleatoria para dividir la matriz
    if random.random() < 0.5:
        divide_horizontally(maze, row1, col1, row2, col2)
    else:
        divide_vertically(maze, row1, col1, row2, col2)

def divide_horizontally(maze, row1, col1, row2, col2):
    # Seleccionar una fila aleatoria para hacer un agujero
    wall_row = random.randrange(row1+1, row2, 2)

    # Hacer un agujero en la pared
    for col in range(col1, col2+1):
        maze[wall_row][col] = 0

    # Llamar a la función recursiva para las dos sub-matrices creadas
    divide(maze, row1, col1, wall_row-1, col2)
    divide(maze, wall_row+1, col1, row2, col2)

def divide_vertically(maze, row1, col1, row2, col2):
    # Seleccionar una columna aleatoria para hacer un agujero
    wall_col = random.randrange(col1+1, col2, 2)

    # Hacer un agujero en la pared
    for row in range(row1, row2+1):
        maze[row][wall_col] = 0

    # Llamar a la función recursiva para las dos sub-matrices creadas
    divide(maze, row1, col1, row2, wall_col-1)
    divide(maze, row1, wall_col+1, row2, col2)


def printMatriz(mat):
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if mat[i][j]==1:
                print("\033[91m█\033[0m",end="")
            elif mat[i][j]==0:
                print("\033[92m█\033[0m",end="")
            else:
                print("█",end="")
        print("")


while True:
    matriz =  recursive_division(30,30)
    printMatriz(matriz)
    input()

