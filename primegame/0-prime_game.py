#!/usr/bin/python3
"""
Determine the winner of the prime game.
"""


def isWinner(x, nums):
    """
    Maria and Ben take turns choosing a prime number from a set of consecutive
    integers starting from 1 up to and including n. The player
    removes that number and all its multiples from the set.
    The player who cannot make a move loses.
    """
    if not nums or x < 1:
        return None

    max_n = max(nums)
    is_prime = [True] * (max_n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(max_n**0.5) + 1):
        if is_prime[i]:
            for multiple in range(i * i, max_n + 1, i):
                is_prime[multiple] = False

    primes_count = [0] * (max_n + 1)
    for i in range(1, max_n + 1):
        primes_count[i] = primes_count[i - 1] + (1 if is_prime[i] else 0)

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if primes_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
