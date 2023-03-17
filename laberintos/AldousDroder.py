import numpy as np
from random import *
def _find_neighbors(r, c, grid, is_wall=False):
    """Find all the grid neighbors of the current position; visited, or not.
    Args:
        r (int): row of cell of interest
        c (int): column of cell of interest
        grid (np.array): 2D maze grid
        is_wall (bool): Are we looking for neighbors that are walls, or open cells?
    Returns:
        list: all neighboring cells that match our request
    """
    ns = []

    if r > 1 and grid[r - 2][c] == is_wall:
        ns.append((r - 2, c))
    if r < H - 2 and grid[r + 2][c] == is_wall:
        ns.append((r + 2, c))
    if c > 1 and grid[r][c - 2] == is_wall:
        ns.append((r, c - 2))
    if c < W - 2 and grid[r][c + 2] == is_wall:
        ns.append((r, c + 2))


    shuffle(ns)
    return ns 

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

h = 10
w = 40
H = (2 * h) + 1
W = (2 * w) + 1
grid = np.empty((H, W), dtype=np.int8)
grid.fill(1)
crow = randrange(1, H, 2)
print(crow)
ccol = randrange(1, W, 2)
grid[crow][ccol] = 0
num_visited = 1

print(grid)
tmp = grid[crow][ccol]
grid[crow][ccol]=2
printMatriz(grid)
grid[crow][ccol]=tmp


while num_visited < h * w:
    # find neighbors
    neighbors = _find_neighbors(crow, ccol, grid, True)
    print("vecinos",neighbors)
    print("random:",crow,ccol)

    # how many neighbors have already been visited?
    if len(neighbors) == 0:
        # mark random neighbor as current
        (crow, ccol) = choice(_find_neighbors(crow, ccol, grid))
        continue

    # loop through neighbors
    for nrow, ncol in neighbors:
        if grid[nrow][ncol] > 0:
            # open up wall to new neighbor
            grid[(nrow + crow) // 2][(ncol + ccol) // 2] = 0
            # mark neighbor as visited
            grid[nrow][ncol] = 0
            # bump the number visited
            num_visited += 1
            # current becomes new neighbor
            crow = nrow
            ccol = ncol
            # break loop
            break
    lol=[]
    for fila,col in neighbors:
        lol.append((fila,col,grid[fila][col]))
        grid[fila][col]=3
    tmp = grid[crow][ccol]
    grid[crow][ccol]=2
    printMatriz(grid)
    grid[crow][ccol]=tmp
    input()
    for fila,col,val in lol:
        grid[fila][col]=val

print("Listo")
