#!/usr/bin/python3
"""This module is has a function that find the right number of Coins"""


def makeChange(coins, total):
    """
    Function to find the fewest number of coins needed to meet the total
    """
    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for i in range(1, total + 1):
        for coin in coins:
            if i - coin >= 0:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1