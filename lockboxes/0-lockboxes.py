#!/usr/bin/python3
"""
This module determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and each box may
    contain keys to the other boxes
    """

    n = len(boxes)
    unlocked = [False] * n
    unlocked[0] = True  # Start with the first box being unlocked
    keys = [0]  # Start with the key to the first box

    while keys:
        current_key = keys.pop()
        for key in boxes[current_key]:
            if key < n and not unlocked[key]:
                unlocked[key] = True
                keys.append(key)

    return all(unlocked)
