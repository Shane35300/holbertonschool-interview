#!/usr/bin/python3
"""
This module's goal is to calculate the right permieter"""


def island_perimeter(grid):
    """
    This function calculate a perimeter by making loop into the gris
    """

    total = 0
    i = 0
    for i in range(len(grid)):
        j = 0
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                per = 0
                if grid[i - 1][j] != 1:
                    per += 1
                if grid[i + 1][j] != 1:
                    per += 1
                if grid[i][j - 1] != 1:
                    per += 1
                if grid[i][j + 1] != 1:
                    per += 1
                total += per
    return (total)
