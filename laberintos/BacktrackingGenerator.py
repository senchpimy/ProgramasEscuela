import numpy as np
from random import randrange,shuffle

def find_neighbors(r, c, grid, is_wall,He,Wi):
    ns = []

    if r > 1 and grid[r - 2][c] == is_wall:
        ns.append((r - 2, c))
    if r < He - 2 and grid[r + 2][c] == is_wall:
        ns.append((r + 2, c))
    if c > 1 and grid[r][c - 2] == is_wall:
        ns.append((r, c - 2))
    if c < Wi - 2 and grid[r][c + 2] == is_wall:
        ns.append((r, c + 2))
    shuffle(ns)
    return ns 

H=20
W=20

def generate():
    # create empty grid, with walls
    grid = np.empty((H, W), dtype=np.int8)
    grid.fill(1)

    crow = randrange(1, H, 2)
    ccol = randrange(1, W, 2)
    track = [(crow, ccol)]
    grid[crow][ccol] = 0

    while track:
        (crow, ccol) = track[-1]
        neighbors = find_neighbors(crow, ccol, grid, True,H,W)

        if len(neighbors) == 0:
            track = track[:-1]
        else:
            nrow, ncol = neighbors[0]
            grid[nrow][ncol] = 0
            grid[(nrow + crow) // 2][(ncol + ccol) // 2] = 0

            track += [(nrow, ncol)]

    return grid

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

printMatriz(generate())
