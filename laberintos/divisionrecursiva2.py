import random

def recursive_division(m, n):
    # Creamos una matriz de m x n, inicializada con todas las celdas como paredes (1).
    maze = [[1] * n for i in range(m)]

    # Creamos las paredes externas del laberinto.
    for i in range(m):
        maze[i][0] = maze[i][n - 1] = 1
    for j in range(n):
        maze[0][j] = maze[m - 1][j] = 1

    # Llamamos a la función de recursión para dividir el laberinto.
    divide(maze, 1, 1, m - 2, n - 2, choose_orientation(m, n))

    # Retornamos el laberinto generado.
    return maze

def divide(maze, row_start, col_start, row_end, col_end, orientation):
    if row_end < row_start or col_end < col_start:
        return

    if orientation == 0:
        # Si la orientación es horizontal, dividimos la sección en dos partes.
        divide_horizontally(maze, row_start, col_start, row_end, col_end)
        wall_row = choose_odd_number(row_start + 1, row_end - 1)
        maze[wall_row][choose_even_number(col_start, col_end)] = 0
        divide(maze, row_start, col_start, wall_row - 1, col_end, choose_orientation(wall_row - row_start + 1, col_end - col_start + 1))
        divide(maze, wall_row + 1, col_start, row_end, col_end, choose_orientation(row_end - wall_row + 1, col_end - col_start + 1))
    else:
        # Si la orientación es vertical, dividimos la sección en dos partes.
        divide_vertically(maze, row_start, col_start, row_end, col_end)
        wall_col = choose_odd_number(col_start + 1, col_end - 1)
        maze[choose_even_number(row_start, row_end)][wall_col] = 0
        divide(maze, row_start, col_start, row_end, wall_col - 1, choose_orientation(row_end - row_start + 1, wall_col - col_start + 1))
        divide(maze, row_start, wall_col + 1, row_end, col_end, choose_orientation(row_end - row_start + 1, col_end - wall_col + 1))

def divide_horizontally(maze, row_start, col_start, row_end, col_end):
    wall_row = choose_even_number(row_start + 1, row_end - 1)
    for j in range(col_start, col_end + 1):
        maze[wall_row][j] = 1

def divide_vertically(maze, row_start, col_start, row_end, col_end):
    wall_col = choose_even_number(col_start + 1, col_end - 1)
    for i in range(row_start, row_end + 1):
        maze[i][wall_col] = 1

def choose_orientation(height, width):
    if height < width:
        return 0
    elif width < height:
        return 1
    else:
        return random.randint(0, 1)

def choose_even_number(start, end):
    if start == end:
        return start
    return random.randrange(start // 2, (end // 2) + 1) * 2
def choose_odd_number(start, end):
    if start == end:
        return start
    return random.randrange((start // 2) + 1, (end // 2) + 1) * 2 - 1


#def choose_even_number(start, end):
#    #return random.randrange(start // 2, end // end // 2) * 2
#    return random.randrange(start // 2, (end // 2) + 1) * 2
#
#
#def choose_odd_number(start, end):
#    return random.randrange(start // 2, end // 2 + 1) * 2 + 1


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

