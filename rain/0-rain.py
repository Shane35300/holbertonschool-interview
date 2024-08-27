def rain(walls):
    """
    Given a list of non-negative integers representing the heights of walls with unit width 1,
    calculate how many square units of water will be retained after it rains.
    """
    if not walls:
        return 0

    left, right = 0, len(walls) - 1
    left_max, right_max = walls[left], walls[right]
    total_water = 0

    while left < right:
        if walls[left] < walls[right]:
            left += 1
            left_max = max(left_max, walls[left])
            total_water += left_max - walls[left]
        else:
            right -= 1
            right_max = max(right_max, walls[right])
            total_water += right_max - walls[right]

    return total_water
