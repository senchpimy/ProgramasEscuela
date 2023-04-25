import random

# Define maze size
width = 20
height = 20

# Initialize the maze with walls everywhere
maze = [[1 for _ in range(width)] for _ in range(height)]

def divide_and_conquer(x1, y1, x2, y2):
    # Calculate the width and height of the current region
    w = x2 - x1
    h = y2 - y1
    if w < 2 or h < 2:
        # Base case: region is too small, so stop dividing
        return
    else:
        # Choose a random position to create a passage
        if w > h:
            # Divide horizontally
            px = random.randint(x1, x2-1)
            passage_y = random.randint(y1, y2-1)
            for i in range(x1, x2):
                if i != px:
                    maze[passage_y][i] = 0
            divide_and_conquer(x1, y1, px, y2)
            divide_and_conquer(px+1, y1, x2, y2)
        else:
            # Divide vertically
            py = random.randint(y1, y2-1)
            passage_x = random.randint(x1, x2-1)
            for i in range(y1, y2):
                if i != py:
                    maze[i][passage_x] = 0
            divide_and_conquer(x1, y1, x2, py)
            divide_and_conquer(x1, py+1, x2, y2)

# Generate the maze
divide_and_conquer(0, 0, width, height)

# Print the maze
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

printMatriz(maze)
