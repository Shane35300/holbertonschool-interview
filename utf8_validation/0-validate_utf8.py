#!/usr/bin/python3
"""
method that determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """method that determines if a given data set represents
    a valid UTF-8 encoding
    """
    for val in data:
        if val > 255 or val < 0:
            return False
    return True
