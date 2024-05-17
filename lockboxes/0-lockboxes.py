#!/usr/bin/python3
def canUnlockAll(boxes):
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
