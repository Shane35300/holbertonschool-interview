#!/usr/bin/python3
import sys
import signal


def signal_handler(sig, frame):
    """Gère l'interruption clavier (CTRL + C) et imprime les statistiques."""
    print_stats()
    sys.exit(0)


def print_stats():
    print("File size: " + str(total_file_size))
    sorted_dico_keys = sorted(dico.keys())
    for key in sorted_dico_keys:
        print(key + ":", str(dico[key]))


# Enregistre la fonction de gestion pour le signal SIGINT (CTRL + C)
signal.signal(signal.SIGINT, signal_handler)

total_lines = 0
total_file_size = 0
dico = {}
for line in sys.stdin:
    line_list = line.strip().split()
    if len(line_list) == 9:
        total_lines += 1
        total_file_size += int(line_list[8])
        if line_list[7] in dico:
            ex_value = dico[line_list[7]]
            dico[line_list[7]] = ex_value + 1
        else:
            dico[line_list[7]] = 1
        if total_lines % 10 == 0:
            print_stats()
