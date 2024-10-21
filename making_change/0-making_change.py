#!/usr/bin/python3
"""This module is has a function that find the right number of Coins"""


def makeChange(coins, total):
    """
    Evaluating the right number of coins nessesary
    """

    liste = coins
    somme = 0
    numberOfCoins = 0
    liste.sort(reverse=True)
    for c in liste:
        while (somme + c) < total:
            somme += c
            numberOfCoins += 1
        if (somme + c) > total:
            continue
        elif (somme + c) == total:
            somme += c
            numberOfCoins += 1
            return numberOfCoins

    return (-1)
