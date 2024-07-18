#!/usr/bin/python3
"""
method that determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    num_bytes = 0  # Variable to track how many bytes still expected
    for num in data:
        byte = num & 0xFF  # Ensure we only take the least significant 8 bits
        if num_bytes == 0:
            # Determine the number of bytes in the UTF-8 sequence
            if byte >> 7 == 0b0:
                num_bytes = 0  # Single byte character
            elif byte >> 5 == 0b110:
                num_bytes = 1  # Two byte character
            elif byte >> 4 == 0b1110:
                num_bytes = 2  # Three byte character
            elif byte >> 3 == 0b11110:
                num_bytes = 3  # Four byte character
            else:
                return False  # Invalid UTF-8 start byte
        else:
            # Check that the byte is a continuation byte
            if byte >> 6 != 0b10:
                return False  # Not a continuation byte
            num_bytes -= 1  # Decrement the count of expected continuation bytes
    return num_bytes == 0  # True if all expected bytes were found
