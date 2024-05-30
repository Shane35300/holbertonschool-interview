#!/usr/bin/python3
import math

def minOperations(n):
    """ method that calculates the fewest number of operations needed
    to result in exactly n H characters in the file
    """

    if n <= 1:
        return 0
    else:
        i = 2
        copy = 1
        paste = 1
        nb_of_caracter = 1
        while(i <= n):
            if i == n:
                return copy + paste
            if n % i == 0:
                copy += 1
                paste += 1
                nb_of_caracter = i
                i = i + nb_of_caracter
                continue
            else:
                paste += 1
                i += nb_of_caracter
        return 0



