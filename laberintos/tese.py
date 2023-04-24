import random

def random_matrix(n, rows, cols):
    # Create an empty matrix with zeros
    matrix = [[0 for j in range(cols)] for i in range(rows)]

    # Generate n random lines
    for _ in range(n):
        # Choose a random row and column to start the line
        start_row = random.randint(0, rows-1)
        start_col = random.randint(0, cols-1)

        # Choose a random direction for the line
        direction = random.choice([(1,0), (0,1), (1,1), (-1,1)])

        # Choose a random length for the line
        length = random.randint(1, min(rows-start_row, cols-start_col, start_row+1, start_col+1))

        # Mark the cells along the line as 1
        for i in range(length):
            row = start_row + i*direction[0]
            col = start_col + i*direction[1]
            matrix[row][col] = 1

    return matrix
matrix = random_matrix(5, 20, 20)
for row in matrix:
    print(row)

