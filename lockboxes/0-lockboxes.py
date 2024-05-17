#!/usr/bin/python3
"""
This module determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and each box may
    contain keys to the other boxes
    """

    i = 0
    unlocked = [0]
    while i < len(boxes):
        if i not in unlocked:
            return False
        y = 0
        while y < len(boxes[i]):
            index = boxes[i][y]
            if index not in unlocked:
                unlocked.append(index)
            for elem in boxes[index]:
                if elem not in unlocked:
                    unlocked.append(elem)
            y += 1
        i += 1
    return True
