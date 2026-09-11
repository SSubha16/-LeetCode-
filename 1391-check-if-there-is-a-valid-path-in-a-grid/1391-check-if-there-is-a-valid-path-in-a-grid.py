from collections import deque
from typing import List


class Solution:

  def hasValidPath(self, grid: List[List[int]]) -> bool:
    m, n = len(grid), len(grid[0])

    # Directions: (dr, dc)
    # Up: (-1, 0), Down: (1, 0), Left: (0, -1), Right: (0, 1)
    OPPOSITE = {
        (-1, 0): (1, 0),
        (1, 0): (-1, 0),
        (0, -1): (0, 1),
        (0, 1): (0, -1),
    }

    # Allowed outgoing directions for each street type
    STREET_DIRS = {
        1: [(0, -1), (0, 1)],  # Left, Right
        2: [(-1, 0), (1, 0)],  # Up, Down
        3: [(0, -1), (1, 0)],  # Left, Down
        4: [(0, 1), (1, 0)],  # Right, Down
        5: [(0, -1), (-1, 0)],  # Left, Up
        6: [(0, 1), (-1, 0)],  # Right, Up
    }

    queue = deque([(0, 0)])
    visited = [[False] * n for _ in range(m)]
    visited[0][0] = True

    while queue:
      r, c = queue.popleft()

      if r == m - 1 and c == n - 1:
        return True

      curr_type = grid[r][c]
      for dr, dc in STREET_DIRS[curr_type]:
        nr, nc = r + dr, c + dc

        # Check grid boundaries and unvisited state
        if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc]:
          neighbor_type = grid[nr][nc]
          required_port = OPPOSITE[(dr, dc)]

          # Check if the neighboring street connects back
          if required_port in STREET_DIRS[neighbor_type]:
            visited[nr][nc] = True
            queue.append((nr, nc))

    return False