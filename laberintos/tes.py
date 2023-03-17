import numpy as np
import matplotlib.pyplot as plt

# Create a 10x10 matrix
matrix = np.zeros((10, 10))

# Define the two points
point1 = (7, 3)
point2 = (3, 8)

# Draw the line on the matrix
if point1[0] == point2[0]:
    # Same column
    matrix[min(point1[1], point2[1]):max(point1[1], point2[1])+1, point1[0]] = 1
elif point1[1] == point2[1]:
    # Same row
    matrix[point1[1], min(point1[0], point2[0]):max(point1[0], point2[0])+1] = 1
else:
    # Sloped line
    slope = (point2[1] - point1[1]) / (point2[0] - point1[0])
    intercept = point1[1] - slope * point1[0]
    for x in range(10):
        y = slope * x + intercept
        if 0 <= y < 10:
            matrix[int(y), x] = 1

# Show the matrix with the line

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

matrix[0][:4]=1
printMatriz(matrix)
