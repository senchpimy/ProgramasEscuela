import numpy as np
from random import *
VERTICAL = 0
HORIZONTAL = 1
H = 20 + 1
W = 20 + 1
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

def generate():
        """highest-level method that implements the maze-generating algorithm
        Returns:
            np.array: returned matrix
        """
        # create empty grid
        grid = np.empty((H, W), dtype=np.int8)
        grid.fill(0)
        # fill borders
        grid[0, :] = grid[-1, :] = 1
        grid[:, 0] = grid[:, -1] = 1

        region_stack = [((1, 1), (H - 2,W - 2))]

        while region_stack:
            print(region_stack)
            printMatriz(grid)
            input()
            current_region = region_stack[-1]
            print("hola")
            print(current_region)
            region_stack = region_stack[:-1]
            min_y = current_region[0][0]
            max_y = current_region[1][0]
            min_x = current_region[0][1]
            max_x = current_region[1][1]
            height = max_y - min_y + 1
            width = max_x - min_x + 1

            if height <= 1 or width <= 1:
                continue

            if width < height:
                cut_direction = HORIZONTAL  # with 100% chance
            elif width > height:
                cut_direction = VERTICAL  # with 100% chance
            else:
                if width == 2:
                    continue
                cut_direction = randrange(2)

            # MAKE CUT
            # select cut position (can't be completely on the edge of the region)
            cut_length = (height, width)[(cut_direction + 1) % 2]
            print(cut_length)
            if cut_length < 3:
                continue
            cut_posi = randrange(1, cut_length, 2)
            # select new door position
            door_posi = randrange(0, (height, width)[cut_direction], 2)
            # add walls to correct places
            if cut_direction == 0:  # vertical
                for row in range(min_y, max_y + 1):
                    grid[row, min_x + cut_posi] = 1
                grid[min_y + door_posi, min_x + cut_posi] = 0
            else:  # horizontal
                for col in range(min_x, max_x + 1):
                    grid[min_y + cut_posi, col] = 1
                grid[min_y + cut_posi, min_x + door_posi] = 0

            # add new regions to stack
            if cut_direction == 0:  # vertical
                region_stack.append(((min_y, min_x), (max_y, min_x + cut_posi - 1)))
                region_stack.append(((min_y, min_x + cut_posi + 1), (max_y, max_x)))
            else:  # horizontal
                region_stack.append(((min_y, min_x), (min_y + cut_posi - 1, max_x)))
                region_stack.append(((min_y + cut_posi + 1, min_x), (max_y, max_x)))


        return grid


printMatriz(generate())
