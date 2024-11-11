#!/usr/bin/python3
"""
This module's goal is to calculate the right permieter
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of the island described in the grid.

    Arguments:
    grid -- a list of list of integers where 0 represents water and 1
    represents land.

    Returns:
    An integer representing the perimeter of the island.
    """
    total_perimeter = 0

    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                per = 4

                if i > 0 and grid[i - 1][j] == 1:
                    per -= 1

                if i < rows - 1 and grid[i + 1][j] == 1:
                    per -= 1

                if j > 0 and grid[i][j - 1] == 1:
                    per -= 1

                if j < cols - 1 and grid[i][j + 1] == 1:
                    per -= 1

                total_perimeter += per

    return total_perimeter
