#!/usr/bin/python3
""" This module is a function that Integer indicating total amount
of rainwater retained.
"""


def rain(array):
    """
    This function is given a list of non-negative integers representing the
    heights of walls with unit width 1, as if viewing the cross-section of a
    relief map, calculate how many square units of water will be retained
    after it rains
    """
    if (len(array) == 0):
        return (0)
    i = 0
    total_water = 0
    first_wall = 0
    index_1 = 0
    index_2 = 0
    second_wall = 0
    while (i < len(array)):
        if (array[i] != 0):
            if (first_wall == 0):
                first_wall = array[i]
                index_1 = i
            elif (first_wall != 0 and second_wall == 0):
                second_wall = array[i]
                index_2 = i
                if (first_wall <= second_wall):
                    total_water += (first_wall * (index_2 - index_1 - 1))
                else:
                    total_water += (second_wall * (index_2 - index_1 - 1))
                first_wall = second_wall
                index_1 = index_2
                index_2 = 0
                second_wall = 0
        i += 1
    return (total_water)
