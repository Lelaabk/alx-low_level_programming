#!/usr/bin/python3
"""
This module contains function that returns perimeter of island
described in grid.
"""


def island_perimeter(grid):
    """
    Calculate primeter of island in given grid.
    Args:
        grid: representing island.
    Returns:
        int: perimeter of island.
    """
    margin = 0

    for a in range(len(grid)):
        for b in range(len(grid[a])):
            if grid[a][b] == 1:
                if a == 0 or grid[a - 1][b] == 0:
                    margin += 1
                if a == len(grid) - 1 or grid[a + 1][b] == 0:
                    margin += 1
                if b == 0 or grid[a][b - 1] == 0:
                    margin += 1
                if b == len(grid[a]) - 1 or grid[a][b + 1] == 0:
                    margin += 1

    return (margin)
