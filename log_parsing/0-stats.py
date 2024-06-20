#!/usr/bin/python3
"""
This module reads stdin line by line and computes metrics.

It prints the following statistics after every 10 lines and upon keyboard
interruption (CTRL + C):
- Total file size
- Number of lines by status code
"""
import sys
import signal


def signal_handler(sig, frame):
    """Gère l'interruption clavier (CTRL + C) et imprime les statistiques."""
    print_stats()
    sys.exit(0)


def print_stats():
    """ This method print the statistic results
    """
    print("File size: " + str(total_file_size))
    sorted_dico_keys = sorted(dico.keys())
    for key in sorted_dico_keys:
        print(key + ":", str(dico[key]))


signal.signal(signal.SIGINT, signal_handler)

total_lines = 0
total_file_size = 0
dico = {}
try:
    for line in sys.stdin:
        line_list = line.strip().split()
        if len(line_list) == 9:
            total_lines += 1
            total_file_size += int(line_list[8])
            if line_list[7] in dico:
                dico[line_list[7]] += 1
            else:
                dico[line_list[7]] = 1
            if total_lines % 10 == 0:
                print_stats()
except Exception as e:
    print(f"Error processing line: {e}", file=sys.stderr)
finally:
    print_stats()
