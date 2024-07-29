#!/usr/bin/python3
import sys


def print_solution(board):
    """Print the board in the required format"""
    solution = []
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == 1:
                solution.append([i, j])
    print(solution)


def is_safe(board, row, col, N):
    """Check if it's safe to place a queen at board[row][col]"""
    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solve_nqueens(board, col, N):
    """Use backtracking to find all solutions"""
    if col >= N:
        print_solution(board)
        return True

    res = False
    for i in range(N):
        if is_safe(board, i, col, N):
            board[i][col] = 1
            res = solve_nqueens(board, col + 1, N) or res
            board[i][col] = 0

    return res


if (len(sys.argv) != 2):
    print("Usage: nqueens N")
    exit(1)
n = sys.argv[1]
if not n.isdigit():
    print("N must be a number")
    exit(1)
n = int(n)
if n < 4:
    print("N must be at least 4")
    exit(1)
board = [[0 for _ in range(n)] for _ in range(n)]
solve_nqueens(board, 0, n)
