#!/usr/bin/python3

""" This module aims to return a pascal triangle"""


def pascal_triangle(n):
    """
    Returns a list of lists representing Pascal's triangle of n.

    Args:
        n (int): The number of rows in Pascal's triangle.

    Returns:
        List[List[int]]: Pascal's triangle up to row n.
    """
    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        prev_row = triangle[-1]
        new_row = [1]

        for j in range(1, len(prev_row)):
            new_row.append(prev_row[j - 1] + prev_row[j])
        new_row.append(1)
        triangle.append(new_row)

    return triangle
